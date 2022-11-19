/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:57:50 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 17:59:57 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	check_angle(t_map *map)
{
	if (map->window.player.ray_angle >= 0
		&& map->window.player.ray_angle <= M_PI)
		map->window.player.up = 1;
	else
		map->window.player.down = 1;
	if (map->window.player.ray_angle <= 0.5 * M_PI
		|| map->window.player.ray_angle >= 1.5 * M_PI)
		map->window.player.right = 1;
	else
		map->window.player.left = 1;
}

void	init_ray(t_map *map)
{
	map->window.player.wall_hx = 0;
	map->window.player.wall_hy = 0;
	map->window.player.wall_vy = 0;
	map->window.player.wall_vx = 0;
	map->window.player.down = 0;
	map->window.player.up = 0;
	map->window.player.left = 0;
	map->window.player.right = 0;
	check_angle(map);
}

void	init_player(t_window *window)
{
	window->player.turndir = 0;
	window->player.walkdir = 0;
	window->player.rot_angle = M_PI / 2;
	window->player.walkspeed = 0;
	window->player.movespeed = 3.0;
	window->player.turnspeed = 4 * M_PI / 180;
	window->player.fov_angle = 60 * M_PI / 180;
	window->player.num_rays = window->width * 32;
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}
