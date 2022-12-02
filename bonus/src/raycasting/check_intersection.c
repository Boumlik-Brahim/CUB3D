/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:26:52 by zel-hach          #+#    #+#             */
/*   Updated: 2022/12/02 11:44:50 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

double	dist_bet_posx_and_inter(t_root *root, double inter_x, double inter_y)
{
	double	x;
	double	y;
	double	res;

	x = (inter_x - root->player.posx) * (inter_x - root->player.posx);
	y = (inter_y - root->player.posy) * (inter_y - root->player.posy);
	res = x + y;
	return (sqrt(res));
}

void	new_pointx(t_root *root, double x, double y)
{
	double	pointx;
	double	pointy;

	pointx = x - root->player.newx;
	pointy = y - root->player.newy;
	creatl_dda_alg(root, pointx, pointy, 0x394e19);
}

void	ckeck_hor_ver(t_root *root)
{
	if (root->player.is_intv == 1 && root->player.is_inth == 1)
	{
		if (root->rays.dis_v < root->rays.dis_h)
			new_pointx(root, root->rays.wall_vx, root->rays.wall_vy);
		else
			new_pointx(root, root->rays.wall_hx, root->rays.wall_hy);
	}
	else if (root->player.is_intv == 1 && root->player.is_inth == 0)
		new_pointx(root, root->rays.wall_vx, root->rays.wall_vy);
	else if (root->player.is_intv == 0 && root->player.is_inth == 1)
		new_pointx(root, root->rays.wall_hx, root->rays.wall_hy);
}
