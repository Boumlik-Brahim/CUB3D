/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:21:09 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/16 18:37:36 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	ft_get_map_line(int fd, t_root *root)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			put_errors("EMPTY MAP");
		if (is_empty_line(line))
		{
			ft_lstadd_back(&root->mheader, ft_lstnew(ft_strtrim(line, " \n")));
			free(line);
			i++;
		}
		else
			free(line);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		ft_lstadd_back(&root->mbody, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
	}
}

void	ft_read_map(char *av, t_root *root)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd != 3)
		put_errors("INVALID FILE");
	ft_get_map_line(fd, root);
	close(fd);
}
