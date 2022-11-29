/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:22:31 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/29 21:44:14 by zel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

void	ft_backbone(char *av, t_root *root)
{
	ft_parssing(av, root);
	ft_raycasting(root);
	ft_free_map_listes(root);
	ft_free_map_tables(root);
}

int	main(int ac, char **av)
{
	t_root	root;

	if (ac != 2 || !av[1] || ft_chk_ext(av[1], ".cub"))
		ft_error("Map in format `*.CUB` is required!");
	ft_backbone(av[1], &root);
	return (0);
}
