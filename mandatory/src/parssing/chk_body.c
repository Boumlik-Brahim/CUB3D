/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:27:22 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/16 18:39:05 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	ft_chk_body(t_root *root, int *count)
{
	t_list	*mbody;

	mbody = root->mbody;
	while (mbody->next && !is_empty_line(mbody->content))
		mbody = mbody->next;
	while (mbody->next)
	{
		if (!ft_chk_txt(mbody->content) || !ft_chk_color(mbody->content))
			put_errors("INVALID MAP HEADER");
		if (!is_empty_line(mbody->content)
			&& is_empty_line(mbody->next->content))
			put_errors("INVALID MAP BODY");
		else if (is_empty_line(mbody->content))
			(*count)++;
		mbody = mbody->next;
	}
}

void	ft_init_body(t_root *root, int count)
{
	t_list	*mbody;
	int		i;

	mbody = root->mbody;
	root->map.content = (char **)malloc(sizeof(char *) * (count + 1));
	if (!root->map.content)
		return ;
	i = 0;
	while (mbody->next && i < count)
	{
		if (is_empty_line(mbody->content))
		{
			root->map.content[i] = ft_strdup(mbody->content);
			i++;
		}
		mbody = mbody->next;
	}
	root->map.content[count] = NULL;
}

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
			if (ft_chk_map(root->map.content[r][c]))
				put_errors("INVALID MAP BODY");
			if (root->map.content[r][c] == '0')
			{
				if (ft_chkm_vertical(r, c, root)
					|| ft_chkm_horizontal(r, c, root))
					put_errors("INVALID MAP BODY");
			}
			c++;
		}
	}
	ft_chk_player(root);
}
