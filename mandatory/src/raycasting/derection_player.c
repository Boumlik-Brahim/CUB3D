/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derection_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:15:21 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/21 11:03:22 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	is_wall(t_map *map, int x, int y)
{
	int	mapgrid_x;
	int	mapgrid_y;
	int	i;
	int	j;

	mapgrid_x = (x / 32);
	mapgrid_y = (y / 32);
	i = 0;
	j = 0;
	while (map->content[i])
		i++;
	if (mapgrid_y < 0 || mapgrid_y >= i)
		return (1);
	j = ft_strlen(map->content[mapgrid_y]);
	if (mapgrid_x > j || mapgrid_x < 0)
		return (1);
	if (map->content[mapgrid_y][mapgrid_x] == '1')
		return (1);
	return (0);
}

/*add dblpi variable*/
double	normalize_angle(double angle)
{
	double	dblpi;

	dblpi = 2 * M_PI;
	angle = fmod(angle, dblpi);
	if (angle < 0)
		angle = dblpi + angle;
	return (angle);
}

/*add turndirspeed variable and half pi*/
void move_player(t_map *map)
{
	double	angle;
	double	posx;
	double	posy;
	double	movestep;
	double	turndirspeed;
	double	halfpi;
	
	halfpi = M_PI / 2;
	if (map->player.walkdir != 0)
		movestep = map->player.walkdir * 4;
	if (map->player.walkspeed != 0)
		movestep = map->player.walkspeed * 4;
	angle = map->player.rot_angle + halfpi;
	turndirspeed = map->player.turndir * map->player.turnspeed;
	map->player.rot_angle += turndirspeed;
	angle = normalize_angle(angle);
	if (map->player.walkdir != 0)
		angle = normalize_angle(map->player.rot_angle);
	posx = map->player.posx + cos(angle) * movestep;
	posy = map->player.posy + sin(angle) * movestep;
	if (!is_wall(map, posx, posy))
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
