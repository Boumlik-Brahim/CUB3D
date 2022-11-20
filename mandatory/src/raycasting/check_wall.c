/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:26:39 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/20 20:40:59 by zel-hach         ###   ########.fr       */
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
