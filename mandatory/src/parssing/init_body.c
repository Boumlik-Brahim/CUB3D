/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_body.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:35:50 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/29 11:37:41 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/* -------------------------------------------------------------------------- */

void	ft_alloc_tables(t_root *root, int count)
{
	root->map.content = (char **)malloc(sizeof(char *) * (count + 1));
	if (!root->map.content)
		ft_error("CONTENT TABLE ALLOC ERROR");
	root->map.collor = (char **)malloc(sizeof(char *) * 3);
	if (!root->map.collor)
		ft_error("COLLOR TABLE ALLOC ERROR");
	root->map.texture = (char **)malloc(sizeof(char *) * 5);
	if (!root->map.texture)
		ft_error("TEXTURE TABLE ALLOC ERROR");
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