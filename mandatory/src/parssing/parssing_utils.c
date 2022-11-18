/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:32:17 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/18 18:32:19 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/* -------------------------------------------------------------------------- */

void	ft_free_table(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

/* -------------------------------------------------------------------------- */

void	ft_free_map_tables(t_root *root)
{
	if (root->map.texture)
		ft_free_table(root->map.texture);
	if (root->map.collor)
		ft_free_table(root->map.collor);
	if (root->map.content)
		ft_free_table(root->map.content);
	else
		return ;
}

/* -------------------------------------------------------------------------- */

void	ft_free_map_listes(t_root *root)
{
	ft_lstclear(&root->mheader, free);
	ft_lstclear(&root->mbody, free);
}

/* -------------------------------------------------------------------------- */

void	ft_error(char *str)
{
	printf("%sError%s\n%s\n", RED, RED, str);
	exit(1);
}

/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */