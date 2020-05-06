/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:43:41 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/02 17:47:18 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_coord	ft_centre_sprite(t_vecteur *pos, t_vecteur *spr, t_coord *s_proj)
{
	t_coord	os;

	if (spr->cote == 'h')
	{
		os.x = floor(spr->x / 64) * 64 + 32;
		os.y = floor(spr->y / 64) * 64 + pos->indicey * 32;
	}
	else
	{
		os.x = floor(spr->x / 64) * 64 + pos->indicex * 32;
		os.y = floor(spr->y / 64) * 64 + 32;
	}
	s_proj->x = os.x;
	s_proj->y = os.y;
	return (os);
}

void	ft_projection(t_vecteur *pos, t_coord *s_proj, t_coord coef, int ind)
{
	if (ind == 0)
	{
		s_proj->y = s_proj->y - pos->indicey * 32;
		if ((int)pos->x != (int)s_proj->x)
			s_proj->x = (s_proj->y - coef.y) / coef.x;
	}
	else
	{
		s_proj->x = s_proj->x - pos->indicex * 32;
		if ((int)pos->y != (int)s_proj->y)
			s_proj->y = coef.x * s_proj->x + coef.y;
	}
}

void	ft_angle_centre_ray(float droite, char c, int pos_ind, float *angle)
{
	if (c == 'x')
	{
		if (droite <= 0)
			*angle = -pos_ind * *angle;
		else
			*angle = pos_ind * *angle;
	}
	else
	{
		if (droite <= 0)
			*angle = pos_ind * *angle;
		else
			*angle = -pos_ind * *angle;
	}
}

float	ft_indice(char c, int pos_ind, float spr, float proj)
{
	float	indice;

	if (c == 'x')
	{
		if (pos_ind == 1)
			indice = spr - proj;
		else
			indice = proj - spr;
	}
	else
	{
		if (pos_ind == 1)
			indice = proj - spr;
		else
			indice = spr - proj;
	}
	return (indice);
}

void	ft_afficher_sprite(t_image *im, t_vecteur *spr, t_tex *tex, int x)
{
	int			i;
	float		j;
	t_coul		couleur;
	int			index;

	j = 0;
	index = spr->offset * tex->sprite.size_line / tex->sprite.width +
			tex->sprite.size_line * (int)j;
	i = 0;
	while (i < spr->h)
	{
		couleur = ft_code_couleur(tex->sprite.pixels[index],
				tex->sprite.pixels[index + 1],
				tex->sprite.pixels[index + 2]);
		if (tex->sprite.pixels[index] != '\0' && im->hei / 2 - spr->h
		/ 2 + i >= 0 && im->hei / 2 - spr->h / 2 + i <= im->hei)
			ft_pixel_put(im, x, im->hei / 2 - spr->h / 2 + i,
			couleur);
		index = spr->offset * tex->sprite.size_line /
		tex->sprite.width + tex->sprite.size_line * (int)j;
		i++;
		j += (float)tex->sprite.hei / spr->h;
	}
}
