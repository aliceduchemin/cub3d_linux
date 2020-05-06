/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonnes2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:50:00 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/02 13:22:24 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_ray(t_vecteur *pos, float *angle)
{
	float	tmp;

	if (*angle > 360 * M_PI / 180)
		*angle = *angle - 360 * M_PI / 180;
	if (*angle < 0 * M_PI / 180)
		*angle = *angle + 360 * M_PI / 180;
	tmp = (float)((int)(*angle * 1000)) / 1000;
	if (tmp >= 0 && tmp < 90 * M_PI / 180)
	{
		pos->indicex = 1;
		pos->indicey = -1;
		pos->col = tmp;
	}
	else if (tmp >= 90 * M_PI / 180 && tmp < 180 * M_PI / 180)
	{
		pos->indicex = 1;
		pos->indicey = 1;
		pos->col = tmp - 90 * M_PI / 180;
	}
	else
		ft_set_ray_suite(pos, tmp);
}

void	ft_set_ray_suite(t_vecteur *pos, float tmp)
{
	if (tmp >= 180 * M_PI / 180 && tmp < 270 * M_PI / 180)
	{
		pos->indicex = -1;
		pos->indicey = 1;
		pos->col = tmp - 180 * M_PI / 180;
	}
	else if (tmp >= 270 * M_PI / 180 && tmp < 360 * M_PI / 180)
	{
		pos->indicex = -1;
		pos->indicey = -1;
		pos->col = tmp - 270 * M_PI / 180;
	}
}

void	ft_set_cote(t_vecteur *ray, float angle, t_vecteur *pos)
{
	if (ray->cote == 'h' && (angle < 90 * M_PI / 180 ||
					angle > 270 * M_PI / 180))
		ray->cote = 'n';
	else if (ray->cote == 'h' && (angle > 90 * M_PI / 180 &&
					angle < 270 * M_PI / 180))
		ray->cote = 's';
	else if (ray->cote == 'v' && (angle > 0 * M_PI / 180 &&
					angle < 180 * M_PI / 180))
		ray->cote = 'e';
	else if (ray->cote == 'v' && (angle > 180 * M_PI / 180 &&
					angle < 360 * M_PI / 180))
		ray->cote = 'o';
	ray->h = (float)pos->tile / ray->dist2 * pos->dist;
	ray->tile = pos->tile;
}

void	ft_orientation_alpha(t_vecteur *pos)
{
	if (pos->alpha > 360 * M_PI / 180)
		pos->alpha = 0 * M_PI / 180;
	if (pos->alpha < 0 * M_PI / 180)
		pos->alpha = 360 * M_PI / 180;
	if (pos->alpha > 0 && pos->alpha < 90 * M_PI / 180)
		pos->indicey = -1;
	else if (pos->alpha > 90 * M_PI / 180 && pos->alpha < 180 * M_PI / 180)
		pos->indicey = 1;
	else if (pos->alpha > 180 * M_PI / 180 && pos->alpha < 270 * M_PI / 180)
	{
		pos->indicex = -1;
		pos->indicey = 1;
	}
	else if (pos->alpha > 270 * M_PI / 180 && pos->alpha < 360 * M_PI / 180)
	{
		pos->indicex = -1;
		pos->indicey = -1;
	}
}

void	ft_afficher_col(t_image *im, t_vecteur *ray, t_tex *tex, int x)
{
	int			i;
	float		j;
	t_coul		couleur;
	int			index;
	t_image		texture;

	if (ray->cote == 'n')
		texture = tex->nord;
	else if (ray->cote == 's')
		texture = tex->sud;
	else if (ray->cote == 'o')
		texture = tex->ouest;
	else if (ray->cote == 'e')
		texture = tex->est;
	index = (int)ray->x % ray->tile * texture.size_line / texture.width;
	j = 0;
	i = 0;
	while (i < ray->h)
	{
		couleur = ft_ray_texture(ray, &texture, &index, &j);
		if (im->hei / 2 - ray->h / 2 + i >= 0 && im->hei / 2 -
		ray->h / 2 + i <= im->hei)
			ft_pixel_put(im, x, im->hei / 2 - ray->h / 2 + i, couleur);
		i++;
	}
}
