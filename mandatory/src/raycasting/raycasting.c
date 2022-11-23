/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:58 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/23 15:00:49 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	funct_ptr(int keycode, t_map *map)
{
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
	return (0);
}

int	funct_ptr_release(int keycode, t_map *map)
{
	if (keycode == 2 || keycode == 0)
		map->player.walkspeed = 0;
	if (keycode == 1 || keycode == 13)
		map->player.walkdir = 0;
	if (keycode == 124 || keycode == 123)
		map->player.turndir = 0;
	return (0);
}

int	ft_close(int keycode, t_map *map)
{
	map = 0;
	keycode = 0;
	exit(0);
}

int	handle_keypress(void *ptr)
{
	t_map *map;

	map = (t_map *)ptr;
	mlx_destroy_image(map->window.mlx, map->window.img.mlx_img);
	mlx_clear_window(map->window.mlx, map->window.win);
	map->window.img.mlx_img = mlx_new_image(map->window.mlx, WIN_WIDTH, WIN_HEIGHT);
	map->window.img.addr = mlx_get_data_addr(map->window.img.mlx_img,&map->window.img.bpp, &map->window.img.line_len, &map->window.img.endian);
	move_player(map);
	draw_background(map);
	add_tree_project_wall(map);
	mini_map(map);
	map_to_window(map, 100, 100, 1);
	mlx_put_image_to_window(map->window.mlx, map->window.win, map->window.img.mlx_img, 0, 0);
	return (0);
}

void	ft_find_pdirection(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
	{
		j = 0;
		while (map->content[i][j])
		{
			if (map->content[i][j] == 'N')
				map->player.rot_angle = M_PI / 2;
			if (map->content[i][j] == 'S')
				map->player.rot_angle = (3 * M_PI) / 2;
			if (map->content[i][j] == 'W')
				map->player.rot_angle = M_PI;
			if (map->content[i][j] == 'E')
				map->player.rot_angle = 2 * M_PI;
			j++;
		}
		i++;
	}
}

void	init_player(t_map *map)
{
	map->player.turndir = 0;
	map->player.walkdir = 0;
	map->player.walkspeed = 0;
	ft_find_pdirection(map);
	map->player.turnspeed = 4.0 * (M_PI / 180);
	map->player.fov_angle = 60 * (M_PI / 180);
	map->player.num_rays = WIN_WIDTH;

	map->rays.wall_hx = malloc(sizeof(double) * map->player.num_rays);
	map->rays.wall_hy = malloc(sizeof(double) * map->player.num_rays);
	map->rays.dis_h = malloc(sizeof(double) * map->player.num_rays);
	map->rays.wall_vx = malloc(sizeof(double) * map->player.num_rays);
	map->rays.wall_vy = malloc(sizeof(double) * map->player.num_rays);
	map->rays.dis_v = malloc(sizeof(double) * map->player.num_rays);
}

void	calcule_new_x_y(t_map *map)
{
	map->player.newx = map->player.posx - 100;
	map->player.newy = map->player.posy - 100;
}

void	where_player(t_map *map)
{
    int i;
    int j;

	j = 0;
	while (map->content[j])
	{
		i = 0;
		while (map->content[j][i])
		{
			if (map->content[j][i] == 'N' || map->content[j][i] == 'S' || map->content[j][i] == 'W' || map->content[j][i] == 'N')
			{
				map->player.posx = (double)i * 32;
				map->player.posy = (double)j * 32;
			}
			i++;
		}
		j++;
	}
}

void	mlx(t_map *map)
{
	map->window.mlx = mlx_init();
	map->window.win = mlx_new_window(map->window.mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	map->window.img.mlx_img = mlx_new_image(map->window.mlx, WIN_WIDTH, WIN_HEIGHT);
	map->window.img.addr = mlx_get_data_addr(map->window.img.mlx_img,&map->window.img.bpp, &map->window.img.line_len, &map->window.img.endian);
	where_player(map);
	calcule_new_x_y(map);
	init_player(map);
	mlx_hook(map->window.win, 17, 0, ft_close, (void *)map);
	mlx_hook(map->window.win, 03, 2L, funct_ptr_release, (void *)map);
	mlx_hook(map->window.win, 02, 1L, funct_ptr, (void *)map);
	mlx_loop_hook(map->window.mlx, &handle_keypress, (void *)map);
	mlx_loop(map->window.mlx);
}
