/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:44:21 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 18:11:05 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	update_win(t_map *map)
{
	paint_minimap(map);
	map->j = 0;
	while (map->content[map->j])
	{
		map->i = 0;
		while (map->content[map->j][map->i])
		{
			if (map->content[map->j][map->i] == '1')
				map_to_window(map, map->i * 32 - map->window.player.newx,
					map->j * 32 - map->window.player.newy, 32);
			// if (map->content[map->j][map->i] == '0')
			// 	map_to_window(map, map->i * 32 - map->window.player.newx,
			// 		map->j * 32 - map->window.player.newy, 32);
			if (map->content[map->j][map->i] == 'N')
				map->content[map->j][map->i] = '0';
			map->i++;
		}
		map->j++;
	}
}

void	create_line_ddl_alg(t_map *map, double newposx, double newposy, int color)
{
	double	x;
	double	y;
	int		i;
	double	step;
	double	x_inc;
	double	y_inc;

	map->window.player.deltax = newposx - 100;
	map->window.player.deltay = newposy - 100;
	if (fabs(map->window.player.deltax) > fabs(map->window.player.deltay))
		step = fabs(map->window.player.deltax);
	else
		step = fabs(map->window.player.deltay);
	x_inc = map->window.player.deltax / step;
	y_inc = map->window.player.deltay / step;
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

void	create_angle(t_map *map)
{
	int		i;
	double	pointx;
	double	pointy;

	i = 0;
	map->window.player.ray_angle = map->window.player.rot_angle - (map->window.player.fov_angle / 2);
	while (i < map->window.player.num_rays)
	{
		map->window.player.ray_angle = normalize_angle(map->window.player.ray_angle);
		init_ray(map);
		find_intersection_horiz(map);
		find_intersection_verticale(map);
		if (map->window.player.is_intv == 1 && map->window.player.is_inth == 1)
		{
			if (map->window.player.dis_v < map->window.player.dis_h)
			{
				pointx = map->window.player.wall_vx - map->window.player.newx;
				pointy = map->window.player.wall_vy - map->window.player.newy;
				create_line_ddl_alg(map, pointx, pointy, 0xD4D925);
			}
			else
			{
				pointx = map->window.player.wall_hx - map->window.player.newx;
				pointy = map->window.player.wall_hy - map->window.player.newy;
				create_line_ddl_alg(map, pointx, pointy, 0xD4D925);
			}
		}
		else if (map->window.player.is_intv == 1 && map->window.player.is_inth == 0)
		{
			pointx = map->window.player.wall_vx - map->window.player.newx;
			pointy = map->window.player.wall_vy - map->window.player.newy;
			create_line_ddl_alg(map, pointx, pointy, 0xD4D925);
		}
		else if (map->window.player.is_intv == 0 && map->window.player.is_inth == 1)
		{
			pointx = map->window.player.wall_hx - map->window.player.newx;
			pointy = map->window.player.wall_hy - map->window.player.newy;
			create_line_ddl_alg(map, pointx, pointy, 0xD4D925);
		}
		map->window.player.ray_angle += (map->window.player.fov_angle / map->window.player.num_rays);
		i++;
	}
}
