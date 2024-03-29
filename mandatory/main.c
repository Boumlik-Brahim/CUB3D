/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:20:43 by bbrahim           #+#    #+#             */
/*   Updated: 2022/12/01 14:15:30 by bbrahim          ###   ########.fr       */
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
