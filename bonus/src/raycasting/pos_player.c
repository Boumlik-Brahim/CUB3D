/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:02:00 by zel-hach          #+#    #+#             */
/*   Updated: 2022/11/30 20:54:48 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"


void	where_player(t_root *root)
{
	int	i;
	int	j;

	j = 0;
	while (root->map.content[j])
	{
		i = 0;
		while (root->map.content[j][i])
		{
			if (root->map.content[j][i] == 'N' || root->map.content[j][i] == 'S'
			|| root->map.content[j][i] == 'W' || root->map.content[j][i] == 'E')
			{
				root->player.posx = (double)i * 32;
				root->player.posy = (double)j * 32;
			}
			i++;
		}
		j++;
	}
}
