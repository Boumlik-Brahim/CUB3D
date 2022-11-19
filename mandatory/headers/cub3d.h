/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:24:21 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/19 18:15:26 by zel-hach         ###   ########.fr       */
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
void	ft_split_color(char *color, char id);
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
int		long_len(t_map *map);
void	mlx(t_map *map);
void	paint_minimap(t_map *map);
void	where_player(t_map *map);
void	drawplayer(t_map *map);
void	paint_win(t_map *map ,int x,int y);
void	map_to_window(t_map *map,int x,int y,int add);
void	update_win(t_map *map);
void	init_ray(t_map *map);
void	init_player(t_window *window);
void	find_intersection_horiz(t_map *map);
void	find_intersection_verticale(t_map *map);
int		is_wall(t_map *map, int x, int y);
double	normalize_angle(double angle);
void	create_angle(t_map *map);
void	create_line_ddl_alg(t_map *map, double newposx, double newposy, int color);
void	check_angle(t_map *map);
void	draw_wall(t_map *map, int x, int y, int width_fi);
void	add_tree_project_wall(t_map *map);
void	calcule_new_x_y(t_map *map);
void	mini_map(t_map *map);
int		funct_ptr(int keycode, t_map *map);
void	move_player_left_right(t_map *map);
void	move_player_up_down(t_map *map);
void	turndir(t_map *map);
double	distancebetwen_posx_and_inter(t_map *map, double inter_x, double inter_y);
/*---------------------------------raycasting---------------------------------*/

#endif