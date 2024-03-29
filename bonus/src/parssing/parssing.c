/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:21:45 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/29 12:04:26 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	ft_parssing(char *av, t_root *root)
{
	int		count;

	count = 0;
	ft_read_map(av, root);
	ft_chk_header(root);
	ft_chk_body(root, &count);
	ft_alloc_tables(root, count);
	ft_init_header(root);
	ft_init_body(root, count);
	ft_chk_body_content(root);
}
