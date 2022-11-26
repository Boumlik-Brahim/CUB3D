/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:18:38 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/26 13:44:08 by zel-hach         ###   ########.fr       */
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

void	check_wall(t_root *root)
{
	while (!is_wall(root, root->inter.x_intercet, root->inter.y_intercet))
	{
		root->inter.x_intercet += root->inter.xsteep;
		root->inter.y_intercet += root->inter.ysteep;
	}
}


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

void	init_ray(t_root *root)
{
	root->player.down = 0;
	root->player.up = 0;
	root->player.left = 0;
	root->player.right = 0;
	root->rays.wall_hx = 0;
	root->rays.wall_hy = 0;
	root->rays.wall_vx = 0;
	root->rays.wall_vy = 0;
	root->rays.dis_v = 0;
	root->rays.dis_h = 0;
	check_angle(root);
}

int	add_tree_project_wall(t_root *root)
{
	int		i;
	double	rangle;
	double	coss;
	double	halfwallstripheight;

	i = 0;
	rangle = (root->player.fov_angle / root->player.num_rays);
	root->player.ray_angle = root->player.rot_angle - (root->player.fov_angle / 2);
	while (i < root->player.num_rays)
	{
		root->player.ray_angle = normalize_angle(root->player.ray_angle);
		init_ray(root);
		find_intersection_horiz(root);
		find_intersection_verticale(root);
		coss = cos(root->player.ray_angle - root->player.rot_angle);
		if (root->rays.dis_v < root->rays.dis_h)
			root->inter.raydistance = root->rays.dis_v * coss;
		else
			root->inter.raydistance = root->rays.dis_h * coss;
		root->inter.projectplan = HALF_WIN_WIDTH / tan(root->player.fov_angle / 2);
		root->inter.wallstripheight = (32 / root->inter.raydistance) * root->inter.projectplan;
		halfwallstripheight = (root->inter.wallstripheight / 2);
		root->inter.top = HALF_WIN_HEIGHT - halfwallstripheight;
		if (root->inter.top < 0)
			root->inter.top = 0;
		root->inter.bottom = HALF_WIN_HEIGHT + halfwallstripheight;
		if (root->inter.bottom > WIN_HEIGHT)
			root->inter.bottom = WIN_HEIGHT;
		put_texture(root);
		draw_wall(root, i);
		root->player.ray_angle += rangle;
		i++;
	}
	return (0);
}
