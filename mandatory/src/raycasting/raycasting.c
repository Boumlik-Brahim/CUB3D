/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:58 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/24 21:30:10 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	handle_keypress(void *ptr)
{
	t_root	*root;

	root = (t_root *)ptr;
	mlx_destroy_image(root->window.mlx, root->window.img.mlx_img);
	mlx_clear_window(root->window.mlx, root->window.win);
	root->window.img.mlx_img = mlx_new_image(root->window.mlx,
			WIN_WIDTH, WIN_HEIGHT);
	root->window.img.addr = mlx_get_data_addr(root->window.img.mlx_img,
			&root->window.img.bpp, &root->window.img.line_len,
			&root->window.img.endian);
	move_player(root);
	draw_background(root);
	add_tree_project_wall(root);
	mini_map(root);
	root->player.add = 1;
	map_to_window(root, 100, 100, 0x3F3BEE);
	mlx_put_image_to_window(root->window.mlx, root->window.win,
		root->window.img.mlx_img, 0, 0);
	return (0);
}

void	ft_find_pdirection(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	while (root->map.content[i])
	{
		j = 0;
		while (root->map.content[i][j])
		{
			if (root->map.content[i][j] == 'N')
				root->player.rot_angle = M_PI / 2;
			if (root->map.content[i][j] == 'S')
				root->player.rot_angle = (3 * M_PI) / 2;
			if (root->map.content[i][j] == 'W')
				root->player.rot_angle = M_PI;
			if (root->map.content[i][j] == 'E')
				root->player.rot_angle = 2 * M_PI;
			j++;
		}
		i++;
	}
}

void	calcule_new_x_y(t_root *root)
{
	root->player.newx = root->player.posx - 100;
	root->player.newy = root->player.posy - 100;
}

void	where_player(t_root *root)
{
	int	i;
	int	j;

	j = 0;
	while (root->map.content[j])
	{
		i = 0;
		while (root->map.content[j][i])
		{
			if (root->map.content[j][i] == 'N' || root->map.content[j][i] == 'S'
			|| root->map.content[j][i] == 'W' || root->map.content[j][i] == 'N')
			{
				root->player.posx = (double)i * 32;
				root->player.posy = (double)j * 32;
			}
			i++;
		}
		j++;
	}
}

void	ft_raycasting(t_root *root)
{
	root->window.mlx = mlx_init();
	root->window.win = mlx_new_window(root->window.mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	add_texture(root);
	// mlx_put_image_to_window(root->window.mlx, root->window.win, root->window.tex.texture1,0,0);
	root->window.img.mlx_img = mlx_new_image(root->window.mlx,
			WIN_WIDTH, WIN_HEIGHT);
	root->window.img.addr = mlx_get_data_addr(root->window.img.mlx_img,
			&root->window.img.bpp, &root->window.img.line_len,
			&root->window.img.endian);
	init_data(root);
	where_player(root);
	calcule_new_x_y(root);
	mlx_hook(root->window.win, 17, 0, ft_close, (void *)root);
	mlx_hook(root->window.win, 03, 2L, funct_ptr_release, (void *)root);
	mlx_hook(root->window.win, 02, 1L, funct_ptr, (void *)root);
	mlx_loop_hook(root->window.mlx, &handle_keypress, (void *)root);
	mlx_loop(root->window.mlx);
}
