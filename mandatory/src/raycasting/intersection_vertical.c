/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vertical.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:07:24 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/26 19:43:07 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	check_intersection_vertical(t_root *root)
{
	double	xwallhit;

	root->player.is_intv = 0;
	while (1)
	{
		xwallhit = root->inter.x_intercet;
		if (root->player.left == 1)
			xwallhit--;
		if (is_wall(root, xwallhit, root->inter.y_intercet))
		{
			root->player.is_intv = 1;
			root->rays.wall_vx = root->inter.x_intercet;
			root->rays.wall_vy = root->inter.y_intercet;
			break ;
		}
		else
		{
			root->inter.x_intercet += root->inter.xsteep;
			root->inter.y_intercet += root->inter.ysteep;
		}
	}
	root->rays.dis_v= dist_bet_posx_and_inter(root,
			root->rays.wall_vx, root->rays.wall_vy);
}

void	find_intersection_verticale(t_root *root)
{
	root->inter.x_intercet = floor(root->player.posx / 32) * 32;
	if (root->player.right == 1)
		root->inter.x_intercet += 32;
	root->inter.y_intercet = root->player.posy
		+ ((root->inter.x_intercet - root->player.posx)
			* tan(root->player.ray_angle));
	root->inter.xsteep = 32;
	if (root->player.left == 1)
		root->inter.xsteep *= -1;
	root->inter.ysteep = 32 * tan(root->player.ray_angle);
	if ((root->player.up == 1 && root->inter.ysteep > 0)
		|| (root->player.down == 1 && root->inter.ysteep < 0))
		root->inter.ysteep *= -1;
	check_intersection_vertical(root);
}
