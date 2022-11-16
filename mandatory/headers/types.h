/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:24:27 by bbrahim           #+#    #+#             */
/*   Updated: 2022/11/16 14:20:36 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "../../libs/Libft/libft.h"

typedef struct s_map
{
	char	**texture;
	char	**collor;
	char	**content;
}	t_map;

typedef struct s_root
{
	t_map	map;
	t_list	*mheader;
	t_list	*mbody;
}	t_root;

#endif