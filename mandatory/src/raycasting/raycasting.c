/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:58 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/23 18:38:37 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	funct_ptr(int keycode, t_root *root)
{
	if (keycode == RIGHT_KEY)
		root->player.walkspeed = 1;
	if (keycode == LEFT_KEY)
		root->player.walkspeed = -1;
	if (keycode == UP_KEY)
		root->player.walkdir = 1;
	if (keycode == DOWN_KEY)
		root->player.walkdir = -1;
	if (keycode == TURN_RIGHT)
		root->player.turndir = 1;
	if (keycode == TURN_LEFT)
		root->player.turndir = -1;
	if (keycode == ESC)
		ft_close(root);
	return (0);
}

int	funct_ptr_release(int keycode, t_root *root)
{
	if (keycode == RIGHT_KEY || keycode == LEFT_KEY)
		root->player.walkspeed = 0;
	if (keycode == DOWN_KEY || keycode == UP_KEY)
		root->player.walkdir = 0;
	if (keycode == TURN_RIGHT || keycode == TURN_LEFT)
		root->player.turndir = 0;
	return (0);
}

/*free data*/
int	ft_close(t_root *root)
{
	mlx_destroy_image(root->window.mlx, root->window.img.mlx_img);
	mlx_clear_window(root->window.mlx, root->window.win);
	exit(0);
}

int	handle_keypress(void *ptr)
{
	t_root	*root;

	root = (t_root *)ptr;
	mlx_destroy_image(root->window.mlx, root->window.img.mlx_img);
	mlx_clear_window(root->window.mlx, root->window.win);
	root->window.img.mlx_img = mlx_new_image(root->window.mlx,
			WIN_WIDTH, WIN_HEIGHT);
	root->window.img.addr = mlx_get_data_addr(root->window.img.mlx_img,
			&root->window.img.bpp, &root->window.img.line_len,
			&root->window.img.endian);
	move_player(root);
	draw_background(root);
	add_tree_project_wall(root);
	mini_map(root);
	map_to_window(root, 100, 100, 1);
	mlx_put_image_to_window(root->window.mlx, root->window.win,
		root->window.img.mlx_img, 0, 0);
	return (0);
}

void	ft_find_pdirection(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	while (root->map.content[i])
	{
		j = 0;
		while (root->map.content[i][j])
		{
			if (root->map.content[i][j] == 'N')
				root->player.rot_angle = M_PI / 2;
			if (root->map.content[i][j] == 'S')
				root->player.rot_angle = (3 * M_PI) / 2;
			if (root->map.content[i][j] == 'W')
				root->player.rot_angle = M_PI;
			if (root->map.content[i][j] == 'E')
				root->player.rot_angle = 2 * M_PI;
			j++;
		}
		i++;
	}
}

void	init_player(t_root *root)
{
	/*add init player*/
	root->player.turndir = 0;
	root->player.walkdir = 0;
	root->player.walkspeed = 0;
	ft_find_pdirection(root);
	root->player.turnspeed = 4.0 * (M_PI / 180);
	root->player.fov_angle = 60 * (M_PI / 180);
	root->player.num_rays = WIN_WIDTH;

	root->player.posx = 0.0;
	root->player.posy = 0.0;
	root->player.deltax = 0.0;
	root->player.deltay = 0.0;
	root->player.newx = 0.0;
	root->player.newy = 0.0;
	root->player.ray_angle = 0.0;
	root->player.is_inth = 0;
	root->player.is_intv = 0;
	root->player.down = 0;
	root->player.up = 0;
	root->player.right = 0;
	root->player.left = 0;
	/*add init inter*/
	root->inter.xsteep = 0.0;
	root->inter.ysteep = 0.0;
	root->inter.x_intercet = 0.0;
	root->inter.y_intercet = 0.0;
	root->inter.raydistance = 0.0;
	root->inter.projectplan = 0.0;
	root->inter.wallstripheight = 0.0;
	root->inter.top = 0.0;
	root->inter.bottom = 0.0;
	/*add init rays*/
	root->rays.wall_hx = malloc(sizeof(double) * root->player.num_rays);
	root->rays.wall_hy = malloc(sizeof(double) * root->player.num_rays);
	root->rays.dis_h = malloc(sizeof(double) * root->player.num_rays);
	root->rays.wall_vx = malloc(sizeof(double) * root->player.num_rays);
	root->rays.wall_vy = malloc(sizeof(double) * root->player.num_rays);
	root->rays.dis_v = malloc(sizeof(double) * root->player.num_rays);
}

void	calcule_new_x_y(t_root *root)
{
	root->player.newx = root->player.posx - 100;
	root->player.newy = root->player.posy - 100;
}

void	where_player(t_root *root)
{
	int	i;
	int	j;

	j = 0;
	while (root->map.content[j])
	{
		i = 0;
		while (root->map.content[j][i])
		{
			if (root->map.content[j][i] == 'N' || root->map.content[j][i] == 'S'
			|| root->map.content[j][i] == 'W' || root->map.content[j][i] == 'N')
			{
				root->player.posx = (double)i * 32;
				root->player.posy = (double)j * 32;
			}
			i++;
		}
		j++;
	}
}

void	ft_raycasting(t_root *root)
{
	root->window.mlx = mlx_init();
	root->window.win = mlx_new_window(root->window.mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	root->window.img.mlx_img = mlx_new_image(root->window.mlx,
			WIN_WIDTH, WIN_HEIGHT);
	root->window.img.addr = mlx_get_data_addr(root->window.img.mlx_img,
			&root->window.img.bpp, &root->window.img.line_len,
			&root->window.img.endian);
	init_player(root);
	where_player(root);
	calcule_new_x_y(root);
	mlx_hook(root->window.win, 17, 0, ft_close, (void *)root);
	mlx_hook(root->window.win, 03, 2L, funct_ptr_release, (void *)root);
	mlx_hook(root->window.win, 02, 1L, funct_ptr, (void *)root);
	mlx_loop_hook(root->window.mlx, &handle_keypress, (void *)root);
	mlx_loop(root->window.mlx);
}
