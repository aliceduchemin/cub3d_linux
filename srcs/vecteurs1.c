/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteurs1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:08:55 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/01 23:29:03 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_vecteur	ft_raycast(t_vecteur *pos, t_window *win, float *angle)
{
	t_vecteur	ray_hor;
	t_vecteur	ray_ver;
	t_vecteur	res;

	ray_hor.dist2 = 0;
	ray_hor.offset = 0;
	ray_ver.dist2 = 0;
	ray_ver.offset = 0;
	if (ft_raycast_horiz(pos, &ray_hor, win) == 1)
		ray_hor.dist2 = ray_hor.dist * cos(fabsf(*angle - pos->alpha));
	if (ft_raycast_vertic(pos, &ray_ver, win) == 1)
		ray_ver.dist2 = ray_ver.dist * cos(fabsf(*angle - pos->alpha));
	res = ft_choix_ray(&ray_hor, &ray_ver, win, pos);
	return (res);
}

t_vecteur	ft_choix_ray(t_vecteur *ray_hor, t_vecteur *ray_ver,
			t_window *win, t_vecteur *pos)
{
	ray_hor->offset += ray_ver->offset;
	ray_ver->offset = ray_hor->offset;
	if (ray_ver->dist2 == 0)
	{
		ray_hor->cote = 'h';
		return (*ray_hor);
	}
	else if (ray_hor->dist2 == 0)
	{
		ray_ver->cote = 'v';
		return (*ray_ver);
	}
	else if (ray_ver->dist2 < ray_hor->dist2 && ray_ver->x >= 0 &&
			ray_ver->x < (pos->tile * win->col) && ray_ver->y >= 0
			&& ray_ver->y < (pos->tile * win->rows))
	{
		ray_ver->cote = 'v';
		return (*ray_ver);
	}
	ray_hor->cote = 'h';
	return (*ray_hor);
}

int			ft_raycast_vertic(t_vecteur *pos, t_vecteur *ray, t_window *win)
{
	ft_set_vertic_xa_ya(ray, pos);
	if (ray->x > 0 && ray->y > 0 && ray->x < (pos->tile * win->col) &&
			ray->y < (pos->tile * win->rows))
	{
		if (ft_vertic(pos, ray, win) == 1)
			return (1);
	}
	while (ray->x > 0 && ray->y > 0 && ray->x < (pos->tile * win->col) &&
			ray->y < (pos->tile * win->rows))
	{
		ray->x += ray->xa;
		ray->y += ray->ya;
		if (ft_vertic(pos, ray, win) == 1)
			return (1);
	}
	return (0);
}

void		ft_set_vertic_xa_ya(t_vecteur *ray, t_vecteur *pos)
{
	float d_x;

	d_x = (float)((int)(pos->x * 100) % (pos->tile * 100)) / 100;
	ray->xa = pos->indicex * pos->tile;
	if (pos->indicex == -1)
		ray->x = pos->x - d_x;
	else
		ray->x = pos->x + pos->tile - d_x;
	if ((pos->indicey == -1 && pos->indicex == 1) ||
			(pos->indicey == 1 && pos->indicex == -1))
	{
		ray->ya = pos->indicey * pos->tile / tan(pos->col);
		ray->y = pos->y + pos->indicey * fabsf(ray->x - pos->x) / tan(pos->col);
	}
	else if ((pos->indicey == 1 && pos->indicex == 1) ||
			(pos->indicey == -1 && pos->indicex == -1))
	{
		ray->ya = pos->indicey * pos->tile * tan(pos->col);
		ray->y = pos->y + pos->indicey * fabsf(ray->x - pos->x) * tan(pos->col);
	}
}

int			ft_vertic(t_vecteur *pos, t_vecteur *ray, t_window *win)
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
		ray->gridx = (ray->x + pos->indicex) / pos->tile;
		ray->gridy = (ray->y + pos->indicey * 0.000001) / pos->tile;
		tmp = (ray->y + pos->indicey * 0.01) / pos->tile;
		if ((ray->y + pos->indicey * 0.01) < (pos->tile * win->rows) &&
				pos->map[tmp][ray->gridx] == '2')
			ray->offset++;
		if (pos->map[ray->gridy][ray->gridx] == '1')
			return (1);
	}
	return (0);
}
