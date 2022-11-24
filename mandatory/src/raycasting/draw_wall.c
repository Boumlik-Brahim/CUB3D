/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:18:38 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/24 10:30:31 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	draw_wall(t_root *root, int x, int y, int width_fi)
{
	int	j;

	j = y;
	while (j < width_fi)
	{
		img_pix_put(&root->window.img, x, j, 0x3F3BEE);
		j++;
	}
}

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

void	check_intersection_vertical(t_root *root, int id)
{
	check_wall(root);
	root->player.is_intv = 1;
	root->rays.wall_vx[id] = root->inter.x_intercet;
	root->rays.wall_vy[id] = root->inter.y_intercet;
	root->rays.dis_v[id] = dist_bet_posx_and_inter(root,
			root->rays.wall_vx[id], root->rays.wall_vy[id]);
}

void	find_intersection_verticale(t_root *root, int id)
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
	if ((root->player.down == 1 && root->inter.ysteep > 0)
		|| (root->player.up == 1 && root->inter.ysteep < 0))
		root->inter.ysteep *= -1;
	if (root->player.left == 1)
		root->inter.x_intercet--;
	root->player.is_intv = 0;
	check_intersection_vertical(root, id);
}

void	check_intersection_horiz(t_root *root, int id)
{
	check_wall(root);
	root->player.is_inth = 1;
	root->rays.wall_hx[id] = root->inter.x_intercet;
	root->rays.wall_hy[id] = root->inter.y_intercet;
	root->rays.dis_h[id] = dist_bet_posx_and_inter(root, root->rays.wall_hx[id],
			root->rays.wall_hy[id]);
}

void	find_intersection_horiz(t_root *root,int	id)
{
	root->inter.y_intercet = floor(root->player.posy / 32) * 32;
	if (root->player.up == 1)
		root->inter.y_intercet += 32;
	root->inter.ysteep = 32;
	if (root->player.down == 1)
		root->inter.ysteep *= -1;
	root->inter.x_intercet = root->player.posx
		+ ((root->inter.y_intercet - root->player.posy)
			/ tan(root->player.ray_angle));
	root->inter.xsteep = root->inter.ysteep / tan(root->player.ray_angle);
	if ((root->player.left == 1 && root->inter.xsteep > 0)
		|| (root->player.right == 1 && root->inter.xsteep < 0))
		root->inter.xsteep *= -1;
	if (root->player.down == 1)
			root->inter.y_intercet--;
	root->player.is_inth = 0;
	check_intersection_horiz(root, id);
}

void	check_angle(t_root *root)
{
	if (root->player.ray_angle >= 0 && root->player.ray_angle <= M_PI)
		root->player.up = 1;
	else
		root->player.down = 1;
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
	check_angle(root);
}

/*rays allocation was here*/
int	add_tree_project_wall(t_root *root)
{
	int		i;
	double	rangle;
	double	coss;
	double	halfwallstripheight;

	i = 0;
	rangle = (root->player.fov_angle / root->player.num_rays);
	root->player.ray_angle = root->player.rot_angle
		- (root->player.fov_angle / 2);
	while (i < root->player.num_rays)
	{
		root->player.ray_angle = normalize_angle(root->player.ray_angle);
		init_ray(root);
		find_intersection_horiz(root, i);
		find_intersection_verticale(root, i);
		coss = cos(root->player.ray_angle - root->player.rot_angle);
		if (root->rays.dis_v[i] < root->rays.dis_h[i])
			root->inter.raydistance = root->rays.dis_v[i] * coss;
		else
			root->inter.raydistance = root->rays.dis_h[i] * coss;
		root->inter.projectplan = HALF_WIN_WIDTH
			/ tan(root->player.fov_angle / 2);
		root->inter.wallstripheight = (32 / root->inter.raydistance)
			* root->inter.projectplan;
		halfwallstripheight = (root->inter.wallstripheight / 2);
		root->inter.top = HALF_WIN_HEIGHT - halfwallstripheight;
		if (root->inter.top < 0)
			root->inter.top = 0;
		root->inter.bottom = HALF_WIN_WIDTH + halfwallstripheight;
		if (root->inter.bottom > WIN_HEIGHT)
			root->inter.bottom = WIN_HEIGHT;
		draw_wall(root, i, root->inter.top, root->inter.bottom);
		// draw_wall(root, i);
		root->player.ray_angle += rangle;
		i++;
	}
	return (0);
}
