/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:17:44 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/06 17:39:20 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_chk_ext(char *str, char	*ext)
{
	char	*extntion;

	extntion = ft_strrchr(str, '.');
	if (!extntion || ft_strncmp(extntion, ext, 5))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// int	ft_chk_sp(t_root *root)
// {
// 	return (EXIT_SUCCESS);
// }
int	ft_col_len(t_root *root)
{
	int	i;
	int	j;

	i = 5;
	while (root->map.data[++i])
	{
		j = 0;
		while (root->map.data[i][j])
			j++;
	}
	return (j);
}

int	ft_row_len(t_root *root)
{
	int	i;
	int	j;

	i = 5;
	while (root->map.data[++i])
	{
		j = 0;
		while (root->map.data[i][j])
			j++;
	}
	return (i);
}

int	ft_chk_character(t_root *root)
{
	int		i;
	int		j;

	i = 5;
	while (root->map.data[++i])
	{
		j = 0;
		while (root->map.data[i][j])
		{
			if (root->map.data[i][j] == '1' || root->map.data[i][j] == '0'
				|| root->map.data[i][j] == ' ' || root->map.data[i][j] == 'N'
				|| root->map.data[i][j] == 'S' || root->map.data[i][j] == 'E'
				|| root->map.data[i][j] == 'W')
				j++;
			else
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_chk_walls(t_root *root)
{
	int		i;
	int		j;
	int		rl;
	int		cl;

	rl = ft_row_len(root);
	cl = ft_col_len(root);
	i = 5;
	printf("%s\n", root->map.data[6]);
	while (++i < rl)
	{
		j = 0;
		while (j < cl)
		{
			if (root->map.data[6][j] != ' ' || root->map.data[6][j] != '1'
				|| root->map.data[rl - 1][j] != ' '
				|| root->map.data[rl - 1][j] != '1')
				return (EXIT_FAILURE);
			j++;
		}
	}
	return (EXIT_SUCCESS);
}
