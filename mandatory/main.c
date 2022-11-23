/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:20:43 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/23 15:02:25 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

void	ft_backbone(char *av, t_root *root)
{
	ft_parssing(av, root);
	mlx(&root->map);
	// mlx(root);
}

int	main(int ac, char **av)
{
	t_root	root;

	if (ac != 2 || !av[1] || ft_chk_ext(av[1], ".cub"))
	{
		printf("\033[0;31mA MAP IN FORMAT `*.CUB` IS REQUIRED!\033[0;37m\n");
		return (EXIT_FAILURE);
	}
	ft_backbone(av[1], &root);
	return (0);
}
