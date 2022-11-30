/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:34:24 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/30 20:43:00 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	texture(t_root *root, t_texture1 *tex, char *text)
{
	tex->texture1 = mlx_xpm_file_to_image(root->window.mlx,
			text,
			&tex->t_width1, &tex->t_height1);
	tex->addr1 = mlx_get_data_addr(tex->texture1, &tex->bpp,
			&tex->line_len, &tex->endian);
	free(text);
}

void	push_texture(t_root *root, int j)
{
	char	*text;

	if (ft_strncmp(root->map.texture[j], "SO", 2) == 0)
	{
		text = ft_strtrim(root->map.texture[j], "SO ");
		texture(root, &root->window.tex1[0], text);
	}
	if (ft_strncmp(root->map.texture[j], "WE", 2) == 0)
	{
		text = ft_strtrim(root->map.texture[j], "WE ");
		texture(root, &root->window.tex1[1], text);
	}
	if (ft_strncmp(root->map.texture[j], "EA", 2) == 0)
	{
		text = ft_strtrim(root->map.texture[j], "EA ");
		texture(root, &root->window.tex1[2], text);
	}
	if (ft_strncmp(root->map.texture[j], "NO", 2) == 0)
	{
		text = ft_strtrim(root->map.texture[j], "NO ");
		texture(root, &root->window.tex1[3], text);
	}
}

void	add_texture(t_root *root)
{
	int		j;

	j = 0;
	while (root->map.texture[j])
	{
		push_texture(root, j);
		j++;
	}
}
