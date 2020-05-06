/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:58:14 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 14:07:06 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_deal_mouse(t_pt *pt, int button)
{
	ft_free_all(pt->pos, pt->win, pt->tex, 1);
	exit(0);
	return (0);
}

int		ft_deal_key(int key, t_pt *pt)
{
	float	angle;
	int		k;
	t_image	new;

	k = 0;
	angle = 0;
	if (key == ESC)
	{
		ft_free_all(pt->pos, pt->win, pt->tex, 1);
		exit(0);
	}
	else if (key == UP || key == LEFT || key == DOWN || key == RIGHT ||
	key == ARROW_LEFT || key == ARROW_RIGHT)
	{
		ft_do_op_mouv(key, pt, &angle);
		ft_set_image(&new, pt->win);
		ft_ray_boucle(pt->pos, pt->win, &new, pt->tex);
		ft_orientation_alpha(pt->pos);
		mlx_put_image_to_window(pt->win->mlx_ptr, pt->win->ptr, new.ptr, 0, 0);
		mlx_destroy_image(pt->win->mlx_ptr, pt->win->im.ptr);
		pt->win->im = new;
	}
	return (0);
}

void	ft_do_op_mouv(int key, t_pt *pt, float *angle)
{
	if (key == UP || key == LEFT || key == DOWN || key == RIGHT)
	{
		if (key == UP)
			ft_shift(pt->pos, 'a', angle);
		else if (key == LEFT)
			ft_shift(pt->pos, 'g', angle);
		else if (key == RIGHT)
			ft_shift(pt->pos, 'd', angle);
		else if (key == DOWN)
			ft_shift(pt->pos, 'r', angle);
		ft_deplacement(pt->pos, *angle);
	}
	else if (key == ARROW_LEFT)
		ft_tourne(pt->pos, 'g');
	else if (key == ARROW_RIGHT)
		ft_tourne(pt->pos, 'd');
}

void	ft_shift_all(t_vecteur *pos, char c, float *angle)
{
	if (pos->indicex == 1)
		*angle = pos->alpha - 90 * M_PI / 180;
	else
		*angle = pos->alpha - 270 * M_PI / 180;
	if (c == 'd')
		pos->indicex *= -1;
	else if (c == 'g')
		pos->indicey *= -1;
}

void	ft_shift_diff(t_vecteur *pos, char c, float *angle)
{
	if (pos->indicex == 1)
		*angle = pos->alpha;
	else
		*angle = pos->alpha - 180 * M_PI / 180;
	if (c == 'd')
		pos->indicey *= -1;
	else if (c == 'g')
		pos->indicex *= -1;
}
