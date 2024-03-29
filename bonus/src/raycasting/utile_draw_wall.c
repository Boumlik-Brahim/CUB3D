/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_draw_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:33:48 by zel-hach          #+#    #+#             */
/*   Updated: 2022/12/01 14:50:09 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	draw_wall(t_root *root, int i, t_texture1	*tex)
{
	int			j;
	int			color;
	double		distancefromtop;

	j = (int)root->inter.top;
	root->window.tex1->y_text = 0;
	color = 0xFFFFFF;
	while (j < (int)root->inter.bottom)
	{
		distancefromtop = (j + (root->inter.wallstripheight / 2))
			- (WIN_HEIGHT / 2);
		if (distancefromtop < 0)
			distancefromtop *= -1;
		root->window.tex1->y_text = distancefromtop
			* ((double)tex->t_height1 / root->inter.wallstripheight);
		root->window.tex1->y_text = (int)root->window.tex1->y_text
			% tex->t_height1;
		color = get_color(root, tex);
		img_pix_put(&root->window.img, i, j, color);
		j++;
	}
}

bool	offset_x(t_root *root, t_texture1 *tex)
{
	root->rays.is_vertical = false;
	root->window.tex1->x_text = 0;
	if (root->rays.dis_v < root->rays.dis_h)
	{
		root->window.tex1->x_text = root->rays.wall_vy / 32.0;
		root->window.tex1->x_text = root->window.tex1->x_text
			- (int)root->window.tex1->x_text;
		root->rays.is_vertical = true;
	}
	if (root->rays.dis_v > root->rays.dis_h)
	{
		root->window.tex1->x_text = root->rays.wall_hx / 32.0;
		root->window.tex1->x_text = root->window.tex1->x_text
			- (int)root->window.tex1->x_text;
		root->rays.is_vertical = false;
	}
	root->window.tex1->x_text = root->window.tex1->x_text
		* tex->t_width1;
	return (root->rays.is_vertical);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

int	get_color(t_root *root, t_texture1	*tex)
{
	int		colorx;
	int		*ptr;
	int		color;

	colorx = (tex->t_width1 * (int)root->window.tex1->y_text)
		+ (int)root->window.tex1->x_text;
	ptr = (int *)tex->addr1;
	color = ptr[colorx];
	return (color);
}
