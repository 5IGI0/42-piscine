/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:08:51 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/17 05:15:36 by tescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft/ft_strlen.h"

#include "structs.h"
#include "file_utils.h"

static unsigned char	parser_char_to_id(char c, struct s_map map)
{
	if (c == map.empty)
		return (0);
	else if (c == map.obstacle)
		return (1);
	return (255);
}

static int	parser_parse_line(unsigned char **out, char *line,
		struct s_map *map)
{
	unsigned int	i;
	int				ret;

	out[0] = malloc(map->col);
	if (out[0] == 0)
		return (-1);
	i = 0;
	ret = 0;
	while (i < map->col)
	{
		out[0][i] = parser_char_to_id(line[i], *map);
		if (out[0][i] == 255)
		{
			ret = -1;
			break ;
		}
		i++;
	}
	if (ret < 0)
	{
		free(out[0]);
		out[0] = NULL;
	}
	return (ret);
}

int	parser_read_lines(int fd, struct s_map *map, char **line,
				unsigned int *buffsize)
{
	unsigned int	i;
	int				ret;

	i = 0;
	ret = 0;
	while (i < map->line)
	{
		if (futils_read_line(fd, line, buffsize) < 1)
			break ;
		if (i == 0)
			map->col = ft_strlen(line[0]);
		else if ((unsigned int)ft_strlen(line[0]) != map->col)
			break ;
		if (parser_parse_line((map->map) + i, line[0], map) < 0)
			break ;
		i++;
	}
	while (i < map->line)
	{
		ret = -1;
		map->map[i] = NULL;
		i++;
	}
	return (ret);
}
