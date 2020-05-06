/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:12:16 by aduchemi          #+#    #+#             */
/*   Updated: 2020/05/06 14:35:57 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_2_H
# define CUB3D_2_H

int				ft_exp(t_pt *pt);
int				ft_free_all(t_vecteur *pos, t_window *win, t_tex *tex, int ind);
void			ft_free_tex(t_window *win, t_tex *tex);
void			ft_free_map(t_vecteur *pos, t_window *win);
t_pt			ft_set_pt(t_vecteur *pos, t_window *win, t_image *im,
			t_tex *tex);
void			ft_init_tex(t_tex *tex);
void			ft_init_win(t_window *window);
int				ft_random_line(char *line);
int				ft_attribuer_texture(t_tex *tex, t_image *im,
				t_image *mur, t_window *win);
int				ft_gestion_arg(int ac, char **av,
			t_window *win, t_tex *tex);
void			ft_afficher_sprite(t_image *im, t_vecteur *spr,
			t_tex *tex, int x);
void			ft_al_kashi(t_vecteur *pos, t_vecteur *spr,
			float angle_ray);
void			ft_sprite_hauteur(t_vecteur *pos, t_vecteur *spr,
			float a, float ind);
t_coord			ft_centre_sprite(t_vecteur *pos, t_vecteur *spr,
			t_coord *s_proj);
void			ft_projection(t_vecteur *pos, t_coord *s_proj,
			t_coord coef, int ind);
float			ft_indice(char c, int pos_ind, float spr, float proj);
void			ft_angle_centre_ray(float droite, char c, int pos_ind,
			float *angle);
void			ft_coef_ray(t_vecteur *spr, t_vecteur *pos,
			t_coord *coef);
int				ft_check_cond(t_vecteur *pos, t_vecteur *spr);
void			ft_set_s_proj(t_coord *s_proj, t_vecteur *spr);
t_vecteur		ft_spritecast(t_vecteur *pos, t_vecteur spr,
			t_window *win, float angle);
void			ft_set_sprite2(t_vecteur *spr_hor, t_vecteur *spr_ver,
			t_vecteur spr);
t_vecteur		ft_choix_sprite_ray(t_vecteur *spr_hor,
			t_vecteur *spr_ver, t_window *win, t_vecteur *pos);
int				ft_spritecast_vertic(t_vecteur *pos,
				t_vecteur *spr, t_window *win);
int				ft_sprite_vertic(t_vecteur *pos,
				t_vecteur *spr, t_window *win);
float			ft_set_spr_ver_xa_ya(t_vecteur *spr, t_vecteur *pos);
int				ft_spritecast_horiz(t_vecteur*pos,
				t_vecteur *spr, t_window *win);
int				ft_sprite_horiz(t_vecteur *pos, t_vecteur *spr,
				t_window *win);
float			ft_set_spr_hor_xa_ya(t_vecteur *spr, t_vecteur *pos);
float			ft_angle_centre_sprite(t_vecteur *pos, t_vecteur *spr,
			float *angle_s);
int				ft_texture(char *line, t_window *win,
				t_image *im);
t_coul			ft_ray_texture(t_vecteur *ray, t_image *tx, int *index,
			float *j);
t_coul			ft_code_couleur(unsigned char red, unsigned char green,
			unsigned char blue);
int				ft_deal_key(int key, t_pt *pt);
int				ft_deal_mouse(t_pt *pt, int button);
void			ft_do_op_mouv(int key, t_pt *pt, float *angle);
void			ft_shift(t_vecteur *pos, char c, float *angle);
void			ft_shift_all(t_vecteur *pos, char c, float *angle);
void			ft_shift_diff(t_vecteur *pos, char c, float *angle);
void			ft_deplacement_diff(t_vecteur *pos, float angle);
void			ft_deplacement_all(t_vecteur *pos, float angle);
void			ft_deplacement(t_vecteur *pos, float angle);
void			ft_tourne(t_vecteur *pos, char c);
void			ft_pixel_put(t_image *im, int x, int y, t_coul couleur);
int				ft_fond_ceiling(t_image *im, t_window *win);
void			ft_fond_floor(t_image *im, t_window *win, int k);
void			ft_set_image(t_image *im, t_window *win);
int				ft_parsing(t_vecteur *pos, t_window *win,
				t_tex *tex, char *av);
int				ft_set_window(t_window *win, t_tex *tex,
				char *av);
int				ft_set_window_suite(t_window *win, t_tex *tex, int fd);
int				ft_taille_fond(char *line, t_window *win);
int				ft_wall_tex(char *line, t_window *win,
				t_tex *tex);
int				ft_resolution(t_window *win, char *line);
void			ft_resolution_suite(t_window *win, char *line, int *i);
int				ft_c_f(t_window *win, char *line, char c);
int				ft_recup_int(char *line, int *i, int blue);
int				ft_verif_settings(t_window *win, t_tex *tex);
int				ft_end_line(char *line, int *i);
int				ft_map(t_vecteur *pos, t_window *win, char *av);
int				ft_size_map(char *av, t_window *win,
				int *row_start, int *row_end);
void			ft_size_map_gnl(char *line, t_window *win,
			int *row_start, int *row_end);
int				ft_malloc_map(t_vecteur *pos, t_window *win);
int				ft_fill_map(char *av, t_window *win,
				int row_start, t_vecteur *pos);
int				ft_perso(t_vecteur *pos, t_window *win);
int				ft_check_murs(t_vecteur *pos, t_window *win,
				char check);
void			ft_cpy(char *dst, char *line, int columns);
int				ft_zero_entoure(t_vecteur *pos, t_window *win,
				int i, int j);
int				ft_check_map_exist(t_window *win);
int				ft_position(t_vecteur *pos, t_window *win);
void			ft_afficher_col(t_image *im, t_vecteur *ray,
			t_tex *tex, int x);
void			ft_ray_boucle(t_vecteur *pos, t_window *win,
			t_image *im, t_tex *tex);
void			ft_set_cote(t_vecteur *ray, float angle,
			t_vecteur *pos);
int				ft_generer_ecran(t_window *win, t_image *im,
				t_vecteur *pos, t_tex *tex);
void			ft_orientation_alpha(t_vecteur *pos);
void			ft_set_spr_ray(t_vecteur *spr, t_vecteur *ray);
void			ft_set_ray(t_vecteur *pos, float *angle);
void			ft_set_ray_suite(t_vecteur *pos, float tmp);
void			ft_choix_aff_sprite(t_image *im, t_vecteur *spr,
			t_tex *tex, float x);
t_vecteur		ft_raycast(t_vecteur *pos, t_window *win, float *angle);
t_vecteur		ft_choix_ray(t_vecteur *ray_hor, t_vecteur *ray_ver,
			t_window *win, t_vecteur *pos);
int				ft_horiz(t_vecteur *pos, t_vecteur *ray,
				t_window *win);
int				ft_raycast_horiz(t_vecteur *pos, t_vecteur *ray,
				t_window *win);
int				ft_vertic(t_vecteur *pos, t_vecteur *ray,
				t_window *win);
int				ft_raycast_vertic(t_vecteur *pos,
				t_vecteur *ray, t_window *win);
void			ft_set_vertic_xa_ya(t_vecteur *ray, t_vecteur *pos);
void			ft_set_horiz_xa_ya(t_vecteur *ray, t_vecteur *pos);
void			ft__save(t_image *im, int fd);
void			ft_entete_fichier(t_image *im, int fd, int padding);
void			ft_entete_image(t_image *im, int fd, int padding);
void			ft_corps_image(t_image *im, int fd, int padding);
void			ft_write_bmp(t_image *im, int fd, int ligne);
int				ft_err_handl(int error);
int				ft_err_handl_suite(int error);
int				ft_err_handl_suite_bis(int error);
int				ft_doop_err_path(char *line);
int				ft_err_perso(int perso);
int				ft_verif_couleur(t_window *win);
#endif
