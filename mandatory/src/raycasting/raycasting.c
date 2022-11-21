/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:58 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/21 15:23:02 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

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
	mlx_hook(map->window.win, 17, 0, ft_close, (void *)map);
	mlx_hook(map->window.win, 02, 0L, funct_ptr, (void *)map);
	mlx_destroy_image(map->window.mlx, map->window.img.mlx_img);
	mlx_clear_window(map->window.mlx, map->window.win);
	map->window.img.mlx_img = mlx_new_image(map->window.mlx, WIN_WIDTH, WIN_HEIGHT);
	map->window.img.addr = mlx_get_data_addr(map->window.img.mlx_img,&map->window.img.bpp, &map->window.img.line_len, &map->window.img.endian);
	draw_background(map);
	add_tree_project_wall(map);
	mini_map(map);
	map_to_window(map, 100, 100, 4);
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
			{
				map->player.rot_angle = M_PI / 2;
			}
			if (map->content[i][j] == 'S')
			{
				map->player.rot_angle = (3 * M_PI) / 2;
			}
			if (map->content[i][j] == 'W')
			{
				map->player.rot_angle = M_PI;
			}
			if (map->content[i][j] == 'E')
			{
				map->player.rot_angle = 2 * M_PI;
			}
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
	// map->player.rot_angle = M_PI / 2;
	ft_find_pdirection(map);
	map->player.turnspeed = 4.0 * (M_PI / 180);
	map->player.fov_angle = 60 * (M_PI / 180);
	map->player.num_rays = WIN_WIDTH;
}

void	calcule_new_x_y(t_map *map)
{
	map->player.newx = map->player.posx - 100;
	map->player.newy = map->player.posy - 100;
}

/*edit where playeer*/
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
			if (ft_strchr("NSWE", map->content[j][i]))
			{
				map->player.posx = (double)i * 32;
				map->player.posy = (double)j * 32;
			}
			i++;
		}
		j++;
	}
}

/*delete win height and win width*/
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
	mlx_loop_hook(map->window.mlx, &handle_keypress, (void *)map);
	mlx_loop(map->window.mlx);
}