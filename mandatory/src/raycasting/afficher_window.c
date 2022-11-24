/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:26:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/24 21:34:23 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	creatl_ddl_alg(t_root *root, double newposx, double newposy, int color)
{
	double	x;
	double	y;
	int		i;
	double	step;
	double	x_inc;
	double	y_inc;

	i = 1;
	y = 100;
	x = 100;
	root->player.deltax = newposx - 100;
	root->player.deltay = newposy - 100;
	if (fabs(root->player.deltax) > fabs(root->player.deltay))
		step = fabs(root->player.deltax);
	else
		step = fabs(root->player.deltay);
	x_inc = root->player.deltax / step;
	y_inc = root->player.deltay / step;
	while (i < step && x > 0 && y > 0 && x < 200 && y < 200)
	{
		img_pix_put(&root->window.img, round(x), round(y), color);
		x = x + x_inc;
		y = y + y_inc;
		i++;
	}
}

void	ckeck_hor_ver(t_root *root, int i)
{
	double	pointx;
	double	pointy;

	pointx = 0.0;
	pointy = 0.0;
	if (root->player.is_intv == 1 && root->player.is_inth == 1)
	{
		if (root->rays.dis_v[i] < root->rays.dis_h[i])
		{
			pointx = root->rays.wall_vx[i] - root->player.newx;
			pointy = root->rays.wall_vy[i] - root->player.newy;
		}
		else
		{
			pointx = root->rays.wall_hx[i] - root->player.newx;
			pointy = root->rays.wall_hy[i] - root->player.newy;
		}
	}
	else if (root->player.is_intv == 1 && root->player.is_inth == 0)
	{
		pointx = root->rays.wall_vx[i] - root->player.newx;
		pointy = root->rays.wall_vy[i] - root->player.newy;
	}
	else if (root->player.is_intv == 0 && root->player.is_inth == 1)
	{
		pointx = root->rays.wall_hx[i] - root->player.newx;
		pointy = root->rays.wall_hy[i] - root->player.newy;
	}
	creatl_ddl_alg(root, pointx, pointy, 0xD4D925);
}

void	create_angle(t_root *root)
{
	int		i;
	double	rangle;

	i = 0;
	rangle = (root->player.fov_angle / root->player.num_rays);
	root->player.ray_angle = root->player.rot_angle
		- (root->player.fov_angle / 2);
	while (i < root->player.num_rays)
	{
		root->player.ray_angle = normalize_angle(root->player.ray_angle);
		ckeck_hor_ver(root, i);
		root->player.ray_angle += rangle;
		i++;
	}
}

void	map_to_window(t_root *root, int x, int y, int color)
{
	int	i;
	int	j;
	int	yadd;
	int	xadd;

	i = y;
	yadd = y + root->player.add;
	xadd = x + root->player.add;
	while (i < yadd)
	{
		j = x;
		while (j < xadd)
		{
			if (j >= 0 && j < 200 && i >= 0 && i < 200)
				img_pix_put(&root->window.img, j, i, color);
			j++;
		}
		i++;
	}
}

/*color for 0 empty for space*/
void	update_win(t_root *root)
{
	int	i;
	int	j;

	j = 0;
	while (root->map.content[j])
	{
		i = 0;
		while (root->map.content[j][i])
		{
			root->player.add = 32;
			if (root->map.content[j][i] == '1')
			{
				map_to_window(root, i * 32 - root->player.newx,
					j * 32 - root->player.newy, 0x3F3BEE);
			}
			if (root->map.content[j][i] == '0')
			{
				map_to_window(root, i * 32 - root->player.newx,
					j * 32 - root->player.newy, 0xFFFFFF);
			}
			if (root->map.content[j][i] == 'N' || root->map.content[j][i] == 'S'
				|| root->map.content[j][i] == 'W'
				|| root->map.content[j][i] == 'E')
				root->map.content[j][i] = '0';
			i++;
		}
		j++;
	}
}

void	paint_minimap(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	while (i >= 0 && i < 200)
	{
		j = 0;
		while (j >= 0 && j < 200)
			img_pix_put(&root->window.img, j++, i, 0x000000);
		i++;
	}
}

void	mini_map(t_root *root)
{
	calcule_new_x_y(root);
	paint_minimap(root);
	update_win(root);
	create_angle(root);
}
