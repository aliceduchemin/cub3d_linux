/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:12:09 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 14:48:13 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_1_H
# define CUB3D_1_H

# ifdef __linux__
#  define ESC 65307
#  define LEFT 113
#  define RIGHT 100
#  define DOWN 115
#  define UP 122
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
# elif __APPLE__
#  define ESC 53
#  define LEFT 0
#  define RIGHT 2
#  define DOWN 1
#  define UP 13
#  define ARROW_LEFT 123
#  define ARROW_RIGHT 124
# endif

typedef struct	s_coul
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_coul;

typedef struct	s_image
{
	void	*ptr;
	char	*pixels;
	int		bpp;
	int		endian;
	int		size_line;
	int		width;
	int		hei;
}				t_image;

typedef struct	s_window
{
	int		save;
	void	*mlx_ptr;
	void	*ptr;
	int		width;
	int		hei;
	t_image	im;
	char	*title;
	int		rows;
	int		col;
	t_coul	floor;
	t_coul	ceiling;
}				t_window;

typedef struct	s_coord
{
	float	x;
	float	y;
}				t_coord;

typedef struct	s_vecteur
{
	int		gridx;
	int		gridy;
	float	x;
	float	y;
	t_coord	os;
	float	xa;
	float	ya;
	float	dist;
	float	dist2;
	float	offset;
	float	col;
	int		indicex;
	int		indicey;
	int		tile;
	int		pace;
	float	alpha;
	char	**map;
	char	cote;
	float	h;
}				t_vecteur;

typedef struct	s_tex
{
	t_image		nord;
	t_image		sud;
	t_image		est;
	t_image		ouest;
	t_image		sprite;
}				t_tex;

typedef struct	s_pt
{
	t_vecteur	*pos;
	t_window	*win;
	t_tex		*tex;
}				t_pt;
#endif
