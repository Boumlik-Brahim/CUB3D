/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:24:21 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/24 10:43:49 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "macros.h"
# include "types.h"
# include "../../libs/Libft/libft.h"
# include "../../libs/mlx/mlx.h"

/*----------------------------------parsiing----------------------------------*/
void	ft_error(char *str);
void	ft_free_table(char **ptr);
void	ft_free_map_listes(t_root *root);
void	ft_free_map_tables(t_root *root);

void	ft_chk_player(t_root *root);
int		ft_chkmc_horizontal(int r, int c, t_root *root);
int		ft_chkmc_vertical(int r, int c, t_root *root);
int		ft_chkm_content(char c);
void	ft_chk_body_content(t_root *root);

int		ft_chk_dup(t_list **list, char *text, int size);
int		ft_chk_space(char *tmp);
int		ft_chk_num(char *color);
int		ft_colorlen(char **tmp);
int		ft_colortoint(char *color);
int		ft_chk_digit(char *color);
int		ft_chk_color(char *color);

int		ft_chk_ext(char *str, char	*ext);
int		ft_chk_txt(char *text);
int		ft_is_space(char c);
int		is_nempty_line(char *line);

void	ft_init_body(t_root *root, int count);

int		ft_convert_color(char *color);
int		ft_split_color(char *color);
void	ft_init_colors(t_root *root);
void	ft_chk_path(t_root *root);
void	ft_init_header(t_root *root);

void	ft_alloc_tables(t_root *root, int count);

void	ft_chk_body(t_root *root, int *count);

void	ft_chk_header(t_root *root);

char	*get_next_line(int fd);
void	ft_read_map(char *av, t_root *root);
void	ft_parssing(char *av, t_root *root);
/*----------------------------------parsiing----------------------------------*/

/*---------------------------------raycasting---------------------------------*/
int		funct_ptr(int keycode, t_root *root);
int		funct_ptr_release(int keycode, t_root *root);
int		ft_close(t_root *root);
int		handle_keypress(void *ptr);
void	ft_find_pdirection(t_root *root);
void	init_data(t_root *root);
void	calcule_new_x_y(t_root *root);
void	where_player(t_root *root);
void	ft_raycasting(t_root *root);

int		is_wall(t_root *root, int x, int y);
double	normalize_angle(double angle);
void	move_player(t_root *root);

void	draw_background(t_root *root);

void	img_pix_put(t_img *img, int x, int y, int color);
void	draw_wall(t_root *root, int x, int y, int width_fi);
double	dist_bet_posx_and_inter(t_root *root, double inter_x, double inter_y);
void	check_wall(t_root *root);
void	check_intersection_vertical(t_root *root, int id);
void	find_intersection_verticale(t_root *root, int id);
void	check_intersection_horiz(t_root *root, int id);
void	find_intersection_horiz(t_root *root, int id);
void	check_angle(t_root *root);
void	init_ray(t_root *root);
int		add_tree_project_wall(t_root *root);

void	paint_minimap(t_root *root);
void	drawplayer(t_root *root);
void	map_to_window(t_root *root, int x, int y, int add);
void	update_win(t_root *root);
void	create_angle(t_root *root);
void	creatl_ddl_alg(t_root *root, double newposx, double newposy, int color);
void	mini_map(t_root *root);

/*--------------------------------texture funct-------------------------------*/
// void    put_texture(t_root *root, int i);
// void    add_texture(t_root *root);
// void    draw_wall(t_root *root,int i);
/*--------------------------------texture funct-------------------------------*/

/*---------------------------------raycasting---------------------------------*/

#endif