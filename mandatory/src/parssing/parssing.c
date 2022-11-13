/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:45 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/13 18:57:32 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*--------------------------------chk_map-------------------------------------*/
int	ft_chk_map(char *text)
{
	int		i;

	i = 0;
	if (!text)
		return (EXIT_FAILURE);
	while (text[i])
	{
		if (text[i] == '1' || text[i] == '0' || text[i] == ' ' || text[i] == 'N'
			|| text[i] == 'S' || text[i] == 'E' || text[i] == 'W')
			i++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
/*--------------------------------chk_map-------------------------------------*/

/*--------------------------------chk_color-----------------------------------*/
int	ft_colorlen(char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (tmp[++i])
	{
		j = 0;
		while (tmp[i][j])
			j++;
	}
	return (i);
}

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
	return (EXIT_SUCCESS);
}

int	ft_colortoint(char *color)
{
	char	**tmp;
	int		i;

	tmp = ft_split(color, ',');
	if (ft_colorlen(tmp) > 3)
		return (EXIT_FAILURE);
	i = -1;
	while (tmp[++i])
	{
		if (ft_chk_num(tmp[i]) != 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_chk_digit(char *color)
{
	int		i;
	int		clen;

	clen = ft_strlen(color);
	if (color[2] == ',' || color[clen - 1] == ',' || ft_colortoint(color) != 0)
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
/*--------------------------------chk_color-----------------------------------*/

/*--------------------------------chk_txt-------------------------------------*/
int	ft_chk_dup(t_list **list, char *text, int size)
{
	t_list	*current;

	current = (*list)->next;
	while (current->next)
	{
		if (ft_strncmp(text, current->content, size))
			current = current->next;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\r' || c == '\v'
		|| c == ' ' || c == '\f')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]) != 0)
		i++;
	if (line[i] != '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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

/*--------------------------------chk_txt-------------------------------------*/

void	ft_read_map(char *av, t_root *root)
{
	char	*line;
	int		fd;
	t_list	*list;
	t_list	*current;

	fd = open(av, O_RDONLY);
	if (fd != 3)
	{
		ft_putstr_fd("INVALID MAP", 1);
		exit(1);
	}
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		ft_lstadd_back(&list, ft_lstnew(ft_strtrim(line, " \n")));
	}
	current = list;
	while (list->next)
	{
		if (is_empty_line(list->content))
		{
			if (!ft_chk_map(list->content)
				&& (ft_chk_txt(list->next->content)
					&& ft_chk_color(list->next->content)))
				list->ismap = true;
		}
		list = list->next;
	}
	while (current->next && !current->ismap)
	{
		if (is_empty_line(current->content))
		{
			if ((ft_chk_txt(current->content) && ft_chk_color(current->content))
				|| (ft_chk_dup(&current, current->content, 3)
					&& ft_chk_dup(&current, current->content, 2)))
					current->valid = false;
		}
		current = current->next;
	}
	root->map.data = NULL;
	close(fd);
}
