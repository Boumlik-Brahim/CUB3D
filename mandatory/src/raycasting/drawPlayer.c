/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:57:25 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/21 21:02:22 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*WIN_HEIGHT / 2 ====> 300*/
void	draw_background(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 300)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(&map->window.img, j++, i, 0x8758FF);
		++i;
	}

	i = WIN_HEIGHT / 2;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(&map->window.img, j++, i, 0x003865);
		++i;
	}
}
