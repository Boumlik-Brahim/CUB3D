/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:26:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 18:14:06 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_close(int keycode, t_map *map)
{
	map = 0;
	keycode = 0;
	exit(0);
}

void	mini_map(t_map *map)
{
	calcule_new_x_y(map);
	paint_minimap(map);
	update_win(map);
	map_to_window(map, 100, 100, 4);
	create_angle(map);
}

void	calcule_new_x_y(t_map *map)
{
	map->window.player.newx = map->window.player.posx - 100;
	map->window.player.newy = map->window.player.posy - 100;
}

int	ft_strnum(char	**str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
            j++;
        i++;
	}
	return (i);
}

void	mlx(t_map *map)
{
	map->window.height = ft_strnum(map->content);
	map->window.width = long_len(map);
	map->window.mlx = mlx_init();
	map->window.win = mlx_new_window(map->window.mlx,
			map->window.width * 32, map->window.height * 32, "cub3D");
	where_player(map);
	calcule_new_x_y(map);
	init_player(&map->window);
	add_tree_project_wall(map);
	mini_map(map);
	mlx_hook(map->window.win, 02, 0L, funct_ptr, (void *)map);
	mlx_hook(map->window.win, 17, 0, ft_close, (void *)map);
	mlx_loop(map->window.mlx);
}