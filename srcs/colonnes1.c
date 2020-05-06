/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonnes1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:49:56 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/05 22:39:40 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_generer_ecran(t_window *win, t_image *im, t_vecteur *pos, t_tex *tex)
{
	int		fd;

	fd = 0;
	ft_position(pos, win);
	ft_ray_boucle(pos, win, im, tex);
	pos->indicex = 1;
	pos->indicey = 1;
	ft_orientation_alpha(pos);
	if (win->save == 0)
	{
		win->ptr = mlx_new_window(win->mlx_ptr, win->width, win->hei,
		win->title);
		mlx_put_image_to_window(win->mlx_ptr, win->ptr, im->ptr, 0, 0);
	}
	else
	{
		if ((fd = open("cub3d.bmp", O_WRONLY | O_CREAT |
		O_TRUNC, S_IRWXU)) == -1)
			return (ft_err_handl(-2));
		ft__save(im, fd);
		close(fd);
		return (2);
	}
	return (0);
}

int		ft_position(t_vecteur *pos, t_window *win)
{
	int		i;

	i = 0;
	while (pos->map[i / win->col][i % win->col] != 'N' &&
			pos->map[i / win->col][i % win->col] != 'E' &&
			pos->map[i / win->col][i % win->col] != 'S' &&
			pos->map[i / win->col][i % win->col] != 'W')
		i++;
	if (pos->map[i / win->col][i % win->col] == 'N')
		pos->alpha = 360 * M_PI / 180;
	else if (pos->map[i / win->col][i % win->col] == 'E')
		pos->alpha = 90 * M_PI / 180;
	else if (pos->map[i / win->col][i % win->col] == 'S')
		pos->alpha = 180 * M_PI / 180;
	else if (pos->map[i / win->col][i % win->col] == 'W')
		pos->alpha = 270 * M_PI / 180;
	pos->gridx = i % win->col;
	pos->x = pos->gridx * pos->tile + pos->tile / 2;
	pos->gridy = i / win->col;
	pos->y = pos->gridy * pos->tile + pos->tile / 2;
	pos->dist = (win->width / 2) / tan((60 * M_PI / 180.0) / 2);
	return (0);
}

void	ft_ray_boucle(t_vecteur *pos, t_window *win, t_image *im, t_tex *tex)
{
	float		x;
	float		angle;
	t_vecteur	ray;
	t_vecteur	spr;

	angle = pos->alpha - 30 * M_PI / 180.0;
	x = 0;
	while (x < win->width)
	{
		ft_set_ray(pos, &angle);
		ray = ft_raycast(pos, win, &angle);
		ft_set_cote(&ray, angle, pos);
		ft_afficher_col(im, &ray, tex, x);
		ft_set_spr_ray(&spr, &ray);
		while (ray.offset--)
		{
			spr = ft_spritecast(pos, spr, win, angle);
			ft_al_kashi(pos, &spr, angle);
			ft_choix_aff_sprite(im, &spr, tex, x);
		}
		angle += (60 * M_PI / 180.0) / win->width;
		x++;
	}
}

void	ft_choix_aff_sprite(t_image *im, t_vecteur *spr, t_tex *tex, float x)
{
	if (spr->offset > 0 && spr->offset < 64 && spr->h > 0)
		ft_afficher_sprite(im, spr, tex, x);
}

void	ft_set_spr_ray(t_vecteur *spr, t_vecteur *ray)
{
	spr->x = ray->x;
	spr->y = ray->y;
	spr->dist2 = 0;
}
