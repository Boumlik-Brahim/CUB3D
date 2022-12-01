/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:24:21 by bbrahim           #+#    #+#             */
/*   Updated: 2022/12/01 13:39:22 by zel-hach         ###   ########.fr       */
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

/*----------------------------------parssing----------------------------------*/
void	ft_error(char *str);
void	ft_free_table(char **ptr);
void	ft_free_map_listes(t_root *root);
void	ft_free_map_tables(t_root *root);
void	ft_chk_body_content(t_root *root);
int		ft_chk_dup(t_list **list, char *text, int size);
int		ft_colorlen(char **tmp);
int		ft_chk_color(char *color);
int		ft_chk_ext(char *str, char	*ext);
int		ft_chk_txt(char *text); 
int		is_nempty_line(char *line);
void	ft_init_body(t_root *root, int count);
void	ft_init_header(t_root *root);
void	ft_alloc_tables(t_root *root, int count);
void	ft_chk_body(t_root *root, int *count);
void	ft_chk_header(t_root *root);
char	*get_next_line(int fd);
void	ft_read_map(char *av, t_root *root);
void	ft_parssing(char *av, t_root *root);
/*----------------------------------parssing----------------------------------*/

/*---------------------------------raycasting---------------------------------*/

/*--------------------------raycasting/background.c--------------------------*/

void	draw_background(t_root *root);

/* ------------------------- /raycasting/check_intersection.c --------------*/

double	dist_bet_posx_and_inter(t_root *root, double inter_x, double inter_y);
void	new_pointx(t_root *root, double x, double y);
void	ckeck_hor_ver(t_root *root);
/* ------------------------- /raycasting/check_wall.c --------------*/

int		ft_chkzero_vertical(int r, int c, t_root *root);
int		ft_chkzero_horizontal(int r, int c, t_root *root);
void	replace(t_root *root);
int		is_wall(t_root *root, int x, int y);

/*---------------------------------/raycasting/ddl_algo.c--------------------*/

void	creatl_dda_alg(t_root *root, double newposx, double newposy, int color);

/*-------------------------------/raycasting/move_player.c-------------*/

void	check_angle(t_root *root);
double	normalize_angle(double angle);
void	move_player(t_root *root);

/*-------------------------------/raycasting/draw_wall.c--------------------*/

void	calcule_wallheight(t_root *root);
void	cast(t_root *root);
void	draw(t_root *root, int i);
void	fish_bowl(t_root *root);
int		add_tree_project_wall(t_root *root);

/*-------------------------------/raycasting/init_data.c--------------------*/

void	init_inter(t_root *root);
void	init_player(t_root *root);
void	init_data(t_root *root);
void	init_ray(t_root *root);

/*--------------------------/raycasting/intersection_horizontal.c------------*/

void	check_intersection_horiz(t_root *root);
void	find_intersection_horiz(t_root *root);

/*-------------------------/raycasting/intersection_vertical.c-------------*/

void	check_intersection_vertical(t_root *root);
void	find_intersection_verticale(t_root *root);

/*--------------------------/raycasting/keyevent_hooking.c-------------------*/

int		ft_close(t_root *root);
int		funct_ptr(int keycode, t_root *root);
int		funct_ptr_release(int keycode, t_root *root);

/*---------------------------/raycasting/pos_player.c----------------------*/

void	where_player(t_root *root);

/*-------------------------------/raycasting/raycasting.c------------------*/

int		handle_keypress(void *ptr);
void	ft_find_pdirection(t_root *root);
void	ft_raycasting(t_root *root);

/*--------------------------------/src/raycasting/texture.c---------------*/

void	texture(t_root *root, t_texture1 *tex, char *text);
void	push_texture(t_root *root, int j);
void	add_texture(t_root *root);
/*-----------------------------------/raycasting/update_window.c-----------*/

void	img_pix_put(t_img *img, int x, int y, int color);
int		get_color(t_root *root, t_texture1	*tex);
void	draw_wall(t_root *root, int i, t_texture1	*tex);
bool	offset_x(t_root *root, t_texture1 *tex);
/*---------------------------------raycasting---------------------------------*/

#endif