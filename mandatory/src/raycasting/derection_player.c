/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derection_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:15:21 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/20 15:24:20 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
void move_player(t_map *map)
{
	double	angle;
	double	posx;
	double	posy;
	double	movestep;
	
	mlx_clear_window(map->window.mlx, map->window.win);
	update_win(map);
	movestep = map->player.walkdir * map->player.movespeed;
	angle = map->player.rot_angle + M_PI / 2;
	angle = normalize_angle(angle);
	if (map->player.direction == 0)
		angle = map->player.rot_angle;
	posx = map->player.posx + cos(angle) * movestep;
	posy = map->player.posy + sin(angle) * movestep;
	if (is_wall(map, posx, posy) == 0)
	{
		map->player.posx = posx;
		map->player.posy = posy;
	}
	map_to_window(map, 100, 100, 4);
	if (map->player.direction == 2)
	{
		map->player.rot_angle += map->player.turndir * map->player.turnspeed;
	}
}

// void	move_player_left_right(t_map *map)
// {
// 	double	angle;
// 	double	posx;
// 	double	posy;

// 	mlx_clear_window(map->window.mlx, map->window.win);
// 	update_win(map);
// 	angle = map->player.rot_angle + M_PI / 2;
// 	angle = normalize_angle(angle);
// 	posx = map->player.posx + cos(angle) * map->player.walkspeed * 4;
// 	posy = map->player.posy + sin(angle) * map->player.walkspeed * 4;
// 	if (is_wall(map, posx, posy) == 0)
// 	{
// 		map->player.posx = posx;
// 		map->player.posy = posy;
// 	}
// 	map_to_window(map, 100, 100, 4);
// }

// void	move_player_up_down(t_map *map)
// {
// 	double	movestep;
// 	double	posx;
// 	double	posy;

// 	mlx_clear_window(map->window.mlx, map->window.win);
// 	update_win(map);
// 	movestep = map->player.walkdir * map->player.movespeed;
// 	map->player.rot_angle = normalize_angle(map->player.rot_angle);
// 	posx = map->player.posx + cos(map->player.rot_angle) * movestep;
// 	posy = map->player.posy + sin(map->player.rot_angle) * movestep;
// 	if (is_wall(map, posx, posy) == 0)
// 	{
// 		map->player.posx = posx;
// 		map->player.posy = posy;
// 	}
// 	map_to_window(map, 100, 100, 4);
// }

// void	turndir(t_map *map)
// {
// 	mlx_clear_window(map->window.mlx, map->window.win);
// 	update_win(map);
// 	map_to_window(map, 100, 100, 4);
// 	map->player.rot_angle += map->player.turndir * map->player.turnspeed;
// }

int	funct_ptr(int keycode, t_map *map)
{
	if (keycode == 2)
	{
		map->player.walkdir = 1;
	}
	if (keycode == 0)
	{
		map->player.walkdir = -1;
	}
	if (keycode == 1)
	{
		map->player.walkdir = -1;
		map->player.direction = 0;
	}
	if (keycode == 13)
	{
		map->player.walkdir = 1;
		map->player.direction = 0;
	}
	if (keycode == 124)
	{
		map->player.turndir = 1;
		map->player.direction = 2;
	}
	if (keycode == 123)
	{
		map->player.turndir = -1;
		map->player.direction = 2;
	}
	if (keycode == 53)
	{
		mlx_clear_window(map->window.mlx, map->window.win);
		exit (0);
	}
	move_player(map);
	add_tree_project_wall(map);
	mini_map(map);
	return (0);
}
