/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:34:24 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/24 10:30:50 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// hado rah zadthm
// void add_texture(t_root *root)
// {
// 	root->window.tex.texture1 = mlx_xpm_file_to_image(root->window.mlx, "assets/textures/txt1.xpm", &root->window.tex.t_width, &root->window.tex.t_height);
// 	root->window.tex.addr = (int *)mlx_get_data_addr(root->window.tex.texture1, &root->window.tex.bpp, &root->window.tex.line_len, &root->window.tex.endian);
// }

// void put_texture(t_root *root, int i)
// {
// 	if (root->player.is_intv == 1)
// 		root->x_text = root->rays.wall_vy[i] / 32;
// 	if (root->player.is_inth == 1)
// 		root->x_text  = root->rays.wall_hx[i] / 32;
// 	root->x_text = (root->x_text - (int)root->x_text);
// 	root->x_text = root->x_text * root->window.tex.t_width;
// }

// // hadi fi blast img_pix_put
// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char    *pixel;

// 	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
// 	{
// 		pixel = (char *)img->addr + (y * img->line_len + x * (img->bpp / 8));
// 		*(int *)pixel = color;
// 	}
// 	else
// 		return ;
// }

// //hadi fi blast draw_wall li 9bal
// void	draw_wall(t_root *root,int i)
// {
// 	int		j;
// 	int		colorx;
// 	int		color;

// 	j = root->inter.top ;
// 	while (j < root->inter.bottom)
// 	{
// 		root->y_text = (root->window.tex.t_height / (int)root->inter.wallstripheight) * j;
// 		colorx = (int)(root->window.tex.t_width * (int)root->y_text) + (int)root->x_text;
// 		color = root->window.tex.addr[colorx];
// 		img_pix_put(&root->window.img, i, j, color);
// 		j++;
// 	}
// }
