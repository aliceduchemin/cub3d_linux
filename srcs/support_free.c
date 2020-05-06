/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:43:36 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 14:08:22 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_map(t_vecteur *pos, t_window *win)
{
	int		i;

	i = 0;
	while (i < win->rows)
	{
		free(pos->map[i]);
		i++;
	}
	free(pos->map);
}

void	ft_free_tex(t_window *win, t_tex *tex)
{
	if (tex->nord.ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, tex->nord.ptr);
	if (tex->sud.ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, tex->sud.ptr);
	if (tex->ouest.ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, tex->ouest.ptr);
	if (tex->est.ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, tex->est.ptr);
	if (tex->sprite.ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, tex->sprite.ptr);
}

int		ft_free_all(t_vecteur *pos, t_window *win, t_tex *tex, int ind)
{
	ft_free_map(pos, win);
	ft_free_tex(win, tex);
	mlx_destroy_image(win->mlx_ptr, win->im.ptr);
	if (ind == 1)
		mlx_destroy_window(win->mlx_ptr, win->ptr);
	free(win->mlx_ptr);
	return (0);
}
