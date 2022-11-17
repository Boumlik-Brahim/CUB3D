/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:27:22 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/17 11:28:19 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

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
			put_errors("INVALID MAP HEADER");
		if (!is_nempty_line(mbody->content)
			&& is_nempty_line(mbody->next->content))
			put_errors("INVALID MAP BODY");
		else if (is_nempty_line(mbody->content))
			(*count)++;
		mbody = mbody->next;
	}
}

/* -------------------------------------------------------------------------- */

void	ft_alloc_tables(t_root *root, int count)
{
	root->map.content = (char **)malloc(sizeof(char *) * (count + 1));
	if (!root->map.content)
		put_errors("CONTENT TABLE ALLOC ERROR");
	root->map.collor = (char **)malloc(sizeof(char *) * 3);
	if (!root->map.collor)
		put_errors("COLLOR TABLE ALLOC ERROR");
	root->map.texture = (char **)malloc(sizeof(char *) * 5);
	if (!root->map.texture)
		put_errors("TEXTURE TABLE ALLOC ERROR");
}

/* -------------------------------------------------------------------------- */

void	ft_init_body(t_root *root, int count)
{
	t_list	*mbody;
	int		i;

	mbody = root->mbody;
	i = 0;
	while (mbody && i < count)
	{
		if (is_nempty_line(mbody->content))
		{
			root->map.content[i] = ft_strdup(mbody->content);
			i++;
		}
		mbody = mbody->next;
	}
	root->map.content[count] = NULL;
}

/* -------------------------------------------------------------------------- */

void	ft_chk_player(t_root *root)
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
		put_errors("INVALID MAP BODY");
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
				put_errors("INVALID MAP BODY");
			if (ft_strchr("0NSWE", root->map.content[r][c]))
			{
				if (ft_chkmc_vertical(r, c, root)
					|| ft_chkmc_horizontal(r, c, root))
					put_errors("INVALID MAP BODY");
			}
			c++;
		}
	}
	ft_chk_player(root);
}

/* -------------------------------------------------------------------------- */