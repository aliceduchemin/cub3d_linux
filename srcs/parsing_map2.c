/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:51:05 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 14:37:58 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_fill_map(char *av, t_window *win, int row_start, t_vecteur *pos)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (ft_err_handl(-17));
	i = -1;
	while (i++ < row_start - 1)
	{
		if (get_next_line(fd, &line) == -1)
			return (ft_err_handl(-11));
		free(line);
	}
	i = 0;
	while (i < win->rows)
	{
		if (get_next_line(fd, &line) == -1)
			return (ft_err_handl(-11));
		ft_cpy(pos->map[i], line, win->col + 1);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

int		ft_perso(t_vecteur *pos, t_window *win)
{
	int		i;
	int		j;
	int		perso;

	perso = 0;
	i = 0;
	while (i < win->rows)
	{
		j = 0;
		while (j < win->col)
		{
			if (pos->map[i][j] == 'E' || pos->map[i][j] == 'S' ||
				pos->map[i][j] == 'N' || pos->map[i][j] == 'W')
			{
				perso++;
				if (ft_zero_entoure(pos, win, i, j))
					return (ft_err_handl(-22));
			}
			j++;
		}
		i++;
	}
	return (ft_err_perso(perso));
}

int		ft_zero_entoure(t_vecteur *pos, t_window *win, int i, int j)
{
	if (i == 0 || i == (win->rows - 1) || j == 0 || j == (win->col - 1))
		return (-1);
	else if (pos->map[i - 1][j] == ' ')
		return (-1);
	else if (pos->map[i + 1][j] == ' ')
		return (-1);
	else if (pos->map[i][j - 1] == ' ')
		return (-1);
	else if (pos->map[i][j + 1] == ' ')
		return (-1);
	return (0);
}

int		ft_check_murs(t_vecteur *pos, t_window *win, char check)
{
	int		i;
	int		j;

	i = 0;
	while (i < win->rows)
	{
		j = 0;
		while (j < win->col)
		{
			if (pos->map[i][j] == check)
			{
				if (ft_zero_entoure(pos, win, i, j))
				{
					if (check == '0')
						return (ft_err_handl(-21));
					else
						return (ft_err_handl(-27));
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_cpy(char *dst, char *line, int columns)
{
	int		i;

	i = 0;
	while (i < (columns - 1) && line[i])
	{
		dst[i] = line[i];
		i++;
	}
	while (i < (columns - 1))
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = 0;
}
