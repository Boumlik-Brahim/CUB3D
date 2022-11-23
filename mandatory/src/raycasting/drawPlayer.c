/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:57:25 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/23 16:08:43 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	draw_background(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	while (i < HALF_WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(&root->window.img, j++, i, root->map.ceillingcolor);
		++i;
	}
	i = HALF_WIN_HEIGHT;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			img_pix_put(&root->window.img, j++, i, root->map.floorcolor);
		++i;
	}
}
