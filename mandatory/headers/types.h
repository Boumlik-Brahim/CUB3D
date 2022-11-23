/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:24:27 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/23 15:02:18 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "../../libs/Libft/libft.h"

/*---------------------------------raycasting---------------------------------*/
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

typedef struct s_player
{
	double		posx;
	double		posy;
	double		deltax;
	double		deltay;
	double		newx;
	double		newy;
	double		rot_angle;
	double		turnspeed;
	double		ray_angle;
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
	int			num_rays;
}	t_player;

typedef struct s_rays
{
	double		*wall_hx;
	double		*wall_hy;
	double		*wall_vx;
	double		*wall_vy;
	double		*dis_v;
	double		*dis_h;
} t_rays;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_img		img;
}	t_window;

/*---------------------------------raycasting---------------------------------*/

typedef struct s_map
{
	char		**texture;
	char		**collor;
	char		**content;

	t_player	player;
	t_window	window;
	t_rays		rays;

}	t_map;

typedef struct s_root
{
	t_list	*mheader;
	t_list	*mbody;
	t_map	map;

	// t_player	player;
	// t_window	window;
	// t_rays		rays;
}	t_root;

#endif