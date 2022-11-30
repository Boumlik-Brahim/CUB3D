/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddl_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:00:44 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/30 21:25:09 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	creatl_dda_alg(t_root *root, double newposx, double newposy, int color)
{
	double	x;
	double	y;
	int		i;

	i = 1;
	y = 100;
	x = 100;
	root->player.deltax = newposx - 100;
	root->player.deltay = newposy - 100;
	if (fabs(root->player.deltax) > fabs(root->player.deltay))
		root->rays.step = fabs(root->player.deltax);
	else
		root->rays.step = fabs(root->player.deltay);
	root->rays.x_inc = root->player.deltax / root->rays.step;
	root->rays.y_inc = root->player.deltay / root->rays.step;
	while (i < root->rays.step && x > 0 && y > 0 && x < 200 && y < 200)
	{
		img_pix_put(&root->window.img, round(x), round(y), color);
		x = x + root->rays.x_inc;
		y = y + root->rays.y_inc;
		i++;
	}
}
