/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:26:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/25 19:26:40 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"


void	ckeck_hor_ver(t_root *root)
{
	double	pointx;
	double	pointy;

	pointx = 0.0;
	pointy = 0.0;
	
	if (root->player.is_intv == 1 && root->player.is_inth == 1)
	{
		if (root->rays.dis_v < root->rays.dis_h)
		{
			pointx = root->rays.wall_vx - root->player.newx;
			pointy = root->rays.wall_vy - root->player.newy;
		}
		else
		{
			pointx = root->rays.wall_hx - root->player.newx;
			pointy = root->rays.wall_hy - root->player.newy;
		}
	}
	else if (root->player.is_intv == 1 && root->player.is_inth == 0)
	{
		pointx = root->rays.wall_vx - root->player.newx;
		pointy = root->rays.wall_vy - root->player.newy;
	}
	else if (root->player.is_intv == 0 && root->player.is_inth == 1)
	{
		pointx = root->rays.wall_hx - root->player.newx;
		pointy = root->rays.wall_hy - root->player.newy;
	}
	creatl_ddl_alg(root, pointx, pointy, 0xD4D925);
}
