/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:24:21 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/18 11:40:47 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "macros.h"
# include "types.h"
# include "../../libs/Libft/libft.h"
# include "../../libs/mlx/mlx.h"

void	put_errors(char *str);
void	ft_free_table(char **ptr);

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

void	ft_init_colors(t_root *root);
void	ft_chk_path(t_root *root);
void	ft_init_header(t_root *root);

void	ft_alloc_tables(t_root *root, int count);

void	ft_chk_body(t_root *root, int *count);

void	ft_chk_header(t_root *root);

char	*get_next_line(int fd);
void	ft_read_map(char *av, t_root *root);
void	ft_backbone(char *av, t_root *root);

#endif