/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derection_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:15:21 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/20 21:09:15 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void move_player(t_map *map)
{
	double	angle;
	double	posx;
	double	posy;
	double	movestep;
	
	if (map->player.walkdir != 0)
		movestep = map->player.walkdir * 4;
	if (map->player.walkspeed != 0)
		movestep = map->player.walkspeed * 4;
	angle = map->player.rot_angle + M_PI / 2;
	map->player.rot_angle += map->player.turndir * map->player.turnspeed;
	angle = normalize_angle(angle);
	if (map->player.walkdir != 0)
		angle = normalize_angle(map->player.rot_angle);
	posx = map->player.posx + cos(angle) * movestep;
	posy = map->player.posy + sin(angle) * movestep;
	if (is_wall(map, posx, posy) == 0)
	{
		map->player.posx = posx;
		map->player.posy = posy;
	}
}

int	funct_ptr(int keycode, t_map *map)
{
	map->player.turndir = 0;
	map->player.walkdir = 0;
	map->player.walkspeed = 0;
	if (keycode == 2)
		map->player.walkspeed = 1;
	if (keycode == 0)
		map->player.walkspeed = -1;
	if (keycode == 1)
		map->player.walkdir = -1;
	if (keycode == 13)
		map->player.walkdir = 1;
	if (keycode == 124)
		map->player.turndir = 1;
	if (keycode == 123)
		map->player.turndir = -1;
	if (keycode == 53)
	{
		mlx_clear_window(map->window.mlx, map->window.win);
		exit (0);
	}
	move_player(map);

	return (0);
}
