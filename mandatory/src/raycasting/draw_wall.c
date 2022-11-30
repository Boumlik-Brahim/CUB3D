/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:18:38 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/30 17:41:27 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

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

void	draw(t_root *root, int i)
{
	if (root->player.down == 1)
	{
		if (!offset_x(root, &root->window.tex1[0]))
			draw_wall(root, i, &root->window.tex1[0]);
	}
	else if (root->player.up == 1)
	{
		if (!offset_x(root, &root->window.tex1[3]))
			draw_wall(root, i, &root->window.tex1[3]);
	}
	if (root->player.left == 1)
	{
		if (offset_x(root, &root->window.tex1[2]))
			draw_wall(root, i, &root->window.tex1[2]);
	}
	else if (root->player.right == 1)
	{
		if (offset_x(root, &root->window.tex1[1]))
			draw_wall(root, i, &root->window.tex1[1]);
	}
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
		draw(root, i);
		root->player.ray_angle += root->player.fov_angle
			/ root->player.num_rays;
		i++;
	}
	return (0);
}
