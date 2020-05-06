/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:49:36 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 14:08:52 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int ac, char **av)
{
	t_window	win;
	t_vecteur	pos;
	t_pt		pt;
	t_image		im;
	t_tex		tex;

	if (ft_gestion_arg(ac, av, &win, &tex) != 0)
		return (-1);
	win.mlx_ptr = mlx_init();
	if (ft_parsing(&pos, &win, &tex, av[1]) == -1)
		return (-1);
	ft_set_image(&im, &win);
	pt = ft_set_pt(&pos, &win, &im, &tex);
	if (ft_generer_ecran(&win, &(win.im), &pos, &tex) != 0)
	{
		ft_free_all(&pos, &win, &tex, 0);
		return (0);
	}
	mlx_hook(win.ptr, 2, (1L << 0), ft_deal_key, &pt);
	mlx_hook(win.ptr, 33, (1L << 5), ft_deal_mouse, &pt);
	mlx_loop_hook(win.mlx_ptr, ft_exp, &pt);
	mlx_loop(win.mlx_ptr);
	ft_free_all(&pos, &win, &tex, 1);
	return (0);
}
