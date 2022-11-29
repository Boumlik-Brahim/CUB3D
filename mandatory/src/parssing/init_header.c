/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:33:09 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/29 11:40:46 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/* -------------------------------------------------------------------------- */

static int	ft_convert_color(char *color)
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

static int	ft_split_color(char *color)
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

static void	ft_init_colors(t_root *root)
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

static void	ft_chk_path(t_root *root)
{
	int		r;
	char	*res;
	char	*tmp;

	r = -1;
	while (root->map.texture[++r])
	{
		res = ft_substr(root->map.texture[r], 3,
				(ft_strlen(root->map.texture[r]) - 3));
		tmp = ft_strtrim(res, " ");
		if (open(tmp, O_RDONLY) < 0)
		{
			free(res);
			free(tmp);
			ft_error("INVALID MAP HEADER");
		}
		free(res);
		free(tmp);
	}
}

/* -------------------------------------------------------------------------- */

void	ft_init_header(t_root *root)
{
	t_list	*mheader;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mheader = root->mheader;
	while (mheader)
	{
		if (!ft_chk_txt(mheader->content))
		{
			root->map.texture[i] = ft_strdup(mheader->content);
			i++;
		}
		else if (!ft_chk_color(mheader->content))
		{
			root->map.collor[j] = ft_strdup(mheader->content);
			j++;
		}
		mheader = mheader->next;
	}
	root->map.texture[i] = NULL;
	root->map.collor[j] = NULL;
	ft_chk_path(root);
	ft_init_colors(root);
}

/* -------------------------------------------------------------------------- */
