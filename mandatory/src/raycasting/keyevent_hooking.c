/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent_hooking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:06:49 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/25 19:17:47 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"


int	ft_close(t_root *root)
{
	mlx_destroy_image(root->window.mlx, root->window.img.mlx_img);
	mlx_clear_window(root->window.mlx, root->window.win);
	exit(0);
}

int	funct_ptr(int keycode, t_root *root)
{
	if (keycode == RIGHT_KEY)
		root->player.walkspeed = 1;
	if (keycode == LEFT_KEY)
		root->player.walkspeed = -1;
	if (keycode == UP_KEY)
		root->player.walkdir = 1;
	if (keycode == DOWN_KEY)
		root->player.walkdir = -1;
	if (keycode == TURN_RIGHT)
		root->player.turndir = 1;
	if (keycode == TURN_LEFT)
		root->player.turndir = -1;
	if (keycode == ESC)
		ft_close(root);
	return (0);
}

int	funct_ptr_release(int keycode, t_root *root)
{
	if (keycode == RIGHT_KEY || keycode == LEFT_KEY)
		root->player.walkspeed = 0;
	if (keycode == DOWN_KEY || keycode == UP_KEY)
		root->player.walkdir = 0;
	if (keycode == TURN_RIGHT || keycode == TURN_LEFT)
		root->player.turndir = 0;
	return (0);
}
