/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:57:25 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/21 09:08:24 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	draw_background(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		j = 0;
		while (j < WIN_WIDTH)
			mlx_pixel_put(map->window.mlx, map->window.win, j++, i, 0x8758FF);
		++i;
	}
	
	i = WIN_HEIGHT / 2;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			mlx_pixel_put(map->window.mlx, map->window.win, j++, i, 0x003865);
		++i;
	}
}
