/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:23:06 by tescande          #+#    #+#             */
/*   Updated: 2022/02/16 19:24:46 by tescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_POS_H
# define FIND_POS_H
# include "structs.h"

int				is_collid(struct s_map map,
					struct s_square *square, unsigned int i, unsigned int j);
struct s_square	find_pos(struct s_map map);
#endif
