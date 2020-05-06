/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:54:41 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/05 22:54:28 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_parsing(t_vecteur *pos, t_window *win, t_tex *tex, char *av)
{
	int		r;

	pos->tile = 64;
	pos->pace = 8;
	pos->alpha = 0;
	win->title = "Cub3D";
	if (ft_set_window(win, tex, av) != 0)
	{
		ft_free_tex(win, tex);
		free(win->mlx_ptr);
		return (-1);
	}
	if ((r = ft_map(pos, win, av)) != 0)
	{
		if (r == -2 && pos->map != NULL)
			ft_free_map(pos, win);
		ft_free_tex(win, tex);
		free(win->mlx_ptr);
		return (-1);
	}
	return (0);
}

int		ft_taille_fond(char *line, t_window *win)
{
	if (line[0] == 'R')
	{
		if (ft_resolution(win, line) == -1)
			return (ft_err_handl(-3));
	}
	else if (line[0] == 'F')
	{
		if (ft_c_f(win, line, 'F') == -1)
			return (ft_err_handl(-4));
	}
	else if (line[0] == 'C')
	{
		if (ft_c_f(win, line, 'C') == -1)
			return (ft_err_handl(-5));
	}
	return (0);
}

int		ft_wall_tex(char *line, t_window *win, t_tex *tex)
{
	t_image	im;

	im.ptr = NULL;
	if ((line[0] == 'S' && line[1] == 'O') || (line[0] == 'W' &&
	line[1] == 'E') || (line[0] == 'E' && line[1] == 'A') ||
	(line[0] == 'N' && line[1] == 'O') ||
	(line[0] == 'S' && (line[1] == ' ' || line[1] == '/')))
	{
		if (ft_texture(line, win, &im) != 0)
			return (-1);
		if (line[0] == 'S' && line[1] == 'O')
			return (ft_attribuer_texture(tex, &im, &tex->nord, win));
		else if (line[0] == 'W' && line[1] == 'E')
			return (ft_attribuer_texture(tex, &im, &tex->est, win));
		else if (line[0] == 'E' && line[1] == 'A')
			return (ft_attribuer_texture(tex, &im, &tex->ouest, win));
		else if (line[0] == 'N' && line[1] == 'O')
			return (ft_attribuer_texture(tex, &im, &tex->sud, win));
		else if (line[0] == 'S' && (line[1] == ' ' || line[1] == '/'))
			return (ft_attribuer_texture(tex, &im, &tex->sprite, win));
	}
	return (0);
}

int		ft_set_window(t_window *win, t_tex *tex, char *av)
{
	int		fd;

	win->width = 0;
	win->hei = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (ft_err_handl(-17));
	if (ft_set_window_suite(win, tex, fd) != 0)
		return (-1);
	close(fd);
	if (ft_verif_settings(win, tex) != 0)
		return (-1);
	return (0);
}

int		ft_set_window_suite(t_window *win, t_tex *tex, int fd)
{
	char	*line;
	int		r;

	while ((r = get_next_line(fd, &line)) == 1)
	{
		if (ft_taille_fond(line, win) != 0 ||
		ft_wall_tex(line, win, tex) != 0 ||
		ft_random_line(line) != 0)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	free(line);
	if (r == -1)
		return (ft_err_handl(-11));
	return (0);
}
