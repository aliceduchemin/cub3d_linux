/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteurs_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:42:15 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/02 00:04:47 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_vecteur	ft_spritecast(t_vecteur *pos, t_vecteur spr,
			t_window *win, float angle)
{
	t_vecteur	spr_hor;
	t_vecteur	spr_ver;
	t_vecteur	res;
	float		angle_centre;

	ft_set_sprite2(&spr_hor, &spr_ver, spr);
	if (ft_spritecast_horiz(pos, &spr_hor, win) == 1)
	{
		ft_angle_centre_sprite(pos, &spr_hor, &angle_centre);
		spr_hor.dist2 = spr_hor.dist *
			cos(fabsf(angle + angle_centre - pos->alpha));
	}
	if (ft_spritecast_vertic(pos, &spr_ver, win) == 1)
	{
		ft_angle_centre_sprite(pos, &spr_ver, &angle_centre);
		spr_ver.dist2 = spr_ver.dist *
			cos(fabsf(angle + angle_centre - pos->alpha));
	}
	res = ft_choix_sprite_ray(&spr_hor, &spr_ver, win, pos);
	return (res);
}

float		ft_angle_centre_sprite(t_vecteur *pos, t_vecteur *spr,
			float *angle_s)
{
	float	a;
	float	b;
	float	a_prime;

	a = sqrt(powf(fabsf(spr->os.x - spr->x), 2) +
		powf(fabsf(spr->os.y - spr->y), 2));
	b = sqrt(powf(fabsf(pos->x - spr->x), 2) +
		powf(fabsf(pos->y - spr->y), 2));
	spr->dist = sqrt(powf(fabsf(spr->os.x - pos->x), 2) +
				powf(fabsf(spr->os.y - pos->y), 2));
	if ((*angle_s = (powf(a, 2) - powf(b, 2) - powf(spr->dist, 2)) /
					(-2 * b * spr->dist)) > 1)
		*angle_s = 1;
	*angle_s = acos(*angle_s);
	a_prime = spr->dist * tan(*angle_s);
	spr->h = 0;
	return (a_prime);
}

void		ft_set_sprite2(t_vecteur *spr_hor, t_vecteur *spr_ver,
			t_vecteur spr)
{
	spr_hor->x = spr.x;
	spr_hor->y = spr.y;
	spr_ver->x = spr.x;
	spr_ver->y = spr.y;
	spr_ver->h = 0;
	spr_hor->h = 0;
	spr_ver->offset = 0;
	spr_hor->offset = 0;
	spr_hor->dist2 = 0;
	spr_ver->dist2 = 0;
	spr_hor->os.x = 0;
	spr_hor->os.y = 0;
	spr_ver->os.x = 0;
	spr_ver->os.y = 0;
}

t_vecteur	ft_choix_sprite_ray(t_vecteur *spr_hor,
			t_vecteur *spr_ver, t_window *win, t_vecteur *pos)
{
	if (spr_ver->dist2 == 0)
		return (*spr_hor);
	else if (spr_hor->dist2 == 0)
		return (*spr_ver);
	else if (spr_ver->dist2 > spr_hor->dist2 && spr_ver->x >= 0 &&
			spr_ver->x < (pos->tile * win->col) && spr_ver->y >= 0 &&
			spr_ver->y < (pos->tile * win->rows))
		return (*spr_ver);
	return (*spr_hor);
}
