/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:57:25 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/22 18:06:43 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*ytzad lcolor dyal lmap*/
void	draw_background(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < HALF_WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(&map->window.img, j++, i, 0x8758FF);
		++i;
	}
	i = HALF_WIN_HEIGHT;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(&map->window.img, j++, i, 0x003865);
		++i;
	}
}
