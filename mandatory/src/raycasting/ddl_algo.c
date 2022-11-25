/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddl_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:00:44 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/25 12:00:56 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	creatl_ddl_alg(t_root *root, double newposx, double newposy, int color)
{
	double	x;
	double	y;
	int		i;
	double	step;
	double	x_inc;
	double	y_inc;

	i = 1;
	y = 100;
	x = 100;
	root->player.deltax = newposx - 100;
	root->player.deltay = newposy - 100;
	if (fabs(root->player.deltax) > fabs(root->player.deltay))
		step = fabs(root->player.deltax);
	else
		step = fabs(root->player.deltay);
	x_inc = root->player.deltax / step;
	y_inc = root->player.deltay / step;
	while (i < step && x > 0 && y > 0 && x < 200 && y < 200)
	{
		img_pix_put(&root->window.img, round(x), round(y), color);
		x = x + x_inc;
		y = y + y_inc;
		i++;
	}
}