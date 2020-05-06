CUB_SRCS_NAME	= main.c support_init.c support_free.c vecteurs1.c vecteurs2.c parsing1.c parsing2.c parsing3.c parsing_map1.c parsing_map2.c colonnes1.c colonnes2.c image.c actions1.c actions2.c textures.c sprites1.c sprites2.c vecteurs_sprites.c vecteurs_sprites_hor.c vecteurs_sprites_ver.c save_bmp.c erreur.c

CUB_SRCS_DIR	= ./srcs

CUB_SRCS	= $(addprefix $(CUB_SRCS_DIR)/, $(CUB_SRCS_NAME))

CUB_OBJS	= $(CUB_SRCS_NAME:.c=.o)

NAME		= Cub3D

BONUS		= bonus

CUB_INCLUDES_DIR= ./includes

LIBFT_DIR	= ./libft

LIBFT_EXEC	= $(LIBFT_DIR)/libft.a

MLX_DIR		= ./minilibx-linux

MLX_EXEC 	= $(MLX_DIR)/libmlx.a -lXext -lX11 -lm -lbsd

CC		= clang

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

IFLAGS		= -I $(CUB_INCLUDES_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

all:		$(LIBFT_EXEC) $(NAME)

$(NAME):	
		$(CC) -c $(IFLAGS) -g $(CUB_SRCS)
		$(CC) -o $@ $(CUB_OBJS) $(LIBFT_EXEC) $(MLX_EXEC) $(CFLAGS)

$(LIBFT_EXEC):
		cd $(LIBFT_DIR) && $(MAKE)

$(BONUS):	fclean all

clean:
		$(RM) $(CUB_OBJS)
		cd $(LIBFT_DIR) && $(MAKE) $@

fclean:		clean
		$(RM) $(NAME)
		cd $(LIBFT_DIR) && $(MAKE) $@
		rm -f cub3d.bmp

re:		fclean all

.PHONY:		all clean fclean re
