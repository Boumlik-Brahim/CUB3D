/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:57:25 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 18:11:05 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	long_len(t_map *map)
{
	int	long_len;
	int	len;

	long_len = 0;
	map->j = 0;
	while (map->content[map->j])
	{
		len = ft_strlen(map->content[map->j]);
		if (long_len < len)
			long_len = len;
		map->j++;
	}
	return (long_len);
}

void	paint_minimap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i >= 0 && i < 200)
	{
		j = 0;
		while (j >= 0 && j < 200)
			mlx_pixel_put(map->window.mlx, map->window.win, j++, i, 0xFFFFFF);
		++i;
	}
}

void	paint_win(t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = x;
	while (i >= 0 && i < y)
	{
		j = 0;
		while (j >= 0 && j < map->window.width * 32)
			mlx_pixel_put(map->window.mlx, map->window.win, j++, i, 0xA3C7D6);
		++i;
	}
}

void	draw_wall(t_map *map, int x, int y, int width_fi)
{
	int	j;

	j = y;
	while (j < width_fi)
		mlx_pixel_put(map->window.mlx, map->window.win, x, j++, 0x3F3BEE);
}

void	map_to_window(t_map *map, int x, int y, int add)
{
	int	i;
	int	j;

	i = y;
	while (i < y + add)
	{
		j = x;
		while (j < x + add)
		{
			if (j >= 0 && j < 200 && i >= 0 && i < 200)
				mlx_pixel_put(map->window.mlx,
					map->window.win, j, i, 0x3F3B6C);
			j++;
		}
		++i;
	}
}

void	where_player(t_map *map)
{
	map->j = 0;
	while (map->content[map->j])
	{
		map->i = 0;
		while (map->content[map->j][map->i])
		{
			if (map->content[map->j][map->i] == 'N')
			{
				map->window.player.posx = (double)map->i * 32;
				map->window.player.posy = (double)map->j * 32;
			}
			map->i++;
		}
		map->j++;
	}
}
