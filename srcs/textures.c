/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:39:57 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/02 17:50:45 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_coul	ft_code_couleur(unsigned char red, unsigned char green,
		unsigned char blue)
{
	t_coul	res;

	res.red = red;
	res.green = green;
	res.blue = blue;
	return (res);
}

int		ft_texture(char *line, t_window *win, t_image *im)
{
	int		i;
	char	*path;

	i = 2;
	if (line[0] == 'S' && line[1] != 'O')
		i = 1;
	while (line[i] == ' ')
		i++;
	i++;
	path = ft_substr(line, i, ft_strlen(line) - i);
	if ((im->ptr = mlx_xpm_file_to_image(win->mlx_ptr, path, &(im->width),
	&(im->hei))) == NULL)
	{
		free(path);
		return (ft_doop_err_path(line));
	}
	free(path);
	im->pixels = mlx_get_data_addr(im->ptr, &(im->bpp), &(im->size_line),
			&(im->endian));
	return (0);
}

t_coul	ft_ray_texture(t_vecteur *ray, t_image *tx, int *index, float *j)
{
	t_coul	couleur;

	couleur = ft_code_couleur(tx->pixels[*index], tx->pixels[*index + 1],
			tx->pixels[*index + 2]);
	*j = *j + (float)tx->hei / ray->h;
	if (ray->cote == 'n' || ray->cote == 's')
		*index = (int)ray->x % ray->tile * tx->size_line / tx->width +
			tx->size_line * (int)(*j);
	else if (ray->cote == 'e' || ray->cote == 'o')
		*index = (int)ray->y % ray->tile * tx->size_line / tx->width +
			tx->size_line * (int)(*j);
	return (couleur);
}

int		ft_verif_couleur(t_window *win)
{
	if (win->floor.red == (unsigned char)-1 && win->floor.blue ==
	(unsigned char)-1 && win->floor.green == (unsigned char)-1)
		return (ft_err_handl(-4));
	if (win->ceiling.red == (unsigned char)-1 && win->ceiling.blue ==
	(unsigned char)-1 && win->ceiling.green == (unsigned char)-1)
		return (ft_err_handl(-5));
	return (0);
}
