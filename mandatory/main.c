/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:20:43 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/02 13:05:00 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int	main(int ac, char **av)
{
	t_root	root;

	if (ac != 2 || !av[1])
	{
		printf("\033[0;31mA map in format `*.cub` is required!\033[0;37m\n");
		return (EXIT_FAILURE);
	}
	ft_chk_map_ext(av[1]);
	ft_read_map(av[1], &root);
	return (0);
}