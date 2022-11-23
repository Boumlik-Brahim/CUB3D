/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:23:28 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/23 16:06:42 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/* -------------------------------------------------------------------------- */

int	ft_convert_color(char *color)
{
	char	*res;
	int		cval;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(color);
	while (color[i])
	{
		if (color[i] == ' ' || ft_isalpha(color[i]) || color[i] == '.')
			i++;
		else
			break ;
	}
	res = ft_substr(color, i, (len - i));
	cval = ft_atoi(res);
	free(res);
	return (cval);
}

int	ft_split_color(char *color)
{
	int		tab[3];
	char	**tmp;
	int		rescolor;

	tmp = ft_split(color, ',');
	tab[0] = ft_convert_color(tmp[0]);
	tab[1] = ft_convert_color(tmp[1]);
	tab[2] = ft_convert_color(tmp[2]);
	rescolor = (tab[0] << 16 | tab[1] << 8 | tab[2]);
	return (rescolor);
	ft_free_table(tmp);
}

void	ft_init_colors(t_root *root)
{
	int	r;

	r = -1;
	while (root->map.collor[++r])
	{
		if (!ft_strncmp(root->map.collor[r], "C ", 2))
			root->map.ceillingcolor = ft_split_color(root->map.collor[r]);
		else if (!ft_strncmp(root->map.collor[r], "F ", 2))
			root->map.floorcolor = ft_split_color(root->map.collor[r]);
	}
}

/* -------------------------------------------------------------------------- */