/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:45 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/15 11:34:12 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*--------------------------------chk_map-------------------------------------*/
int	ft_chk_map(char c)
{
	if (c != '1' && c != '0' && c != ' '
		&& c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (EXIT_FAILURE);
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
	while (current)
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
	if (c == '\n' || c == '\r' || c == '\v'
		|| c == ' ' || c == '\f')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_empty_line(char *line)
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

void ft_chk_header(t_list	*header)
{
	t_list	*mheader;

	mheader = header;
	while (mheader)
	{
		if ((ft_chk_txt(mheader->content) && ft_chk_color(mheader->content))
			|| (ft_chk_dup(&mheader, mheader->content, 3)
				&& ft_chk_dup(&mheader, mheader->content, 2)))
		{
			printf("\033[0;31mA INVALID MAP HEADER\033[0;37m\n");
			break ;
		}
		mheader = mheader->next;
	}
}

void ft_init_header(t_list *header, t_root *root)
{
	t_list	*mheader;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mheader = header;
	root->map.collor = (char **)malloc(sizeof(char *) * 3);
	if (!root->map.collor)
		return ;
	root->map.texture = (char **)malloc(sizeof(char *) * 5);
	if (!root->map.texture)
		return ;
	i = 0;
	j = 0;
	while (mheader)
	{
		if (!ft_chk_txt(mheader->content))
		{
			root->map.texture[i] = ft_strdup(mheader->content);
			i++;
		}
		else if (!ft_chk_color(mheader->content))
		{
			root->map.collor[j] = ft_strdup(mheader->content);
			j++;
		}
		mheader = mheader->next;
	}
	root->map.texture[i] = NULL;
	root->map.collor[j] = NULL;
}

void ft_chk_body(t_list	*body, int *count)
{
	t_list	*mbody;

	mbody = body;
	while (!is_empty_line(mbody->content))
		mbody = mbody->next;
	while (mbody->next)
	{
		if (!ft_chk_txt(mbody->content) || !ft_chk_color(mbody->content))
		{
			printf("\033[0;31mA INVALID MAP HEADER\033[0;37m\n");
			break ;
		}
		if (!is_empty_line(mbody->content)
			&& is_empty_line(mbody->next->content))
		{
			printf("\033[0;31mA INVALID MAP BODY\033[0;37m\n");
			break ;
		}
		else if (is_empty_line(mbody->content))
			(*count)++;
		mbody = mbody->next;
	}
}

void ft_init_body(t_list *body, t_root *root, int count)
{
	t_list	*mbody;
	int		i;

	mbody = body;
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

int ft_chkm_vertical(int r, int c, t_root *root)
{
	int	i;

	i = r + 1;
	while (root->map.content[i] && root->map.content[i][c] != '1')
	{
		if (root->map.content[i][c] != '0' && root->map.content[i][c] != 'N'
			&& root->map.content[i][c] != 'S' && root->map.content[i][c] != 'W'
			&& root->map.content[i][c] != 'E')
			return (EXIT_FAILURE);
		i++;
	}
	i = r;
	while (root->map.content[i] && root->map.content[i][c] != '1' && i >= 0)
	{
		if (root->map.content[i][c] != '0' && root->map.content[i][c] != 'N'
			&& root->map.content[i][c] != 'S' && root->map.content[i][c] != 'W'
			&& root->map.content[i][c] != 'E')
			return (EXIT_FAILURE);
		i--;
	}
	return (EXIT_SUCCESS);
}

int ft_chkm_horizontal(int r, int c, t_root *root)
{
	int	j;

	j = c + 1;
	while (root->map.content[r][j] && root->map.content[r][j] != '1')
	{
		if (root->map.content[r][j] != '0' && root->map.content[r][j] != 'N'
			&& root->map.content[r][j] != 'S' && root->map.content[r][j] != 'W'
			&& root->map.content[r][j] != 'E')
			return (EXIT_FAILURE);
		j++;
	}
	j = c;
	while (root->map.content[r][j] && root->map.content[r][j] != '1' && j >= 0)
	{
		if (root->map.content[r][j] != '0' && root->map.content[r][j] != 'N'
			&& root->map.content[r][j] != 'S' && root->map.content[r][j] != 'W'
			&& root->map.content[r][j] != 'E')
			return (EXIT_FAILURE);
		j--;
	}
	return (EXIT_SUCCESS);
}

/*--------------------------------chk_txt-------------------------------------*/
void	ft_read_map(char *av, t_root *root)
{
	char	*line;
	int		fd;
	t_list	*mheader;
	t_list	*mbody;
	t_list	*new;
	int		i;
	int		r;
	int		c;
	int		count;

	count = 0;
	fd = open(av, O_RDONLY);
	if (fd != 3)
	{
		ft_putstr_fd("INVALID MAP", 1);
		exit(1);
	}
	/*----------------------------------------------*/
	line = "";
	i = 0;
	while (line != NULL && i < 6)
	{
		line = get_next_line(fd);
		if (is_empty_line(line))
		{
			new = ft_lstnew(ft_strtrim(line, " \n"));
			ft_lstadd_back(&mheader, new);
			i++;
		}
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		new = ft_lstnew(ft_strtrim(line, "\n"));
		ft_lstadd_back(&mbody, new);
	}
	ft_chk_header(mheader);
	ft_chk_body(mbody, &count);
	ft_init_header(mheader, root);
	ft_init_body(mbody, root, count);
	r = -1;
	while (root->map.content[++r])
	{
		c = 0;
		while (root->map.content[r][c])
		{
			printf("chkmap========>%d\n", ft_chk_map(root->map.content[r][c]));
			if (root->map.content[r][c] == '0')
			{
				// if (ft_chkm_vertical(r, c, root) || ft_chkm_horizontal(r, c, root))
				// {
				// 	printf("\033[0;31mA INVALID MAP BODY\033[0;37m\n");
				// 	exit(1);
				// }
			}
			c++;
		}
	}
	close(fd);
}
