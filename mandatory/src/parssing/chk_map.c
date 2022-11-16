/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:17:44 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/16 17:26:42 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_chk_map(char c)
{
	if (c != '1' && c != '0' && c != ' '
		&& c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_chkm_vertical(int r, int c, t_root *root)
{
	int	i;

	i = r + 1;
	while (root->map.content[i] && root->map.content[i][c] != '1')
	{
		if (root->map.content[i][c] != '0' && root->map.content[i][c] != 'N'
			&& root->map.content[i][c] != 'S' && root->map.content[i][c] != 'W'
			&& root->map.content[i][c] != 'E')
			return (EXIT_FAILURE);
		i++;
	}
	i = r;
	while (root->map.content[i] && root->map.content[i][c] != '1' && i >= 0)
	{
		if (root->map.content[i][c] != '0' && root->map.content[i][c] != 'N'
			&& root->map.content[i][c] != 'S' && root->map.content[i][c] != 'W'
			&& root->map.content[i][c] != 'E')
			return (EXIT_FAILURE);
		i--;
	}
	return (EXIT_SUCCESS);
}

int	ft_chkm_horizontal(int r, int c, t_root *root)
{
	int	j;

	j = c + 1;
	while (root->map.content[r][j] && root->map.content[r][j] != '1')
	{
		if (root->map.content[r][j] != '0' && root->map.content[r][j] != 'N'
			&& root->map.content[r][j] != 'S' && root->map.content[r][j] != 'W'
			&& root->map.content[r][j] != 'E')
			return (EXIT_FAILURE);
		j++;
	}
	j = c;
	while (root->map.content[r][j] && root->map.content[r][j] != '1' && j >= 0)
	{
		if (root->map.content[r][j] != '0' && root->map.content[r][j] != 'N'
			&& root->map.content[r][j] != 'S' && root->map.content[r][j] != 'W'
			&& root->map.content[r][j] != 'E')
			return (EXIT_FAILURE);
		j--;
	}
	return (EXIT_SUCCESS);
}

void	ft_chk_player(t_root *root)
{
	int	r;
	int	c;
	int	count;

	count = 0;
	r = -1;
	while (root->map.content[++r])
	{
		c = 0;
		while (root->map.content[r][c])
		{
			if (root->map.content[r][c] == 'N' || root->map.content[r][c] == 'S'
				|| root->map.content[r][c] == 'W'
				|| root->map.content[r][c] == 'E')
				count++;
			c++;
		}
	}
	if (count != 1)
		put_errors("INVALID MAP BODY");
}
