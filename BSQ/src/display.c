/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:44:24 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/17 02:50:38 by tescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <unistd.h>

int	is_filled(unsigned int i, unsigned int j, struct s_square square)
{
	return (j >= square.x
		&& j < (square.x + square.size)
		&& i >= square.y
		&& i < (square.y + square.size));
}

void	display(struct s_map map, struct s_square square)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < map.line)
	{
		j = 0;
		while (j < map.col)
		{
			if (is_filled(i, j, square))
				write(1, &map.full, 1);
			else if (map.map[i][j] == 0)
				write(1, &map.empty, 1);
			else if (map.map[i][j] == 1)
				write(1, &map.obstacle, 1);
			j = j + 1;
		}
		write(1, "\n", 1);
		i = i + 1;
	}
}
