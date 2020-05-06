/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:54:41 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 14:54:04 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_c_f(t_window *win, char *line, char c)
{
	int		red;
	int		green;
	int		blue;
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if ((blue = ft_recup_int(line, &i, 1)) == -1)
		return (-1);
	if ((green = ft_recup_int(line, &i, 0)) == -1)
		return (-1);
	if ((red = ft_recup_int(line, &i, 0)) == -1)
		return (-1);
	if (ft_end_line(line, &i) == -1)
		return (-1);
	if (c == 'F')
		win->floor = ft_code_couleur(red, green, blue);
	else if (c == 'C')
		win->ceiling = ft_code_couleur(red, green, blue);
	return (0);
}

int		ft_recup_int(char *line, int *i, int blue)
{
	int		nb;
	int		virg;

	virg = 0;
	while (ft_isdigit(line[*i]) == 0)
	{
		if (line[*i] == ',')
			virg++;
		if ((line[*i] != ' ' && line[*i] != ',') || virg > 1)
			return (-1);
		*i = *i + 1;
	}
	if ((virg == 0 && blue == 0) || (virg == 1 && blue == 1))
		return (-1);
	nb = 0;
	while (ft_isdigit(line[*i]))
	{
		nb = nb * 10 + line[*i] - 48;
		*i = *i + 1;
	}
	if (nb < 0 || nb > 255)
		return (-1);
	return (nb);
}

int		ft_resolution(t_window *win, char *line)
{
	int		i;

	i = 1;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0 && line[i] != ' ')
			return (-1);
		i++;
	}
	i = 1;
	while (line[i] == ' ')
		i++;
	ft_resolution_suite(win, line, &i);
	if (ft_end_line(line, &i) == -1)
		return (-1);
	return (0);
}

void	ft_resolution_suite(t_window *win, char *line, int *i)
{
	while (ft_isdigit(line[*i]))
	{
		win->width = win->width * 10 + line[*i] - 48;
		*i = *i + 1;
	}
	while (line[*i] == ' ')
		*i = *i + 1;
	while (ft_isdigit(line[*i]))
	{
		win->hei = win->hei * 10 + line[*i] - 48;
		*i = *i + 1;
	}
}

int		ft_verif_settings(t_window *win, t_tex *tex)
{
	int	sizex;
	int	sizey;

	if (win->width == 0 || win->hei == 0)
		return (ft_err_handl(-3));
	mlx_get_screen_size(win->mlx_ptr, &sizex, &sizey);
	if (win->width > sizex)
		win->width = sizex;
	if (win->hei > sizey)
		win->hei = sizey;
	if (ft_verif_couleur(win) != 0)
		return (-1);
	if (tex->nord.ptr == NULL)
		return (ft_err_handl(-6));
	else if (tex->sud.ptr == NULL)
		return (ft_err_handl(-7));
	else if (tex->est.ptr == NULL)
		return (ft_err_handl(-8));
	else if (tex->ouest.ptr == NULL)
		return (ft_err_handl(-9));
	else if (tex->sprite.ptr == NULL)
		return (ft_err_handl(-10));
	return (0);
}
