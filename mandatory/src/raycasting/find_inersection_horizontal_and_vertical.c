/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_inersection_horizontal_and_vertical.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:37:33 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 15:38:55 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distancebetwen_posx_and_inter(t_readmap *map, double inter_x, double inter_y)
{
	return (sqrt((inter_x - map->window.player.posx) * (inter_x - map->window.player.posx) + (inter_y - map->window.player.posy) * (inter_y - map->window.player.posy)));
}

void	check_intersection_vertical(t_readmap *map,t_inter *inter)
{
	map->window.player.dis_v = 0;
	while (inter->x_intercet > 0 && inter->x_intercet < map->window.width * 32 && inter->y_intercet > 0 && inter->y_intercet < map->window.height * 32)
	{
		if (is_wall(map, inter->x_intercet, inter->y_intercet) == 1) 
		{
			map->window.player.is_intv = 1;
			map->window.player.wall_vx = inter->x_intercet;
			map->window.player.wall_vy = inter->y_intercet;
			break ;
		}
		else
		{
			inter->x_intercet += inter->xsteep;
			inter->y_intercet += inter->ysteep;
		}
	}
	map->window.player.dis_v = distancebetwen_posx_and_inter(map, map->window.player.wall_vx, map->window.player.wall_vy);
}

void	check_intersection_horiz(t_readmap *map, t_inter *inter)
{
	map->window.player.dis_h = 0;
	while (inter->x_intercet > 0 && inter->x_intercet <= map->window.width * 32 && inter->y_intercet > 0 && inter->y_intercet <= map->window.height * 32)
	{
		if (is_wall(map, inter->x_intercet, inter->y_intercet) == 1)
		{
			map->window.player.is_inth = 1;
			map->window.player.wall_hx = inter->x_intercet;
			map->window.player.wall_hy = inter->y_intercet;
			break ;
		}
		else
		{
			inter->x_intercet += inter->xsteep;
			inter->y_intercet += inter->ysteep;
		}
	}
	map->window.player.dis_h = distancebetwen_posx_and_inter(map, map->window.player.wall_hx,map->window.player.wall_hy);
}


void	find_intersection_horiz(t_readmap *map)
{
	t_inter inter;

	inter.y_intercet = floor(map->window.player.posy / 32) * 32;
	if (map->window.player.up == 1)
			inter.y_intercet += 32;
	inter.ysteep = 32;
	if (map->window.player.down == 1)
		inter.ysteep *= -1;
	inter.x_intercet = map->window.player.posx + (inter.y_intercet - map->window.player.posy) / tan(map->window.player.ray_angle);
	inter.xsteep = inter.ysteep / tan(map->window.player.ray_angle);
	if ((map->window.player.left == 1 && inter.xsteep > 0))
		inter.xsteep *= -1;
	if ((map->window.player.right == 1 && inter.xsteep < 0))
		inter.xsteep *= -1;
	if (map->window.player.down == 1)
				inter.y_intercet--;
	map->window.player.is_inth = 0;
	check_intersection_horiz(map, &inter);
}

void	find_intersection_verticale(t_readmap *map)
{
	t_inter inter;

	inter.x_intercet = floor(map->window.player.posx / 32) * 32;
	if (map->window.player.right == 1)
		inter.x_intercet += 32;
	inter.y_intercet = map->window.player.posy + (inter.x_intercet - map->window.player.posx) * tan(map->window.player.ray_angle);
	inter.xsteep = 32;
	if (map->window.player.left == 1)
		inter.xsteep *= -1;
	inter.ysteep = 32 * tan(map->window.player.ray_angle);
	if ((map->window.player.down == 1 && inter.ysteep > 0))
		inter.ysteep *= -1;
	if ((map->window.player.up == 1 && inter.ysteep < 0))
		inter.ysteep *= -1;
	if (map->window.player.left == 1)
		inter.x_intercet--;
	map->window.player.is_intv = 0;
	check_intersection_vertical(map, &inter);
}
