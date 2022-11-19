/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derection_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:15:21 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 14:30:58 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_player_left_right(t_readmap *map)
{
	double	angle;
	double	posx;
	double	posy;

	mlx_clear_window(map->window.mlx, map->window.win);
	update_win(map);
	angle = map->window.player.rot_angle + M_PI / 2;
	angle = normalize_angle(angle);
	posx = map->window.player.posx + cos(angle) * map->window.player.walkspeed * 4;
	posy = map->window.player.posy + sin(angle) * map->window.player.walkspeed * 4;
	if (is_wall(map, posx, posy) == 0)
	{
		map->window.player.posx = posx;
		map->window.player.posy = posy;
	}
	map_to_window(map, 100, 100, 4);
}

void	move_player_up_down(t_readmap *map)
{
	double	movestep;
	double	posx;
	double	posy;

	mlx_clear_window(map->window.mlx, map->window.win);
	update_win(map);
	movestep = map->window.player.walkdir * map->window.player.movespeed;
	map->window.player.rot_angle = normalize_angle(map->window.player.rot_angle);
	posx = map->window.player.posx + cos(map->window.player.rot_angle) * movestep;
	posy = map->window.player.posy + sin(map->window.player.rot_angle) * movestep;
	if (is_wall(map, posx, posy) == 0)
	{
		map->window.player.posx = posx;
		map->window.player.posy = posy;
	}
	map_to_window(map, 100, 100, 4);
}

void	turndir(t_readmap *map)
{
	mlx_clear_window(map->window.mlx, map->window.win);
	update_win(map);
	map_to_window(map, 100, 100, 4);
	map->window.player.rot_angle += map->window.player.turndir * map->window.player.turnspeed;
}

int	funct_ptr(int keycode, t_readmap *map)
{
	if (keycode == 2)
	{
		map->window.player.walkspeed = +1;
		move_player_left_right(map);
	}
	if (keycode == 0)
	{
		map->window.player.walkspeed = -1;
		move_player_left_right(map);
	}
	if (keycode == 1)
	{
		map->window.player.walkdir = -1;
		move_player_up_down(map);
	}
	if (keycode == 13)
	{
		map->window.player.walkdir = 1;
		move_player_up_down(map);
	}
	if (keycode == 124)
	{
		map->window.player.turndir = 1;
		turndir(map);
	}
	if (keycode == 123)
	{
		map->window.player.turndir = -1;
		turndir(map);
	}
	if (keycode == 53)
	{
		mlx_clear_window(map->window.mlx, map->window.win);
		exit (0);
	}
	add_tree_project_wall(map);
	mini_map(map);
	return (0);
}
