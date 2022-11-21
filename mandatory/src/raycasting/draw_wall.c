/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:18:38 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/21 11:26:25 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*increment j outside mlx_pixel_put*/
void	draw_wall(t_map *map, int x, int y, int width_fi)
{
	int	j;

	j = y;
	while (j < width_fi)
	{
		mlx_pixel_put(map->window.mlx, map->window.win, x, j, 0x3F3BEE);
		j++;
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

void check_wall(t_map *map, t_inter *inter)
{
	while (!is_wall(map, inter->x_intercet, inter->y_intercet))
	{
		inter->x_intercet += inter->xsteep;
		inter->y_intercet += inter->ysteep;
	}
}

void	check_intersection_vertical(t_map *map, t_inter *inter)
{
	check_wall(map, inter);
	map->player.is_intv = 1;
	map->player.wall_vx = inter->x_intercet;
	map->player.wall_vy = inter->y_intercet;
	map->player.dis_v = distancebetwen_posx_and_inter(map, map->player.wall_vx, map->player.wall_vy);
}

void	find_intersection_verticale(t_map *map)
{
	t_inter inter;
	double	tang;

	map->player.dis_v = 0;
	tang = tan(map->player.ray_angle);
	inter.x_intercet = floor(map->player.posx / 32) * 32;
	if (map->player.right == 1)
		inter.x_intercet += 32;
	inter.y_intercet = map->player.posy + ((inter.x_intercet - map->player.posx) * tang);
	inter.xsteep = 32;
	if (map->player.left == 1)
		inter.xsteep *= -1;
	inter.ysteep = 32 * tang;
	if ((map->player.down == 1 && inter.ysteep > 0))
		inter.ysteep *= -1;
	if ((map->player.up == 1 && inter.ysteep < 0))
		inter.ysteep *= -1;
	if (map->player.left == 1)
		inter.x_intercet--;
	map->player.is_intv = 0;
	check_intersection_vertical(map, &inter);
}

void	check_intersection_horiz(t_map *map, t_inter *inter)
{
	check_wall(map, inter);
	map->player.is_inth = 1;
	map->player.wall_hx = inter->x_intercet;
	map->player.wall_hy = inter->y_intercet;
	map->player.dis_h = distancebetwen_posx_and_inter(map, map->player.wall_hx, map->player.wall_hy);
}


/*add variable tan*/
void	find_intersection_horiz(t_map *map)
{
	t_inter inter;
	double	tang;

	map->player.dis_h = 0;
	tang = tan(map->player.ray_angle);
	inter.y_intercet = floor(map->player.posy / 32) * 32;
	if (map->player.up == 1)
		inter.y_intercet += 32;
	inter.ysteep = 32;
	if (map->player.down == 1)
		inter.ysteep *= -1;
	inter.x_intercet = map->player.posx + ((inter.y_intercet - map->player.posy) / tang);
	inter.xsteep = inter.ysteep / tang;
	if ((map->player.left == 1 && inter.xsteep > 0))
		inter.xsteep *= -1;
	if ((map->player.right == 1 && inter.xsteep < 0))
		inter.xsteep *= -1;
	if (map->player.down == 1)
			inter.y_intercet--;
	map->player.is_inth = 0;
	check_intersection_horiz(map, &inter);
}

/*compare variables not formulas*/
void	check_angle(t_map *map)
{
	double zerofivepi;
	double onefivepi;

	zerofivepi = (0.5 * M_PI);
	onefivepi = (1.5 * M_PI);
	if (map->player.ray_angle >= 0 && map->player.ray_angle <= M_PI)
		map->player.up = 1;
	else
		map->player.down = 1;
	if (map->player.ray_angle <= zerofivepi || map->player.ray_angle >= onefivepi)
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

/*add tang variable, w / 2 and h / 2*/
int	add_tree_project_wall(t_map *map)
{
	int		i;
	t_inter inter;
	double	rangle;
	double	tang;

	i = 0;
	rangle = (map->player.fov_angle / map->player.num_rays);
	tang = tan(map->player.fov_angle / 2);
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
		inter.projectplan = (WIN_WIDTH / 2) / tang;
		inter.wallstripheight = (32 / inter.raydistance) * inter.projectplan;
		inter.top = (WIN_HEIGHT / 2) - (inter.wallstripheight / 2);
		if (inter.top < 0)
			inter.top = 0;
		inter.bottom = (WIN_HEIGHT / 2) + (inter.wallstripheight / 2);
		if (inter.bottom > WIN_HEIGHT)
			inter.bottom = WIN_HEIGHT;
		draw_wall(map, i, inter.top, inter.bottom);
		map->player.ray_angle += rangle;
		i++;
	}
	return (0);
}
