/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:57:49 by aduchemi          #+#    #+#             */
/*   Updated: 2020/04/29 18:29:39 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_shift(t_vecteur *pos, char c, float *angle)
{
	if ((pos->indicex == 1 && pos->indicey == 1) ||
			(pos->indicex == -1 && pos->indicey == -1))
		ft_shift_all(pos, c, angle);
	else if ((pos->indicex == 1 && pos->indicey == -1) ||
			(pos->indicex == -1 && pos->indicey == 1))
		ft_shift_diff(pos, c, angle);
	if (c == 'r')
	{
		pos->indicex *= -1;
		pos->indicey *= -1;
	}
}

void	ft_deplacement_diff(t_vecteur *pos, float angle)
{
	int		gridx;
	int		gridy;

	gridx = ((pos->x + pos->indicex * sin(angle) * pos->pace) +
			pos->indicex * 5) / pos->tile;
	gridy = ((pos->y + pos->indicey * cos(angle) * pos->pace) +
			pos->indicey * 5) / pos->tile;
	if (pos->map[gridy][gridx] != '1' && pos->map[gridy][gridx] != '2')
	{
		pos->x = pos->x + pos->indicex * sin(angle) * pos->pace;
		pos->y = pos->y + pos->indicey * cos(angle) * pos->pace;
	}
}

void	ft_deplacement_all(t_vecteur *pos, float angle)
{
	int		gridx;
	int		gridy;

	gridx = ((pos->x + pos->indicex * cos(angle) * pos->pace) +
			pos->indicex * 5) / pos->tile;
	gridy = ((pos->y + pos->indicey * sin(angle) * pos->pace) +
			pos->indicey * 5) / pos->tile;
	if (pos->map[gridy][gridx] != '1' && pos->map[gridy][gridx] != '2')
	{
		pos->x = pos->x + pos->indicex * cos(angle) * pos->pace;
		pos->y = pos->y + pos->indicey * sin(angle) * pos->pace;
	}
}

void	ft_deplacement(t_vecteur *pos, float angle)
{
	if ((pos->indicex == 1 && pos->indicey == -1) ||
			(pos->indicex == -1 && pos->indicey == 1))
		ft_deplacement_diff(pos, angle);
	else if ((pos->indicex == 1 && pos->indicey == 1) ||
			(pos->indicex == -1 && pos->indicey == -1))
		ft_deplacement_all(pos, angle);
	pos->gridx = pos->x / pos->tile;
	pos->gridy = pos->y / pos->tile;
}

void	ft_tourne(t_vecteur *pos, char c)
{
	if (c == 'g')
		pos->alpha -= 2 * M_PI / 180.0;
	else
		pos->alpha += 2 * M_PI / 180.0;
}
