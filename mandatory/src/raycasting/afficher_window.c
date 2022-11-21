/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:26:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/21 09:09:11 by bbrahim          ###   ########.fr       */
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
	while (i < step && x < 200 && y < 200)
	{
		mlx_pixel_put(map->window.mlx, map->window.win,
			round(x), round(y), color);
		x = x + x_inc;
		y = y + y_inc;
		i++;
	}
}

void ckeck_hor_ver(t_map *map)
{
	double	pointx;
	double	pointy;

	pointx = 0.0;
	pointy = 0.0;
	if (map->player.is_intv == 1 && map->player.is_inth == 1)
	{
		if (map->player.dis_v < map->player.dis_h)
		{
			pointx = map->player.wall_vx - map->player.newx;
			pointy = map->player.wall_vy - map->player.newy;
		}
		else
		{
			pointx = map->player.wall_hx - map->player.newx;
			pointy = map->player.wall_hy - map->player.newy;
		}
	}
	else if (map->player.is_intv == 1 && map->player.is_inth == 0)
	{
		pointx = map->player.wall_vx - map->player.newx;
		pointy = map->player.wall_vy - map->player.newy;
	}
	else if (map->player.is_intv == 0 && map->player.is_inth == 1)
	{
		pointx = map->player.wall_hx - map->player.newx;
		pointy = map->player.wall_hy - map->player.newy;
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
		init_ray(map);
		find_intersection_horiz(map);
		find_intersection_verticale(map);
		ckeck_hor_ver(map);
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
				mlx_pixel_put(map->window.mlx,
					map->window.win, j, i, 0x3F3B6C);
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
			mlx_pixel_put(map->window.mlx, map->window.win, j++, i, 0xFFFFFF);
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
}
