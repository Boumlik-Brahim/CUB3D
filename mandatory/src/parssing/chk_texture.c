/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:13:40 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/18 10:11:05 by bbrahim          ###   ########.fr       */
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

void	ft_chk_path(t_root *root)
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
			put_errors("INVALID MAP HEADER");
		}
		free(res);
		free(tmp);
	}
}

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
