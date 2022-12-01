/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:15:21 by zel-hach          #+#    #+#             */
/*   Updated: 2022/12/01 13:45:16 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	check_angle(t_root *root)
{
	if (root->player.ray_angle >= 0 && root->player.ray_angle <= M_PI)
		root->player.down = 1;
	else
		root->player.up = 1;
	if (root->player.ray_angle <= M_PI_2 || root->player.ray_angle >= PI_5)
		root->player.right = 1;
	else
		root->player.left = 1;
}

double	normalize_angle(double angle)
{
	double	dblpi;

	dblpi = 2 * M_PI;
	angle = fmod(angle, dblpi);
	if (angle < 0)
		angle = dblpi + angle;
	return (angle);
}

void	move_player(t_root *root)
{
	double	posx;
	double	posy;
	double	angle;
	double	movestep;
	double	turndirspeed;

	if (root->player.walkdir != 0)
		movestep = root->player.walkdir * 4;
	if (root->player.walkspeed != 0)
		movestep = root->player.walkspeed * 4;
	angle = root->player.rot_angle + M_PI_2;
	turndirspeed = root->player.turndir * root->player.turnspeed;
	root->player.rot_angle += turndirspeed;
	angle = normalize_angle(angle);
	if (root->player.walkdir != 0)
		angle = normalize_angle(root->player.rot_angle);
	posx = root->player.posx + cos(angle) * movestep;
	posy = root->player.posy + sin(angle) * movestep;
	if (!is_wall_coll(root, posx, posy))
	{
		root->player.posx = posx;
		root->player.posy = posy;
	}
}
