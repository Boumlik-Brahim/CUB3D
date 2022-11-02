/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:13:40 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/02 18:29:12 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_txtchr(char *text)
{
	char	*res;

	res = ft_strtrim(text, " ");
	if (!ft_strncmp(res, "NO ", 3)
		|| !ft_strncmp(res, "SO ", 3)
		|| !ft_strncmp(res, "WE ", 3)
		|| !ft_strncmp(res, "EA ", 3)
		|| !ft_strncmp(res, "F ", 2)
		|| !ft_strncmp(res, "C ", 2))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_chk_texture(t_root *root)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (root->map.data[++i])
	{
		if (!ft_txtchr(root->map.data[i]))
			count++;
		else
			break ;
	}
	return (count);
}

void	ft_init_texture(t_root *root)
{
	if (ft_chk_texture(root) != 6)
		printf("\033[0;31mA INVALID TEXTURE\033[0;37m\n");
}
