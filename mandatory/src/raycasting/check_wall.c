/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:44:44 by zel-hach          #+#    #+#             */
/*   Updated: 2022/12/01 13:46:24 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	ft_chkzero_vertical(int r, int c, t_root *root)
{
	int	i;

	i = r + 1;
	if (root->map.content[i][c] && root->map.content[i][c] == '1')
		return (EXIT_FAILURE);
	i = r - 1;
	if (root->map.content[i][c] && root->map.content[i][c] == '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_chkzero_horizontal(int r, int c, t_root *root)
{
	int	j;

	j = c + 1;
	if (root->map.content[r][j] && root->map.content[r][j] == '1')
		return (EXIT_FAILURE);
	j = c - 1;
	if (root->map.content[r][j] && root->map.content[r][j] == '1')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	replace(t_root *root)
{
	int	j;
	int	i;

	i = 0;
	while (root->map.content[i])
	{
		j = 0;
		while (root->map.content[i][j])
		{
			if (root->map.content[i][j] == '0' || root->map.content[i][j] == 'N'
			|| root->map.content[i][j] == 'S' || root->map.content[i][j] == 'E'
			||root->map.content[i][j] == 'W')
			{
				if (ft_chkzero_horizontal(i, j, root)
					&& ft_chkzero_vertical(i, j, root))
						root->map.content[i][j] = '2';
			}
			j++;
		}
		i++;
	}
}

int	is_wall(t_root *root, int x, int y)
{
	int	mapgrid_x;
	int	mapgrid_y;
	int	i;
	int	j;

	mapgrid_x = (x / 32);
	mapgrid_y = (y / 32);
	i = 0;
	while (root->map.content[i])
		i++;
	if (mapgrid_y < 0 || mapgrid_y >= i)
		return (1);
	j = ft_strlen(root->map.content[mapgrid_y]);
	if (mapgrid_x > j || mapgrid_x < 0
		|| root->map.content[mapgrid_y][mapgrid_x] == '1'
		|| root->map.content[mapgrid_y][mapgrid_x] == ' ')
		return (1);
	return (0);
}

int	is_wall_coll(t_root *root, int x, int y)
{
	int	mapgrid_x;
	int	mapgrid_y;
	int	i;
	int	j;

	mapgrid_x = (x / 32);
	mapgrid_y = (y / 32);
	i = 0;
	while (root->map.content[i])
		i++;
	if (mapgrid_y < 0 || mapgrid_y >= i)
		return (1);
	j = ft_strlen(root->map.content[mapgrid_y]);
	if (mapgrid_x > j || mapgrid_x < 0
		|| root->map.content[mapgrid_y][mapgrid_x] == '1'
		|| root->map.content[mapgrid_y][mapgrid_x] == ' '
		|| (root->map.content[(int )(root->player.posy / 32)] \
		[(int)(root->player.posx / 32)] == '2'
		&& root->map.content[mapgrid_y][mapgrid_x] == '2'
		&& (int)(root->player.posy / 32) != mapgrid_y
		&& (int)(root->player.posx / 32) != mapgrid_x))
		return (1);
	return (0);
}
