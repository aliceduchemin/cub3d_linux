/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteurs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:09:01 by aduchemi          #+#    #+#             */
/*   Updated: 2020/04/29 18:32:21 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_raycast_horiz(t_vecteur *pos, t_vecteur *ray, t_window *win)
{
	ft_set_horiz_xa_ya(ray, pos);
	if (ray->x > 0 && ray->y > 0 && ray->x < (pos->tile * win->col) &&
			ray->y < (pos->tile * win->rows))
	{
		if (ft_horiz(pos, ray, win) == 1)
			return (1);
	}
	while (ray->x > 0 && ray->y > 0 && ray->x < (pos->tile * win->col) &&
			ray->y < (pos->tile * win->rows))
	{
		ray->x += ray->xa;
		ray->y += ray->ya;
		if (ft_horiz(pos, ray, win) == 1)
			return (1);
	}
	return (0);
}

void	ft_set_horiz_xa_ya(t_vecteur *ray, t_vecteur *pos)
{
	float d_y;

	d_y = (float)((int)(pos->y * 100) % (pos->tile * 100)) / 100;
	ray->ya = pos->indicey * pos->tile;
	if (pos->indicey == -1)
		ray->y = pos->y - d_y;
	else
		ray->y = pos->y + pos->tile - d_y;
	if ((pos->indicey == -1 && pos->indicex == 1) ||
			(pos->indicey == 1 && pos->indicex == -1))
	{
		ray->xa = pos->indicex * pos->tile * tan(pos->col);
		ray->x = pos->x + pos->indicex * fabsf(ray->y - pos->y) * tan(pos->col);
	}
	else if ((pos->indicey == 1 && pos->indicex == 1) ||
			(pos->indicey == -1 && pos->indicex == -1))
	{
		ray->xa = pos->indicex * pos->tile / tan(pos->col);
		ray->x = pos->x + pos->indicex * fabsf(ray->y - pos->y) / tan(pos->col);
	}
}

int		ft_horiz(t_vecteur *pos, t_vecteur *ray, t_window *win)
{
	int		tmp;

	if ((pos->indicex == 1 && pos->indicey == -1) ||
			(pos->indicex == -1 && pos->indicey == 1))
		ray->dist = fabsf(pos->y - ray->y) / cos(pos->col);
	else if ((pos->indicex == 1 && pos->indicey == 1) ||
			(pos->indicex == -1 && pos->indicey == -1))
		ray->dist = fabsf(pos->x - ray->x) / cos(pos->col);
	if (ray->x > 0 && ray->y > 0 && ray->x < (pos->tile * win->col) &&
			ray->y < (pos->tile * win->rows))
	{
		ray->gridx = (ray->x + pos->indicex * 0.000001) / pos->tile;
		ray->gridy = (ray->y + pos->indicey) / pos->tile;
		tmp = (ray->x + pos->indicex * 0.01) / pos->tile;
		if ((ray->x + pos->indicex * 0.01) < (pos->tile * win->col) &&
				pos->map[ray->gridy][tmp] == '2')
			ray->offset++;
		else if (pos->map[ray->gridy][ray->gridx] == '1')
			return (1);
	}
	return (0);
}
