/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:21:09 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/02 12:07:41 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char	*ft_read_file(int fd)
{
	static char		*res;
	char			*buf;
	int				n;

	buf = (char *)malloc(sizeof(char) + 2);
	if (!buf)
		return (NULL);
	if (!res)
		res = ft_strdup("");
	n = 1;
	while (n != 0)
	{
		n = read(fd, buf, 1);
		if (n == -1)
		{
			free (buf);
			free (res);
			return (NULL);
		}
		buf[n] = '\0';
		res = ft_strjoin(res, buf);
	}
	free (buf);
	return (res);
}

void	ft_read_map(char *av, t_root *root)
{
	char	**map;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd != 3)
		ft_putstr_fd("INVALID MAP", 1);
	line = ft_read_file(fd);
	if (!line)
		ft_putstr_fd("MAP IS EMPTY", 1);
	map = ft_split(line, '\n');
	root->map.data = map;
	close(fd);
}