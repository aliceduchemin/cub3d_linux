/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:43:16 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 17:58:07 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_gestion_arg(int ac, char **av, t_window *win, t_tex *tex)
{
	int	len;

	win->save = 0;
	if (ac == 3 && ft_strncmp(av[2], "--save", 6) == 0)
		win->save = 1;
	else if (ac != 2)
		return (ft_err_handl(-23));
	len = ft_strlen(av[1]);
	if (ft_strncmp(ft_substr(av[1], len - 4, 4), ".cub", 4) != 0)
		return (ft_err_handl(-28));
	ft_init_win(win);
	ft_init_tex(tex);
	return (0);
}

t_pt	ft_set_pt(t_vecteur *pos, t_window *win, t_image *im, t_tex *tex)
{
	t_pt	res;

	res.pos = pos;
	res.win = win;
	res.win->im = *im;
	res.tex = tex;
	return (res);
}

void	ft_init_win(t_window *win)
{
	win->ptr = NULL;
	win->width = 0;
	win->hei = 0;
	win->floor = ft_code_couleur(-1, -1, -1);
	win->ceiling = ft_code_couleur(-1, -1, -1);
}

void	ft_init_tex(t_tex *tex)
{
	tex->nord.ptr = NULL;
	tex->sud.ptr = NULL;
	tex->est.ptr = NULL;
	tex->ouest.ptr = NULL;
	tex->sprite.ptr = NULL;
}

int		ft_exp(t_pt *pt)
{
	mlx_put_image_to_window(pt->win->mlx_ptr,
	pt->win->ptr, pt->win->im.ptr, 0, 0);
	return (0);
}
