/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_horizontal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:08:32 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/26 19:42:43 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	check_intersection_horiz(t_root *root)
{
	double	yhit_wall;

	root->player.is_inth = 0;
	while (1)
	{
		yhit_wall = root->inter.y_intercet;
		if (root->player.up == 1)
			yhit_wall--;
		if (is_wall(root, root->inter.x_intercet, yhit_wall))
		{
			root->player.is_inth = 1;
			root->rays.wall_hx = root->inter.x_intercet;
			root->rays.wall_hy = root->inter.y_intercet;
			break ;
		}
		else
		{
			root->inter.x_intercet += root->inter.xsteep;
			root->inter.y_intercet += root->inter.ysteep;
		}
	}
	root->rays.dis_h = dist_bet_posx_and_inter(root, root->rays.wall_hx,
			root->rays.wall_hy);
}

void	find_intersection_horiz(t_root *root)
{
	root->inter.y_intercet = floor(root->player.posy / 32) * 32;
	if (root->player.down == 1)
		root->inter.y_intercet += 32;
	root->inter.ysteep = 32;
	if (root->player.up == 1)
		root->inter.ysteep *= -1;
	root->inter.x_intercet = root->player.posx
		+ ((root->inter.y_intercet - root->player.posy)
			/ tan(root->player.ray_angle));
	root->inter.xsteep = root->inter.ysteep / tan(root->player.ray_angle);
	if ((root->player.left == 1 && root->inter.xsteep > 0)
		|| (root->player.right == 1 && root->inter.xsteep < 0))
		root->inter.xsteep *= -1;
	check_intersection_horiz(root);
}
