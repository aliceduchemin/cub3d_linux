/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:01:35 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/01 18:37:27 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_pixel_put(t_image *im, int x, int y, t_coul couleur)
{
	int		index;

	index = 0;
	if (x >= 0 && x < im->width && y >= 0 && y < im->hei)
	{
		index = ((y * im->width) + x) * 4;
		im->pixels[index] = couleur.red;
		im->pixels[index + 1] = couleur.green;
		im->pixels[index + 2] = couleur.blue;
	}
}

int		ft_fond_ceiling(t_image *im, t_window *win)
{
	int		j;
	int		k;

	j = 0;
	k = win->hei / 2;
	while (j < win->width)
	{
		while (k < win->hei / 2)
		{
			ft_pixel_put(im, j, k, win->ceiling);
			k++;
		}
		k = 0;
		j++;
	}
	return (k);
}

void	ft_fond_floor(t_image *im, t_window *win, int k)
{
	int		j;

	j = 0;
	while (j < win->width)
	{
		while (k < win->hei)
		{
			ft_pixel_put(im, j, k, win->floor);
			k++;
		}
		k = win->hei / 2;
		j++;
	}
}

void	ft_set_image(t_image *im, t_window *win)
{
	int		k;

	im->width = win->width;
	im->hei = win->hei;
	im->ptr = mlx_new_image(win->mlx_ptr, win->width, win->hei);
	im->pixels = mlx_get_data_addr(im->ptr, &(im->bpp), &(im->size_line),
			&(im->endian));
	k = ft_fond_ceiling(im, win);
	ft_fond_floor(im, win, k);
}
