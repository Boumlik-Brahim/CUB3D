/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:18:38 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/20 12:34:00 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	add_tree_project_wall(t_map *map)
{
	int		i;
	t_inter inter;

	i = 0;

	paint_win(map, 0, WIN_HEIGHT / 2);
	map->player.ray_angle = map->player.rot_angle - (map->player.fov_angle / 2);
	map->player.dis_v = 0;
	map->player.dis_h = 0;
	while (i < map->player.num_rays)
	{
		map->player.ray_angle = normalize_angle(map->player.ray_angle);
		init_ray(map);
		find_intersection_horiz(map);
		find_intersection_verticale(map);
		if (map->player.dis_v < map->player.dis_h)
			inter.raydistance = map->player.dis_v;
		else
			inter.raydistance = map->player.dis_h;
		inter.projectplan = (WIN_WIDTH / 2) / tan(map->player.fov_angle / 2);
		inter.wallstripheight = (32 / inter.raydistance) * inter.projectplan;
		inter.top = (WIN_HEIGHT / 2) - (inter.wallstripheight / 2);
		if (inter.top < 0)
			inter.top = 0;
		inter.bottom = (WIN_HEIGHT / 2) + (inter.wallstripheight / 2);
		if (inter.bottom > WIN_HEIGHT)
			inter.bottom = WIN_HEIGHT;

		draw_wall(map, i, inter.top, inter.bottom);
		map->player.ray_angle += (map->player.fov_angle / map->player.num_rays);
		i++;
	}
}
