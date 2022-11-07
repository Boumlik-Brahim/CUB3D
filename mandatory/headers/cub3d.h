/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:24:21 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/07 10:56:11 by bbrahim          ###   ########.fr       */
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

int		ft_chk_ext(char *str, char *ext);
char	*ft_read_file(int fd);
void	ft_read_map(char *av, t_root *root);

int		ft_colorchr(char *color);
void	ft_init_array_collor(t_root *root);
int		ft_txtchr(char *text);
void	ft_init_array_texture(t_root *root);
int		ft_chk_texture(t_root *root);
void	ft_init_texture(t_root *root);

int		ft_chk_character(t_root *root);
int		ft_chk_walls(t_root *root);
int		ft_chk_sp(t_root *root);

#endif