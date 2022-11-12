/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:21:09 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/12 18:52:34 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
#include <string.h>

char	*ft_read_file(int fd)
{
	static char	*res;
	char		*buf;
	int			n;

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
			free(buf);
			free(res);
			return (NULL);
		}
		buf[n] = '\0';
		res = ft_strjoin(res, buf);
	}
	free(buf);
	return (res);
}

void	ft_read_map(char *av, t_root *root)
{
	char	**map;
	char	*line;
	int		fd;
	int		count;
	int		i;
	int		j;

	fd = open(av, O_RDONLY);
	if (fd != 3)
	{
		ft_putstr_fd("INVALID MAP", 1);
		exit(1);
	}
	line = ft_read_file(fd);
	if (!line)
		ft_putstr_fd("MAP IS EMPTY", 1);
	char *str = strdup(line);
	char *sub = "";
	count = 0;
	while (sub != NULL)
	{
		sub = strsep(&str, "\n");
		count++;
	}
	map = (char **)malloc(sizeof(char *) * (count));
	if (!map)
		return ;
	char *str0 = ft_strtrim(line, " \n");
	printf("%s", str0);
	char *str2 = strdup(str0);
	char *sub2 = "";
	i = 0;
	while (sub2 != NULL && i < count - 1)
	{
		sub2 = strsep(&str2, "\n");
		map[i] = ft_strdup(sub2);
		i++;
	}
	map[i] = NULL;
	root->map.data = map;
	i = 0;
	j = 0;
	while (root->map.data[i][0] != ' ' && root->map.data[i][0] != '1')
		i++;
	while (root->map.data[i])
	{
		if (!ft_strlen(root->map.data[i]))
			printf("|%s|\n", root->map.data[i]);
		i++;
	}
	// map = ft_split(line, '\n');
	close(fd);
}
