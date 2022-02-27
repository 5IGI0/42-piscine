/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:22:00 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/17 06:29:12 by tescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#include "parser.h"
#include "find_pos.h"

void	map_free(struct s_map map)
{
	unsigned int	i;

	i = 0;
	if (map.map != 0)
	{
		while (i < map.line)
		{
			free(map.map[i]);
			i = i + 1;
		}
		free(map.map);
	}
}

void	display(struct s_map map, struct s_square square);

int	main(int argc, char **argv)
{
	int				i;
	struct s_map	map;
	struct s_square	square;
	int				ret;

	i = 1;
	while (i == 1 || i < argc)
	{
		if (i == argc)
			ret = parse(NULL, &map);
		else
			ret = parse(argv[i], &map);
		if (ret < 0)
			write(1, "map error\n", 10);
		else
		{
			square = find_pos(map);
			display(map, square);
		}
		map_free(map);
		i++;
	}
	return (0);
}
