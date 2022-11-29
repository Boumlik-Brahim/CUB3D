/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:27:22 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/29 12:13:00 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/* -------------------------------------------------------------------------- */

static int	ft_chkm_content(char c)
{
	if (c != '1' && c != '0' && c != ' '
		&& c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */

static int	ft_chkmc_vertical(int r, int c, t_root *root)
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

static int	ft_chkmc_horizontal(int r, int c, t_root *root)
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

static void	ft_chk_player(t_root *root)
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
		ft_error("INVALID MAP BODY");
}

/* -------------------------------------------------------------------------- */

void	ft_chk_body_content(t_root *root)
{
	int		r;
	int		c;

	r = -1;
	while (root->map.content[++r])
	{
		c = 0;
		while (root->map.content[r][c])
		{
			if (ft_chkm_content(root->map.content[r][c]))
				ft_error("INVALID MAP BODY");
			if (ft_strchr("0NSWE", root->map.content[r][c]))
			{
				if (ft_chkmc_vertical(r, c, root)
					|| ft_chkmc_horizontal(r, c, root))
					ft_error("INVALID MAP BODY");
			}
			c++;
		}
	}
	ft_chk_player(root);
}

/* -------------------------------------------------------------------------- */