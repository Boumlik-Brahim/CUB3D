/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inersection_horizontal_and_vertical.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:37:33 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/20 21:38:13 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void check_wall(t_map *map, t_inter *inter)
{
	while (!is_wall(map, inter->x_intercet, inter->y_intercet))
	{
		inter->x_intercet += inter->xsteep;
		inter->y_intercet += inter->ysteep;
	}
}

double	distancebetwen_posx_and_inter(t_map *map, double inter_x, double inter_y)
{
	double	x;
	double	y;
	double	res;

	x = (inter_x - map->player.posx) * (inter_x - map->player.posx);
	y = (inter_y - map->player.posy) * (inter_y - map->player.posy);
	res = x + y;
	return (sqrt(res));
}

void	check_intersection_vertical(t_map *map, t_inter *inter)
{
	check_wall(map, inter);
	map->player.is_intv = 1;
	map->player.wall_vx = inter->x_intercet;
	map->player.wall_vy = inter->y_intercet;
	map->player.dis_v = distancebetwen_posx_and_inter(map, map->player.wall_vx, map->player.wall_vy);
}

void	check_intersection_horiz(t_map *map, t_inter *inter)
{

	check_wall(map, inter);
	map->player.is_inth = 1;
	map->player.wall_hx = inter->x_intercet;
	map->player.wall_hy = inter->y_intercet;
	map->player.dis_h = distancebetwen_posx_and_inter(map, map->player.wall_hx, map->player.wall_hy);
}


void	find_intersection_horiz(t_map *map)
{
	t_inter inter;

	map->player.dis_h = 0;
	inter.y_intercet = floor(map->player.posy / 32) * 32;
	if (map->player.up == 1)
			inter.y_intercet += 32;
	inter.ysteep = 32;
	if (map->player.down == 1)
		inter.ysteep *= -1;
	inter.x_intercet = map->player.posx + ((inter.y_intercet - map->player.posy) / tan(map->player.ray_angle));
	inter.xsteep = inter.ysteep / tan(map->player.ray_angle);
	if ((map->player.left == 1 && inter.xsteep > 0))
		inter.xsteep *= -1;
	if ((map->player.right == 1 && inter.xsteep < 0))
		inter.xsteep *= -1;
	if (map->player.down == 1)
			inter.y_intercet--;
	map->player.is_inth = 0;
	check_intersection_horiz(map, &inter);
}

void	find_intersection_verticale(t_map *map)
{
	t_inter inter;

	map->player.dis_v = 0;
	inter.x_intercet = floor(map->player.posx / 32) * 32;
	if (map->player.right == 1)
		inter.x_intercet += 32;
	inter.y_intercet = map->player.posy + ((inter.x_intercet - map->player.posx) * tan(map->player.ray_angle));
	inter.xsteep = 32;
	if (map->player.left == 1)
		inter.xsteep *= -1;
	inter.ysteep = 32 * tan(map->player.ray_angle);
	if ((map->player.down == 1 && inter.ysteep > 0))
		inter.ysteep *= -1;
	if ((map->player.up == 1 && inter.ysteep < 0))
		inter.ysteep *= -1;
	if (map->player.left == 1)
		inter.x_intercet--;
	map->player.is_intv = 0;
	check_intersection_vertical(map, &inter);
}
