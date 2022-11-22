/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:26:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/22 18:25:19 by bbrahim          ###   ########.fr       */
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

	i = 1;
	y = 100;
	x = 100;
	map->player.deltax = newposx - 100;
	map->player.deltay = newposy - 100;
	if (fabs(map->player.deltax) > fabs(map->player.deltay))
		step = fabs(map->player.deltax);
	else
		step = fabs(map->player.deltay);
	x_inc = map->player.deltax / step;
	y_inc = map->player.deltay / step;
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
	int	yadd;
	int	xadd;

	i = y;
	yadd = y + add;
	xadd = x + add;
	while (i < yadd)
	{
		j = x;
		while (j < xadd)
		{
			if (j >= 0 && j < 200 && i >= 0 && i < 200)
				img_pix_put(&map->window.img, j, i, 0x3F3BEE);
			j++;
		}
		i++;
	}
}

/*color for 0 empty for space*/
void	update_win(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->content[j])
	{
		i = 0;
		while (map->content[j][i])
		{
			if (map->content[j][i] == '1')
				map_to_window(map, i * 32 - map->player.newx,
					j * 32 - map->player.newy, 32);
			if (map->content[j][i] == 'N' || map->content[j][i] == 'S' || map->content[j][i] == 'W' || map->content[j][i] == 'E')
				map->content[j][i] = '0';
			i++;
		}
		j++;
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
		{
			img_pix_put(&map->window.img, j++, i, 0xFFFFFF);
		}
		i++;
	}
}

void	mini_map(t_map *map)
{
	calcule_new_x_y(map);
	paint_minimap(map);
	update_win(map);
	create_angle(map);
	// free(map->rays.wall_hx);
	// free(map->rays.wall_hy);
	// free(map->rays.dis_h);
	// free(map->rays.wall_vx);
	// free(map->rays.wall_vy);
	// free(map->rays.dis_v);
}
