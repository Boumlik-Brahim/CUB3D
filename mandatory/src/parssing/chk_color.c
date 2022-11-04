/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:14:06 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/04 11:49:05 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_colorlen(char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (tmp[++i])
	{
		j = 0;
		while (tmp[i][j])
			j++;
	}
	return (i);
}

int	ft_colortoint(char **tmp)
{
	int		i;
	int		color;

	i = 1;
	while (tmp[i])
	{
		color = ft_atoi(tmp[i]);
		if (color < 0 || color > 255)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_chk_digit(char *color)
{
	int		i;
	int		clen;
	char	**tmp;

	clen = ft_strlen(color);
	tmp = ft_split(color, ',');
	printf("%d\n", ft_colortoint(tmp));
	if (color[2] == ',' || color[clen - 1] == ',' || ft_colorlen(tmp) > 3)
		return (EXIT_FAILURE);
	i = 2;
	while (color[i])
	{
		if (color[i] == ' ' || ft_isdigit(color[i])
			|| (color[i] == ',' && color[i + 1] != ',')
			|| color[i] == '.')
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_colorchr(char *color)
{
	if (!ft_strncmp(color, "F ", 2) || !ft_strncmp(color, "C ", 2))
	{
		ft_chk_digit(color);
		// printf("%d\n", ft_chk_digit(color));
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	ft_init_array_collor(t_root *root)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = 0;
	root->map.collor = (char **)malloc(sizeof(char *) * 3);
	if (!root->map.collor)
		return ;
	while (root->map.data[++i])
	{
		res = ft_strtrim(root->map.data[i], " ");
		if (!ft_colorchr(res))
		{
			root->map.collor[j] = ft_strdup(res);
			j++;
		}
	}
	root->map.collor[j] = NULL;
}
