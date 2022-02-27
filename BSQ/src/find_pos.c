/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:09:08 by tescande          #+#    #+#             */
/*   Updated: 2022/02/16 19:23:14 by tescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static void	set_null(struct s_square *square, struct s_square *best)
{
	square->x = 0;
	square->y = 0;
	square->size = 0;
	best->x = 0;
	best->x = 0;
	best->x = 0;
}

int	collid(struct s_square square, struct s_map map)
{
	unsigned int	x;
	unsigned int	y;

	x = square.x;
	y = square.y;
	while (x < (square.x + square.size))
	{
		y = square.y;
		while (y < (square.y + square.size))
		{
			if (y == map.line)
				break ;
			if (map.map[y][x])
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

struct s_square	find_pos(struct s_map map)
{
	struct s_square	bst;
	struct s_square	sqr;

	set_null(&sqr, &bst);
	while ((sqr.y + sqr.size) < map.line)
	{
		sqr.x = 0;
		while ((sqr.x + sqr.size) < map.col)
		{
			while (!collid(sqr, map))
			{
				bst = sqr;
				sqr.size++;
				if (
					(sqr.y + sqr.size) > (map.line)
					|| (sqr.x + sqr.size) > (map.col)
				)
					break ;
			}
			sqr.x++;
		}
		sqr.y++;
	}
	return (bst);
}
