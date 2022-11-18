/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:14:06 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/18 14:40:14 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/* -------------------------------------------------------------------------- */

int	ft_chk_space(char *tmp)
{
	int	j;

	j = -1;
	while (tmp[++j])
	{
		if (tmp[j] == ' ' && ft_isdigit(tmp[j + 1]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */

int	ft_chk_num(char *color)
{
	int		i;
	char	*tmp;
	int		res;
	int		len;

	i = 0;
	len = ft_strlen(color);
	while (color[i])
	{
		if (color[i] == ' ' || ft_isalpha(color[i]) || color[i] == '.')
			i++;
		else
			break ;
	}
	tmp = ft_substr(color, i, (len - i));
	res = ft_atoi(tmp);
	if (res < 0 || res > 255 || ft_chk_space(tmp) != 0)
		return (EXIT_FAILURE);
	free(tmp);
	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */

int	ft_colortoint(char *color)
{
	char	**tmp;
	int		i;

	tmp = ft_split(color, ',');
	if (ft_colorlen(tmp) > 3)
	{
		ft_free_table(tmp);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (tmp[++i])
	{
		if (ft_chk_num(tmp[i]) != 0)
		{
			ft_free_table(tmp);
			return (EXIT_FAILURE);
		}
	}
	ft_free_table(tmp);
	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */

int	ft_chk_digit(char *color)
{
	int		i;
	int		clen;

	clen = ft_strlen(color);
	if (color[2] == ',' || color[clen - 1] == ',' || ft_colortoint(color))
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

/* -------------------------------------------------------------------------- */

int	ft_chk_color(char *color)
{
	if (!color)
		return (EXIT_FAILURE);
	if (!ft_strncmp(color, "F ", 2) || !ft_strncmp(color, "C ", 2))
	{
		if (!ft_chk_digit(color))
			return (EXIT_SUCCESS);
		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}

/* -------------------------------------------------------------------------- */