/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:52:48 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 00:05:38 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_end_line(char *line, int *i)
{
	while (line[*i])
	{
		if (line[*i] != ' ')
			return (-1);
		*i = *i + 1;
	}
	return (0);
}

int		ft_random_line(char *line)
{
	int		i;

	if (line[0] == 'R' || line[0] == 'C' || line[0] == 'F' || line[0] == '1'
	|| (line[0] == 'S' && line[1] == 'O') || (line[0] == 'W' &&
	line[1] == 'E') || (line[0] == 'E' && line[1] == 'A') ||
	(line[0] == 'N' && line[1] == 'O') || (line[0] == 'S' &&
	(line[1] == ' ' || line[1] == '/')) || line[0] == 0)
		return (0);
	if (line[0] == ' ')
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == ' ')
				i++;
			if (line[i] == '1')
				return (0);
		}
	}
	return (ft_err_handl(-25));
}

int		ft_attribuer_texture(t_tex *tex, t_image *im, t_image *mur,
		t_window *win)
{
	if (mur->ptr != NULL)
	{
		mlx_destroy_image(win->mlx_ptr, im->ptr);
		return (ft_err_handl(-26));
	}
	*mur = *im;
	return (0);
}
