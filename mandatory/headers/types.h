/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:24:27 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/20 15:11:07 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "../../libs/Libft/libft.h"

/*---------------------------------raycasting---------------------------------*/
typedef struct s_player
{
	double		posx;
	double		posy;
	double		deltax;
	double		deltay;
	double		newx;
	double		newy;
	double		dis_h;
	double		dis_v;
	double		rot_angle;
	double		turnspeed;
	double		movespeed;
	double		ray_angle;
	double		wall_hx;
	double		wall_hy;
	double		wall_vx;
	double		wall_vy;
	double		fov_angle;
	int			is_inth;
	int			is_intv;
	int			walkspeed;
	int			walkdir;
	int			turndir;
	int			down;
	int			up;
	int			right;
	int			left;
	int			direction;
	int			num_rays;
}	t_player;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	int			*data;
}	t_window;

typedef struct s_inter
{
	double	xsteep;
	double	ysteep;
	double	x_intercet;
	double	y_intercet;
	double	raydistance;
	double	projectplan;
	double	wallstripheight;
	double	top;
	double	bottom;
}			t_inter;

/*---------------------------------raycasting---------------------------------*/

typedef struct s_map
{
	char		**texture;
	char		**collor;
	char		**content;

	int			i;
	int			j;
	int			len;
	int			count;
	t_player	player;
	t_window	window;

}	t_map;

typedef struct s_root
{
	t_map	map;
	t_list	*mheader;
	t_list	*mbody;
}	t_root;

#endif