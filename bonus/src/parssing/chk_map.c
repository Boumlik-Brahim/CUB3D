/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:17:44 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/29 12:13:26 by bbrahim          ###   ########.fr       */
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
			ft_error("INVALID MAP HEADER");
		mheader = mheader->next;
	}
}

/* -------------------------------------------------------------------------- */

void	ft_chk_body(t_root *root, int *count)
{
	t_list	*mbody;

	mbody = root->mbody;
	while (mbody && !is_nempty_line(mbody->content))
		mbody = mbody->next;
	while (mbody && mbody->next)
	{
		if (!ft_chk_txt(mbody->content) || !ft_chk_color(mbody->content))
			ft_error("INVALID MAP HEADER");
		if (!is_nempty_line(mbody->content)
			&& is_nempty_line(mbody->next->content))
			ft_error("INVALID MAP BODY");
		else if (is_nempty_line(mbody->content))
			(*count)++;
		mbody = mbody->next;
	}
}

/* -------------------------------------------------------------------------- */