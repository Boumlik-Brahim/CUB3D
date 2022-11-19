/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:26:39 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/19 18:11:05 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../headers/cub3d.h"

int	is_wall(t_map *map, int x, int y)
{
	double	mapgrid_x;
	double	mapgrid_y;

	if (x > map->window.width * 32 || x < 0
		|| y < 0 || y > map->window.height * 32)
		return (1);
	mapgrid_x = floor(x / 32);
	mapgrid_y = floor(y / 32);
	map->j = 0;
	while (map->content[map->j])
	{
		map->i = 0;
		while (map->content[map->j][map->i])
		{
			if (map->content[map->j][map->i] != '0' && map->j == mapgrid_y
				&& map->i == mapgrid_x)
				return (1);
			map->i++;
		}
		map->j++;
	}
	return (0);
}
