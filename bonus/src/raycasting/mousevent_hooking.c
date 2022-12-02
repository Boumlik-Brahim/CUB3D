/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousevent_hooking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:56:31 by bbrahim           #+#    #+#             */
/*   Updated: 2022/12/02 11:03:43 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	on_mousemove(int x, int y, void *param)
{
	t_root	*root;

	root = (t_root *)param;
	(void)y;
	if (root->window.isclick == true && x < WIN_WIDTH
		&& y > 0 && y < WIN_HEIGHT)
	{
		if ((root->window.oldx - x) > 0)
				root->player.rot_angle -= 0.05;
		else if ((root->window.oldx - x) < 0)
				root->player.rot_angle += 0.05;
		root->window.oldx = x;
	}
	return (0);
}

int	on_mouseclick(int button, int x, int y, void *param)
{
	t_root	*root;

	root = (t_root *)param;
	if ((button == LEFT_CLICK) && (x > 0)
		&& (x < WIN_WIDTH) && (y > 0) && (y < WIN_HEIGHT))
	{
		root->window.isclick = true;
		root->window.oldx = x;
	}
	return (0);
}

int	on_mousrelease(int button, int x, int y, void *param)
{
	t_root	*root;

	(void)button;
	(void)x;
	(void)y;
	root = (t_root *)param;
	if (root->window.isclick == true)
		root->window.isclick = false;
	return (0);
}
