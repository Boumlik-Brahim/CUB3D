/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:45 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/17 13:50:31 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	ft_backbone(char *av, t_root *root)
{
	int		count;
	int		i;

	count = 0;
	ft_read_map(av, root);
	ft_chk_header(root);
	ft_chk_body(root, &count);
	ft_alloc_tables(root, count);
	ft_init_header(root);
	ft_init_body(root, count);
	ft_chk_body_content(root);
	i = -1;
	// while (root->map.collor[++i])
	// {
	// 	printf("|%s|\n", root->map.collor[i]);
	// }
	// i = -1;
	// while (root->map.texture[++i])
	// {
	// 	printf("|%s|\n", root->map.texture[i]);
	// }
	// i = -1;
	// while (root->map.content[++i])
	// {
	// 	printf("|%s|\n", root->map.content[i]);
	// }
}
