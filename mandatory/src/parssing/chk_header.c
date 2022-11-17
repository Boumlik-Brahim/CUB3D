/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:27:19 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/17 11:35:10 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/* -------------------------------------------------------------------------- */

void	ft_chk_header(t_root *root)
{
	t_list	*mheader;

	mheader = root->mheader;
	while (mheader)
	{
		if ((ft_chk_txt(mheader->content) && ft_chk_color(mheader->content))
			|| (ft_chk_dup(&mheader, mheader->content, 3)
				&& ft_chk_dup(&mheader, mheader->content, 2)))
			put_errors("INVALID MAP HEADER");
		mheader = mheader->next;
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
}

/* -------------------------------------------------------------------------- */
