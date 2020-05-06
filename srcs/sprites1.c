/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:24:57 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/01 19:02:02 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sprite_hauteur(t_vecteur *pos, t_vecteur *spr, float a, float ind)
{
	if ((int)(a * 100) % 6400 <= 3200 && a < 64 && a >= 0)
	{
		if (ind < 0)
			spr->offset = 32 - (((int)(a * 100)) % 6400) / 100;
		else
			spr->offset = (((int)(a * 100) + 3200) % 6400) / 100;
		spr->h = (float)pos->tile / spr->dist2 * pos->dist;
	}
}

void	ft_coef_ray(t_vecteur *spr, t_vecteur *pos, t_coord *coef)
{
	coef->x = (spr->os.y - pos->y) / (spr->os.x - pos->x);
	coef->y = spr->os.y - coef->x * spr->os.x;
}

void	ft_al_kashi(t_vecteur *pos, t_vecteur *spr, float angle_ray)
{
	t_coord	coef;
	t_coord	s_proj;
	float	tmp;
	float	a_prime;

	tmp = 1;
	ft_set_s_proj(&s_proj, spr);
	a_prime = ft_angle_centre_sprite(pos, spr, &tmp);
	ft_coef_ray(spr, pos, &coef);
	if (ft_check_cond(pos, spr) == 1)
	{
		ft_projection(pos, &s_proj, coef, 0);
		ft_angle_centre_ray(spr->x - s_proj.x, 'x', pos->indicey, &tmp);
		spr->dist2 = spr->dist * cos(fabsf(angle_ray + tmp - pos->alpha));
		tmp = ft_indice('y', pos->indicey, spr->x, s_proj.x);
	}
	else if (ft_check_cond(pos, spr) == 2)
	{
		ft_projection(pos, &s_proj, coef, 1);
		ft_angle_centre_ray(spr->y - s_proj.y, 'y', pos->indicex, &tmp);
		spr->dist2 = spr->dist * cos(fabsf(angle_ray + tmp - pos->alpha));
		tmp = ft_indice('x', pos->indicex, spr->y, s_proj.y);
	}
	ft_sprite_hauteur(pos, spr, a_prime, tmp);
}

int		ft_check_cond(t_vecteur *pos, t_vecteur *spr)
{
	if (fabsf(pos->x - spr->os.x) < fabsf(pos->y - spr->os.y) ||
			(fabsf(pos->x - spr->os.x) == fabsf(pos->y - spr->os.y) &&
			((int)spr->x % pos->tile) > ((int)spr->y % pos->tile)))
		return (1);
	else if (fabsf(pos->x - spr->os.x) > fabsf(pos->y - spr->os.y) ||
			(fabsf(pos->x - spr->os.x) == fabsf(pos->y - spr->os.y) &&
			((int)spr->x % pos->tile) < ((int)spr->y % pos->tile)))
		return (2);
	return (0);
}

void	ft_set_s_proj(t_coord *s_proj, t_vecteur *spr)
{
	s_proj->x = spr->os.x;
	s_proj->y = spr->os.y;
}
