/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:42:24 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/25 19:18:53 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	init_inter(t_root *root)
{
	root->inter.xsteep = 0.0;
	root->inter.ysteep = 0.0;
	root->inter.x_intercet = 0.0;
	root->inter.y_intercet = 0.0;
	root->inter.raydistance = 0.0;
	root->inter.projectplan = 0.0;
	root->inter.wallstripheight = 0.0;
	root->inter.top = 0.0;
	root->inter.bottom = 0.0;
}

void	init_player(t_root *root)
{
	root->player.turndir = 0;
	root->player.walkdir = 0;
	root->player.walkspeed = 0;
	ft_find_pdirection(root);
	root->player.turnspeed = 4.0 * (M_PI / 180);
	root->player.fov_angle = 60 * (M_PI / 180);
	root->player.num_rays = WIN_WIDTH;

	root->player.posx = 0.0;
	root->player.posy = 0.0;
	root->player.deltax = 0.0;
	root->player.deltay = 0.0;
	root->player.newx = 0.0;
	root->player.newy = 0.0;
	root->player.ray_angle = 0.0;
	root->player.is_inth = 0;
	root->player.is_intv = 0;
	root->player.down = 0;
	root->player.up = 0;
	root->player.right = 0;
	root->player.left = 0;
}

void	init_data(t_root *root)
{
	init_player(root);
	init_inter(root);
}
