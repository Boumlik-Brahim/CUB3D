/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:18:38 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/26 21:06:07 by zel-hach         ###   ########.fr       */
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

void	calcule_wallheight(t_root *root)
{
	root->inter.projectplan = HALF_WIN_WIDTH
		/ tan(root->player.fov_angle / 2);
	root->inter.wallstripheight = (32 / root->inter.raydistance)
		* root->inter.projectplan;
	root->inter.top = HALF_WIN_HEIGHT - (root->inter.wallstripheight / 2);
	if (root->inter.top < 0)
		root->inter.top = 0;
	root->inter.bottom = HALF_WIN_HEIGHT + (root->inter.wallstripheight / 2);
	if (root->inter.bottom > WIN_HEIGHT)
		root->inter.bottom = WIN_HEIGHT;
}

void	cast(t_root *root)
{
	init_ray(root);
	find_intersection_horiz(root);
	find_intersection_verticale(root);
}

void	fish_bowl(t_root *root)
{
	if (root->rays.dis_v < root->rays.dis_h)
		root->inter.raydistance = root->rays.dis_v
			* cos(root->player.ray_angle - root->player.rot_angle);
	else
		root->inter.raydistance = root->rays.dis_h
			* cos(root->player.ray_angle - root->player.rot_angle);
}

int	add_tree_project_wall(t_root *root)
{
	int		i;

	i = 0;
	root->player.ray_angle = root->player.rot_angle
		- (root->player.fov_angle / 2);
	while (i < root->player.num_rays)
	{
		root->player.ray_angle = normalize_angle(root->player.ray_angle);
		cast(root);
		fish_bowl(root);
		calcule_wallheight(root);
		root->rays.is_vertical = false;
		put_texture(root);
		draw_wall(root, i);
		root->player.ray_angle += root->player.fov_angle
			/ root->player.num_rays;
		i++;
	}
	return (0);
}
