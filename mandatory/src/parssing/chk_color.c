/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:14:06 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/03 17:58:35 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_chk_digit(char *color)
{
	int	i;

	i = 2;
	while (color[i])
	{
		if (ft_isdigit(color[i]) || color[i] == ','
			|| color[i] == ' ' || color[i] == '.' || color[i] == '\t')
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
		printf("%d\n", ft_chk_digit(color));
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
