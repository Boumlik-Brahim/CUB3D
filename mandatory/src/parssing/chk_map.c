/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:17:44 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/17 15:36:59 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/* -------------------------------------------------------------------------- */

int	ft_chkm_content(char c)
{
	if (c != '1' && c != '0' && c != ' '
		&& c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */

int	ft_chkmc_vertical(int r, int c, t_root *root)
{
	int	i;

	i = r;
	while (root->map.content[i] && root->map.content[i][c] != '1')
	{
		if (root->map.content[i][c] != '0' && root->map.content[i][c] != 'N'
			&& root->map.content[i][c] != 'S' && root->map.content[i][c] != 'W'
			&& root->map.content[i][c] != 'E')
			return (EXIT_FAILURE);
		i++;
	}
	if (!root->map.content[i])
		return (EXIT_FAILURE);
	i = r;
	while (root->map.content[i] && root->map.content[i][c] != '1' && i > 0)
	{
		if (root->map.content[i][c] != '0' && root->map.content[i][c] != 'N'
			&& root->map.content[i][c] != 'S' && root->map.content[i][c] != 'W'
			&& root->map.content[i][c] != 'E')
			return (EXIT_FAILURE);
		i--;
	}
	if (root->map.content[i][c] != '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */

int	ft_chkmc_horizontal(int r, int c, t_root *root)
{
	int	j;

	j = c;
	while (root->map.content[r][j] && root->map.content[r][j] != '1')
	{
		if (root->map.content[r][j] != '0' && root->map.content[r][j] != 'N'
			&& root->map.content[r][j] != 'S' && root->map.content[r][j] != 'W'
			&& root->map.content[r][j] != 'E')
			return (EXIT_FAILURE);
		j++;
	}
	if (root->map.content[r][j] != '1')
		return (EXIT_FAILURE);
	j = c;
	while (root->map.content[r][j] && root->map.content[r][j] != '1' && j > 0)
	{
		if (root->map.content[r][j] != '0' && root->map.content[r][j] != 'N'
			&& root->map.content[r][j] != 'S' && root->map.content[r][j] != 'W'
			&& root->map.content[r][j] != 'E')
			return (EXIT_FAILURE);
		j--;
	}
	if (root->map.content[r][j] != '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */