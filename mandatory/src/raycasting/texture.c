/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:34:24 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/26 14:33:28 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void add_texture(t_root *root)
{
	int j  = 0;
	char *text;
	
	while(root->map.texture[j])
	{
		if (ft_strncmp(root->map.texture[j], "SO", 2) == 0)
		{
			text = ft_strtrim(root->map.texture[j], "SO ");
			root->window.tex.texture1 = mlx_xpm_file_to_image(root->window.mlx, text, &root->window.tex.t_width, &root->window.tex.t_height);
			root->window.tex.addr1 = mlx_get_data_addr(root->window.tex.texture1, &root->window.tex.bpp, &root->window.tex.line_len, &root->window.tex.endian);
		}
		if (ft_strncmp(root->map.texture[j], "WE", 2) == 0)
		{
			text = ft_strtrim(root->map.texture[j], "WE ");
			root->window.tex.texture2 = mlx_xpm_file_to_image(root->window.mlx, text, &root->window.tex.t_width, &root->window.tex.t_height);
			root->window.tex.addr2 = mlx_get_data_addr(root->window.tex.texture2, &root->window.tex.bpp, &root->window.tex.line_len, &root->window.tex.endian);
		}
		if (ft_strncmp(root->map.texture[j], "EA", 2) == 0)
		{
			text = ft_strtrim(root->map.texture[j], "EA ");
			root->window.tex.texture3 = mlx_xpm_file_to_image(root->window.mlx, text, &root->window.tex.t_width, &root->window.tex.t_height);
			root->window.tex.addr3 = mlx_get_data_addr(root->window.tex.texture3, &root->window.tex.bpp, &root->window.tex.line_len, &root->window.tex.endian);
		}
		if (ft_strncmp(root->map.texture[j], "NO", 2) == 0)
		{
			text = ft_strtrim(root->map.texture[j], "NO ");
			root->window.tex.texture4 = mlx_xpm_file_to_image(root->window.mlx, text, &root->window.tex.t_width, &root->window.tex.t_height);
			root->window.tex.addr4 = mlx_get_data_addr(root->window.tex.texture4, &root->window.tex.bpp, &root->window.tex.line_len, &root->window.tex.endian);
		}
		j++;
	}
}

void put_texture(t_root *root)
{
	root->x_text = 0;
	if (root->rays.dis_v < root->rays.dis_h)
	{
		root->x_text = root->rays.wall_vy / 32.0;
		root->x_text = root->x_text - (int)root->x_text;
	}
	if (root->rays.dis_v > root->rays.dis_h)
	{
		root->x_text = root->rays.wall_hx / 32.0;
		root->x_text = root->x_text - (int)root->x_text;
	}
	root->x_text = root->x_text * root->window.tex.t_width;
}


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

void	draw_wall(t_root *root,int i)
{
	int			j;
	double		colorx;
	int			color;
	int 		*ptr;
	double 		y;
	double 		distancefromtop;

	y = (double)root->window.tex.t_height / root->inter.wallstripheight;
	j = (int)root->inter.top ;
	root->y_text = 0;
	color = 0xFFFFFF;
	while (j < (int)root->inter.bottom)
	{
		distancefromtop = (j + (root->inter.wallstripheight / 2)) - (WIN_HEIGHT / 2);
		if (distancefromtop  < 0)
			distancefromtop *=-1;
		root->y_text =  y * distancefromtop;
		root->y_text  = (int)root->y_text % root->window.tex.t_height;
		colorx = ((double)root->window.tex.t_width * root->y_text) + root->x_text;
		ptr = (int *)root->window.tex.addr1;
		color = ptr[(int)colorx];
		img_pix_put(&root->window.img, i, j, color);
		j++;
	}
}