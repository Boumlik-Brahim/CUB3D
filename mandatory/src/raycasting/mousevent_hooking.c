/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousevent_hooking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:56:31 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/25 20:28:05 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int on_mousemove(int x, int y, t_root *root)
{
    (void)y;
    if (root->isclick == true && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
    {
        if (root->oldx - x > 0)
		    root->player.rot_angle -= 0.05;
        else if (root->oldx - x < 0)
	    	root->player.rot_angle += 0.05;
        root->oldx = x;
    }
    return (0);
}

int on_mouseclick(int button, int x, int y, t_root *root)
{
    if (button == LEFT_CLICK && x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
    {
        root->isclick = true;
        root->oldx = x;
    }
    return (0);
}

int on_mousrelease(t_root *root)
{
    if (root->isclick == true)
        root->isclick = false;
    return (0);
}
