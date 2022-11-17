/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:13:40 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/17 10:55:36 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/* -------------------------------------------------------------------------- */

int	ft_chk_dup(t_list **list, char *text, int size)
{
	t_list	*current;

	current = (*list)->next;
	while (current)
	{
		if (ft_strncmp(text, current->content, size))
			current = current->next;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */

int	ft_is_space(char c)
{
	if (c == '\n' || c == '\r' || c == '\v'
		|| c == ' ' || c == '\f')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_nempty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (EXIT_SUCCESS);
	while (line[i] && ft_is_space(line[i]) != 0)
		i++;
	if (line[i] != '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */

int	ft_chk_ext(char *str, char	*ext)
{
	char	*extntion;

	extntion = ft_strrchr(str, '.');
	if (!extntion || ft_strncmp(extntion, ext, 5))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_chk_txt(char *text)
{
	if (!text)
		return (EXIT_FAILURE);
	if (!ft_strncmp(text, "NO ", 3) || !ft_strncmp(text, "SO ", 3)
		|| !ft_strncmp(text, "WE ", 3) || !ft_strncmp(text, "EA ", 3))
	{
		if (!ft_chk_ext(text, ".xpm"))
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/* -------------------------------------------------------------------------- */
