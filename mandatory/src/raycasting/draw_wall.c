/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:18:38 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/20 12:08:32 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	add_tree_project_wall(t_map *map)
{
	int		i;
	t_inter inter;

	i = 0;

	// paint_win(map, 0, map->window.height * 32 / 2);

	map->window.player.ray_angle = map->window.player.rot_angle - (map->window.player.fov_angle / 2);
	map->window.player.dis_v = 0;
	map->window.player.dis_h = 0;
	while (i < map->window.player.num_rays)
	{
		map->window.player.ray_angle = normalize_angle(map->window.player.ray_angle);
		init_ray(map);
		find_intersection_horiz(map);
		find_intersection_verticale(map);
		if (map->window.player.dis_v < map->window.player.dis_h)
			inter.raydistance = map->window.player.dis_v;
		else
			inter.raydistance = map->window.player.dis_h;

		// inter.projectplan = (map->window.width * 32 / 2) / tan(map->window.player.fov_angle / 2);
		inter.projectplan = (WIN_WIDTH / 2) / tan(map->window.player.fov_angle / 2);

		inter.wallstripheight = (32 / inter.raydistance) * inter.projectplan;

		// inter.top = (map->window.height * 32 / 2) - (inter.wallstripheight / 2);
		inter.top = (WIN_HEIGHT / 2) - (inter.wallstripheight / 2);

		if (inter.top < 0)
			inter.top = 0;

		// inter.bottom = (map->window.height * 32 / 2) + (inter.wallstripheight / 2);
		inter.bottom = (WIN_HEIGHT / 2) + (inter.wallstripheight / 2);

		// if (inter.bottom > map->window.height * 32)
		// 	inter.bottom = map->window.height * 32;
		if (inter.bottom > WIN_HEIGHT)
			inter.bottom = WIN_HEIGHT;

		draw_wall(map, i, inter.top, inter.bottom);
		map->window.player.ray_angle += (map->window.player.fov_angle / map->window.player.num_rays);
		i++;
	}
}
