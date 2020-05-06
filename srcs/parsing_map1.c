/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:51:01 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 14:38:15 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_size_map(char *av, t_window *win, int *row_start, int *row_end)
{
	int		fd;
	int		r;
	char	*line;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (ft_err_handl(-17));
	while ((r = get_next_line(fd, &line)) == 1)
	{
		ft_size_map_gnl(line, win, row_start, row_end);
		free(line);
	}
	if (r == 0 && line[0])
		ft_size_map_gnl(line, win, row_start, row_end);
	free(line);
	close(fd);
	if (r == -1)
		return (ft_err_handl(-11));
	win->rows = *row_end - *row_start;
	return (0);
}

void	ft_size_map_gnl(char *line, t_window *win, int *row_start, int *row_end)
{
	if (line[0] != '1' && line[0] != ' ')
		*row_start = *row_start + 1;
	else if (line[0] == '1' || line[0] == ' ')
	{
		if ((int)ft_strlen(line) > win->col)
			win->col = ft_strlen(line);
	}
	*row_end = *row_end + 1;
}

int		ft_malloc_map(t_vecteur *pos, t_window *win)
{
	int		i;

	if (!(pos->map = (char **)malloc(sizeof(char **) * win->rows + 1)))
		return (ft_err_handl(-18));
	i = 0;
	while (i < win->rows)
	{
		if (!(pos->map[i] = (char *)malloc(sizeof(char *) * win->col)))
		{
			i--;
			while (i >= 0)
			{
				free(pos->map[i]);
				i--;
			}
			free(pos->map);
			return (ft_err_handl(-18));
		}
		i++;
	}
	return (0);
}

int		ft_check_map_exist(t_window *win)
{
	if (win->rows < 3 || win->col < 3)
		return (ft_err_handl(-24));
	return (0);
}

int		ft_map(t_vecteur *pos, t_window *win, char *av)
{
	int		row_start;
	int		row_end;

	row_start = 0;
	row_end = 0;
	win->col = 0;
	pos->map = NULL;
	if (ft_size_map(av, win, &row_start, &row_end) != 0)
		return (-1);
	if (ft_check_map_exist(win) != 0)
		return (-1);
	if (ft_malloc_map(pos, win) != 0)
		return (-1);
	if (ft_fill_map(av, win, row_start, pos) != 0)
		return (-2);
	if (ft_perso(pos, win) != 0)
		return (-2);
	if (ft_check_murs(pos, win, '0') != 0)
		return (-2);
	if (ft_check_murs(pos, win, '2') != 0)
		return (-2);
	return (0);
}
