/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:26:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/21 15:09:19 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	create_line_ddl_alg(t_map *map, double newposx, double newposy, int color)
{
	double	x;
	double	y;
	int		i;
	double	step;
	double	x_inc;
	double	y_inc;

	map->player.deltax = newposx - 100;
	map->player.deltay = newposy - 100;
	if (fabs(map->player.deltax) > fabs(map->player.deltay))
		step = fabs(map->player.deltax);
	else
		step = fabs(map->player.deltay);
	x_inc = map->player.deltax / step;
	y_inc = map->player.deltay / step;
	i = 1;
	y = 100;
	x = 100;
	while (i < step && x > 0 && y > 0 && x < 200 && y < 200)
	{
		img_pix_put(&map->window.img, round(x), round(y), color);
		x = x + x_inc;
		y = y + y_inc;
		i++;
	}
}

void ckeck_hor_ver(t_map *map, int i)
{
	double	pointx;
	double	pointy;

	pointx = 0.0;
	pointy = 0.0;
	if (map->player.is_intv == 1 && map->player.is_inth == 1)
	{
		if (map->rays.dis_v[i] < map->rays.dis_h[i])
		{
			pointx = map->rays.wall_vx[i] - map->player.newx;
			pointy = map->rays.wall_vy[i] - map->player.newy;
		}
		else
		{
			pointx = map->rays.wall_hx[i] - map->player.newx;
			pointy = map->rays.wall_hy[i] - map->player.newy;
		}
	}
	else if (map->player.is_intv == 1 && map->player.is_inth == 0)
	{
		pointx = map->rays.wall_vx[i] - map->player.newx;
		pointy = map->rays.wall_vy[i] - map->player.newy;
	}
	else if (map->player.is_intv == 0 && map->player.is_inth == 1)
	{
		pointx = map->rays.wall_hx[i] - map->player.newx;
		pointy = map->rays.wall_hy[i] - map->player.newy;
	}
	create_line_ddl_alg(map, pointx, pointy, 0xD4D925);
}

void	create_angle(t_map *map)
{
	int		i;

	double	rangle;

	i = 0;
	rangle = (map->player.fov_angle / map->player.num_rays);
	map->player.ray_angle = map->player.rot_angle - (map->player.fov_angle / 2);
	while (i < map->player.num_rays)
	{
		map->player.ray_angle = normalize_angle(map->player.ray_angle);
		ckeck_hor_ver(map,i);
		map->player.ray_angle += rangle;
		i++;
	}
}

void	map_to_window(t_map *map, int x, int y, int add)
{
	int	i;
	int	j;

	i = y;
	while (i < y + add)
	{
		j = x;
		while (j < x + add)
		{
			if (j >= 0 && j < 200 && i >= 0 && i < 200)
				img_pix_put(&map->window.img, j, i, 0x3F3BEE);
			j++;
		}
		++i;
	}
}

void	update_win(t_map *map)
{
	map->j = 0;
	while (map->content[map->j])
	{
		map->i = 0;
		while (map->content[map->j][map->i])
		{
			if (map->content[map->j][map->i] == '1')
				map_to_window(map, map->i * 32 - map->player.newx,
					map->j * 32 - map->player.newy, 32);
			if (map->content[map->j][map->i] == 'N')
				map->content[map->j][map->i] = '0';
			map->i++;
		}
		map->j++;
	}
}

void	paint_minimap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i >= 0 && i < 200)
	{
		j = 0;
		while (j >= 0 && j < 200)
			img_pix_put(&map->window.img, j++, i, 0xFFFFFF);
		++i;
	}
}

void	mini_map(t_map *map)
{
	calcule_new_x_y(map);
	paint_minimap(map);
	update_win(map);
	map_to_window(map, 100, 100, 1);
	create_angle(map);
	free(map->rays.wall_hx);
	free(map->rays.wall_hy);
	free(map->rays.dis_h);
	free(map->rays.wall_vx);
	free(map->rays.wall_vy);
	free(map->rays.dis_v);
}
