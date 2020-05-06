/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:39:15 by aduchemi          #+#    #+#             */
/*   Updated: 2020/04/30 00:24:28 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft__save(t_image *im, int fd)
{
	int		padding;

	padding = (im->width * 3) % 4;
	ft_entete_fichier(im, fd, padding);
	ft_entete_image(im, fd, padding);
	ft_corps_image(im, fd, padding);
}

void	ft_entete_fichier(t_image *im, int fd, int padding)
{
	unsigned int	file_size;
	unsigned int	data_offset;

	file_size = im->width * im->hei * 3 + padding * im->hei + 54;
	data_offset = 54;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &data_offset, 4);
}

void	ft_entete_image(t_image *im, int fd, int padding)
{
	unsigned int	header_size;
	unsigned short	plans;
	unsigned short	bpp;
	unsigned int	im_size;
	unsigned int	res;

	header_size = 40;
	plans = 1;
	bpp = 24;
	res = 3780;
	im_size = im->width * im->hei * 3 + padding * im->hei;
	write(fd, &header_size, 4);
	write(fd, &(im->width), 4);
	write(fd, &(im->hei), 4);
	write(fd, &plans, 2);
	write(fd, &bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &im_size, 4);
	write(fd, &res, 4);
	write(fd, &res, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "\0\0\0\0", 4);
}

void	ft_write_bmp(t_image *im, int fd, int ligne)
{
	int		largeur;
	int		index;

	largeur = 0;
	index = 0;
	while (largeur < im->width)
	{
		write(fd, im->pixels + im->size_line * ligne +
		index, sizeof(char));
		write(fd, im->pixels + im->size_line * ligne +
		index + sizeof(char), sizeof(char));
		write(fd, im->pixels + im->size_line * ligne +
		index + 2 * sizeof(char), sizeof(char));
		index += 4;
		largeur++;
	}
}

void	ft_corps_image(t_image *im, int fd, int padding)
{
	int		ligne;

	ligne = im->hei - 1;
	while (ligne >= 0)
	{
		ft_write_bmp(im, fd, ligne);
		if (padding != 0)
			write(fd, "\0", sizeof(char) * padding);
		ligne--;
	}
}
