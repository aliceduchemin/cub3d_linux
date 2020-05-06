/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteurs_sprites_ver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:41:55 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/01 19:03:34 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_spritecast_vertic(t_vecteur *pos, t_vecteur *spr, t_window *win)
{
	float	d_x;

	d_x = ft_set_spr_ver_xa_ya(spr, pos);
	while ((int)spr->x > 0 && (int)spr->y > 0 &&
			spr->x < (pos->tile * win->col) &&
			spr->y < (pos->tile * win->rows) &&
			(pos->indicex * spr->x >= pos->indicex * pos->x) &&
			(pos->indicey * spr->y >= pos->indicey * pos->y))
	{
		if ((int)(spr->x * 100 + spr->xa * 100) % (pos->tile * 100) != 0)
			spr->x = floor((spr->x * 100 - pos->indicex * d_x * 100) / 100);
		else
		{
			spr->x += spr->xa;
			spr->y += spr->ya;
		}
		if (ft_sprite_vertic(pos, spr, win) == 1)
			return (1);
	}
	return (0);
}

float	ft_set_spr_ver_xa_ya(t_vecteur *spr, t_vecteur *pos)
{
	float	d_x;

	d_x = (float)((int)(spr->x * 100) % (pos->tile * 100)) / 100;
	if (pos->indicex == -1)
		d_x = pos->tile - d_x;
	spr->xa = -pos->indicex * pos->tile;
	if ((pos->indicey == -1 && pos->indicex == 1) ||
			(pos->indicey == 1 && pos->indicex == -1))
	{
		if ((int)(spr->x * 100 + spr->xa * 100) % (pos->tile * 100) != 0)
			spr->y += -pos->indicey * d_x / tan(pos->col);
		spr->ya = -pos->indicey * pos->tile / tan(pos->col);
	}
	else if ((pos->indicey == 1 && pos->indicex == 1) ||
			(pos->indicey == -1 && pos->indicex == -1))
	{
		if ((int)(spr->x * 100 + spr->xa * 100) % (pos->tile * 100) != 0)
			spr->y += -pos->indicey * d_x * tan(pos->col);
		spr->ya = -pos->indicey * pos->tile * tan(pos->col);
	}
	return (d_x);
}

int		ft_sprite_vertic(t_vecteur *pos, t_vecteur *spr, t_window *win)
{
	spr->gridx = (spr->x + pos->indicex) / pos->tile;
	spr->gridy = (spr->y + pos->indicey * 0.01) / pos->tile;
	if (spr->x > 0 && spr->y > 0 && spr->x < (pos->tile * win->col) &&
			spr->y < (pos->tile * win->rows) &&
			pos->map[spr->gridy][spr->gridx] == '2' &&
			(pos->indicex * spr->x >= pos->indicex * pos->x) &&
			(pos->indicey * spr->y >= pos->indicey * pos->y))
	{
		spr->os.x = spr->gridx * pos->tile + 32;
		spr->os.y = spr->gridy * pos->tile + 32;
		spr->dist = sqrt(powf(fabs((floor(spr->y / 64) * 64 + 32) -
					pos->y), 2) + powf(fabs((floor(spr->x / 64) * 64 +
					pos->indicex * 32) - pos->x), 2));
		return (1);
	}
	return (0);
}
