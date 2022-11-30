/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:02:00 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/30 17:49:28 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	calcule_new_x_y(t_root *root)
{
	root->player.newx = root->player.posx - 100;
	root->player.newy = root->player.posy - 100;
}

void	where_player(t_root *root)
{
	int	i;
	int	j;

	j = 0;
	while (root->map.content[j])
	{
		i = 0;
		while (root->map.content[j][i])
		{
			if (root->map.content[j][i] == 'N' || root->map.content[j][i] == 'S'
			|| root->map.content[j][i] == 'W' || root->map.content[j][i] == 'E')
			{
				root->player.posx = (double)i * 32;
				root->player.posy = (double)j * 32;
			}
			i++;
		}
		j++;
	}
}

void	create_angle(t_root *root)
{
	int		i;
	double	rangle;

	i = 0;
	rangle = (root->player.fov_angle / root->player.num_rays);
	root->player.ray_angle = root->player.rot_angle
		- (root->player.fov_angle / 2);
	while (i < root->player.num_rays)
	{
		root->player.ray_angle = normalize_angle(root->player.ray_angle);
		cast(root);
		ckeck_hor_ver(root);
		root->player.ray_angle += rangle;
		i++;
	}
}

void	paint_minimap(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	while (i >= 0 && i < 200)
	{
		j = 0;
		while (j >= 0 && j < 200)
			img_pix_put(&root->window.img, j++, i, 0x000000);
		i++;
	}
}

void	mini_map(t_root *root)
{
	calcule_new_x_y(root);
	paint_minimap(root);
	update_win(root);
	create_angle(root);
	root->player.add = 1;
	map_to_window(root, 100, 100, 0x3F3BEE);
}
