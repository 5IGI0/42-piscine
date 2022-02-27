/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:27:04 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/17 07:46:20 by tescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft/ft_strlen.h"
#include "ft/ft_atoi.h"

#include "structs.h"
#include "parser_line.h"
#include "parser.h"
#include "file_utils.h"

static int	parser_exiter(int status, int fd, char *line)
{
	if (fd > 0)
		close(fd);
	if (line)
		free(line);
	return (status);
}

static int	parser_dup_check(struct s_map map)
{
	return (
		map.empty == map.obstacle
		|| map.obstacle == map.full
		|| map.empty == map.full
	);
}

static int	parser_read_header(int fd, struct s_map *map, char **line,
				unsigned int *buffsize)
{
	int	len;

	if (futils_read_line(fd, line, buffsize) <= 0)
		return (-1);
	if (line[0][0] < '0' || line[0][0] > '9' || ft_strlen(line[0]) < 4)
		return (-1);
	len = ft_strlen(line[0]);
	map->empty = line[0][len - 3];
	map->obstacle = line[0][len - 2];
	map->full = line[0][len - 1];
	if (parser_dup_check(*map))
		return (-1);
	line[0][len - 3] = 0;
	len = 0;
	while (line[0][len])
	{
		if (line[0][len] < '0' || line[0][len] > '9')
			return (-1);
		len++;
	}
	map->line = ft_atoi(line[0]);
	if (map->line <= 0)
		return (-1);
	return (0);
}

int	parse(char *filename, struct s_map *map)
{
	int				fd;
	unsigned int	buffsize;
	char			*line;
	unsigned int	i;

	fd = 0;
	line = 0;
	i = 0;
	if (filename)
		fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (parser_read_header(fd, map, &line, &buffsize) < 0)
		return (parser_exiter(-1, fd, line));
	map->map = malloc(sizeof(*(map->map)) * map->line);
	if (map->map == NULL)
		return (parser_exiter(-1, fd, line));
	while (i < map->line)
	{
		map->map[i] = 0;
		i = i + 1;
	}
	if (parser_read_lines(fd, map, &line, &buffsize) < 0)
		return (parser_exiter(-1, fd, line));
	return (parser_exiter(0, fd, line));
}
