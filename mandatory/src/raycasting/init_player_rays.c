/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:57:50 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/20 15:11:25 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	check_angle(t_map *map)
{
	if (map->player.ray_angle >= 0
		&& map->player.ray_angle <= M_PI)
		map->player.up = 1;
	else
		map->player.down = 1;
	if (map->player.ray_angle <= 0.5 * M_PI
		|| map->player.ray_angle >= 1.5 * M_PI)
		map->player.right = 1;
	else
		map->player.left = 1;
}

void	init_ray(t_map *map)
{
	map->player.wall_hx = 0;
	map->player.wall_hy = 0;
	map->player.wall_vy = 0;
	map->player.wall_vx = 0;
	map->player.down = 0;
	map->player.up = 0;
	map->player.left = 0;
	map->player.right = 0;
	check_angle(map);
}

void	init_player(t_player *player)
{
	player->turndir = 0;
	player->walkdir = 0;
	player->rot_angle = M_PI / 2;
	player->walkspeed = 0;
	player->movespeed = 3.0;
	player->turnspeed = 4 * M_PI / 180;
	player->fov_angle = 60 * M_PI / 180;
	player->direction = -1;
	player->num_rays = WIN_WIDTH;
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}
