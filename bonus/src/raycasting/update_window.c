/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:04:18 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/29 13:31:04 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	map_to_window(t_root *root, int x, int y, int color)
{
	int	i;
	int	j;

	i = y;
	while (i < y + root->player.add)
	{
		j = x;
		while (j < x + root->player.add)
		{
			if (j >= 0 && j < 200 && i >= 0 && i < 200)
				img_pix_put(&root->window.img, j, i, color);
			j++;
		}
		i++;
	}
}

void	update_win(t_root *root)
{
	int	i;
	int	j;

	j = 0;
	while (root->map.content[j])
	{
		i = 0;
		while (root->map.content[j][i])
		{
			root->player.add = 32;
			if (root->map.content[j][i] == '1')
				map_to_window(root, i * 32 - root->player.newx,
					j * 32 - root->player.newy, 0x3F3BEE);
			if (root->map.content[j][i] == '0')
				map_to_window(root, i * 32 - root->player.newx,
					j * 32 - root->player.newy, 0xFFFFFF);
			if (root->map.content[j][i] == 'N' || root->map.content[j][i] == 'S'
				|| root->map.content[j][i] == 'W'
				|| root->map.content[j][i] == 'E')
				root->map.content[j][i] = '0';
			i++;
		}
		j++;
	}
}
