/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:58 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/29 20:10:32 by zel-hach         ###   ########.fr       */
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

void	ft_raycasting(t_root *root)
{
	root->window.mlx = mlx_init();
	root->window.win = mlx_new_window(root->window.mlx,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	root->window.tex1 = malloc(sizeof(t_texture1) * 4);
	add_texture(root);
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
	mlx_hook(root->window.win, 04, (1L << 8), on_mouseclick, (void *)root);
	mlx_hook(root->window.win, 06, (1L << 8), on_mousemove, (void *)root);
	mlx_hook(root->window.win, 05, (1L << 6), on_mousrelease, (void *)root);
	mlx_loop_hook(root->window.mlx, &handle_keypress, (void *)root);
	mlx_loop(root->window.mlx);
}
