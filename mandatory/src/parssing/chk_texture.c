/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:13:40 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/13 13:07:16 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// int	ft_txtchr(char *text)
// {
// 	if (!ft_strncmp(text, "NO ", 3) || !ft_strncmp(text, "SO ", 3)
// 		|| !ft_strncmp(text, "WE ", 3) || !ft_strncmp(text, "EA ", 3))
// 	{
// 		if (!ft_chk_ext(text, ".xpm"))
// 			return (EXIT_SUCCESS);
// 	}
// 	return (EXIT_FAILURE);
// }

void	ft_init_array_texture(t_root *root)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = 0;
	root->map.texture = (char **)malloc(sizeof(char *) * 5);
	if (!root->map.texture)
		return ;
	while (root->map.data[++i])
	{
		res = ft_strtrim(root->map.data[i], " ");
		if (!ft_chk_txt(res))
		{
			root->map.texture[j] = ft_strdup(res);
			j++;
		}
	}
	root->map.texture[j] = NULL;
}

int	ft_chk_texture(t_root *root)
{
	int		i;
	int		count;
	char	*res;

	i = -1;
	count = 0;
	while (root->map.data[++i])
	{
		res = ft_strtrim(root->map.data[i], " ");
		if (!ft_chk_txt(res) || !ft_chk_color(res))
			count++;
		else
			break ;
	}
	return (count);
}

void	ft_init_texture(t_root *root)
{
	// int	i;

	if (ft_chk_texture(root) != 6)
	{
		printf("\033[0;31mA INVALID TEXTURE\033[0;37m\n");
		return ;
	}
	// printf("characters====> %d\n", ft_chk_character(root));
	// printf("walls====> %d\n", ft_chk_walls(root));
	// ft_chk_sp(root);
	// printf("space====> %d\n", ft_chk_sp(root));
	// ft_init_array_texture(root);
	// i = -1;
	// while (root->map.texture[++i])
	// 	printf("%s\n", root->map.texture[i]);
	// ft_init_array_collor(root);
	// i = -1;
	// while (root->map.collor[++i])
	// 	printf("%s\n", root->map.collor[i]);
}
