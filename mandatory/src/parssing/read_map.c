/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:21:09 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/16 17:21:03 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	ft_read_map(char *av, t_root *root)
{
	int		fd;
	int		i;
	char	*line;
	t_list	*new;

	fd = open(av, O_RDONLY);
	if (fd != 3)
		put_errors("INVALID FILE");
	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			put_errors("EMPTY MAP");
		if (is_empty_line(line))
		{
			new = ft_lstnew(ft_strtrim(line, " \n"));
			free(line);
			ft_lstadd_back(&root->mheader, new);
			i++;
		}
		else
			free(line);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		new = ft_lstnew(ft_strtrim(line, "\n"));
		free(line);
		ft_lstadd_back(&root->mbody, new);
	}
	close(fd);
}
