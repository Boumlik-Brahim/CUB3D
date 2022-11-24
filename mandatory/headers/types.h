/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:24:27 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/24 21:27:15 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "../../libs/Libft/libft.h"

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

typedef struct s_rays
{
	double		*wall_hx;
	double		*wall_hy;
	double		*wall_vx;
	double		*wall_vy;
	double		*dis_v;
	double		*dis_h;
}	t_rays;

typedef struct s_player
{
	int			turndir;
	int			walkdir;
	int			walkspeed;
	double		rot_angle;
	double		turnspeed;
	double		fov_angle;
	int			num_rays;
	double		posx;
	double		posy;
	double		deltax;
	double		deltay;
	double		newx;
	double		newy;
	double		ray_angle;
	int			is_inth;
	int			is_intv;
	int			down;
	int			up;
	int			right;
	int			left;
	int			add;
}	t_player;

/*--------------------------------texture struct-----------------------------*/
typedef struct s_texture
{
	void	*texture1;
	void	*texture2;
	void	*texture3;
	void	*texture4;
	char	*addr1;
	char	*addr2;
	char	*addr3;
	char	*addr4;
	int		t_width;
	int		t_height;
	int		bpp;
	int		line_len;
	int		endian;
}			t_texture;
/*--------------------------------texture struct-----------------------------*/

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

	t_texture	tex;

}	t_window;

typedef struct s_map
{
	char		**texture;
	char		**collor;
	char		**content;
	int			floorcolor;
	int			ceillingcolor;
}	t_map;

typedef struct s_root
{
	t_list		*mheader;
	t_list		*mbody;
	t_map		map;
	t_window	window;
	t_player	player;
	t_rays		rays;
	t_inter		inter;

	double		x_text;
	double		y_text;

}	t_root;

#endif