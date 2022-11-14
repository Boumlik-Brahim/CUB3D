/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:17:44 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/14 16:39:41 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

// int	ft_chk_ext(char *str, char	*ext)
// {
// 	char	*extntion;

// 	extntion = ft_strrchr(str, '.');
// 	if (!extntion || ft_strncmp(extntion, ext, 5))
// 		return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

// int	ft_col_len(t_root *root)
// {
// 	int	i;
// 	int	j;

// 	i = 5;
// 	while (root->map.data[++i])
// 	{
// 		j = 0;
// 		while (root->map.data[i][j])
// 			j++;
// 	}
// 	return (j);
// }

// int	ft_row_len(t_root *root)
// {
// 	int	i;
// 	int	j;

// 	i = 5;
// 	while (root->map.data[++i])
// 	{
// 		j = 0;
// 		while (root->map.data[i][j])
// 			j++;
// 	}
// 	return (i);
// }

// int	ft_chk_character(t_root *root)
// {
// 	int		i;
// 	int		j;

// 	i = 5;
// 	while (root->map.data[++i])
// 	{
// 		j = 0;
// 		while (root->map.data[i][j])
// 		{
// 			if (root->map.data[i][j] == '1' || root->map.data[i][j] == '0'
// 				|| root->map.data[i][j] == ' ' || root->map.data[i][j] == 'N'
// 				|| root->map.data[i][j] == 'S' || root->map.data[i][j] == 'E'
// 				|| root->map.data[i][j] == 'W')
// 				j++;
// 			else
// 				return (EXIT_FAILURE);
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }

// int	ft_chk_walls(t_root *root)
// {
// 	int		r;
// 	int		c;
// 	int		rl;
// 	int		cl;

// 	rl = ft_row_len(root);
// 	// cl = ft_col_len(root);
// 	r = 6;
// 	while (root->map.data[r] && r < rl)
// 	{
// 		c = 0;
// 		cl = ft_strlen(root->map.data[r]);
// 		while (root->map.data[r][c] && c < cl)
// 		{
// 			if ((root->map.data[6][c] != '1' && root->map.data[6][c] != ' ')
// 				|| (root->map.data[r][0] != '1' && root->map.data[r][0] != ' ')
// 				|| (root->map.data[r][cl - 1] != '1'
// 				&& root->map.data[r][cl - 1] != ' ')
// 				|| (root->map.data[rl - 1][c] != '1'
// 				&& root->map.data[rl - 1][c] != ' '))
// 				return (EXIT_FAILURE);
// 			c++;
// 		}
// 		r++;
// 	}
// 	return (EXIT_SUCCESS);
// }

// int	ft_chk_sp(t_root *root)
// {
// 	int		r;
// 	int		i;
// 	int		j;
// 	int		c;
// 	int		rl;
// 	char	**tmp;

// 	rl = ft_row_len(root);
// 	tmp = (char **)malloc(sizeof(char *) * (rl + 1));
// 	if (!tmp)
// 		return (EXIT_FAILURE);
// 	r = -1;
// 	i = -1;
// 	while (root->map.data[++r] && tmp[++i])
// 		tmp[i] = ft_strtrim(root->map.data[r], " ");
// 	tmp[i + 1] = NULL;
// 	j = 5;
// 	while (tmp[++j])
// 	{
// 		c = 0;
// 		while (tmp[j][c])
// 		{
// 			if (tmp[j][c] == ' ')
// 			{
// 				if ((tmp[j][c - 1] == '0' && tmp[j][c + 1] == '0')
// 					|| (tmp[j - 1][c] == '0' && tmp[j + 1][c] == '0'))
// 					return (EXIT_FAILURE);
// 			}
// 			c++;
// 		}
// 		// printf("\n");
// 	}
// 	return (EXIT_SUCCESS);
// }
