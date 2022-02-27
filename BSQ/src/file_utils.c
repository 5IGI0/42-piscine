/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:33:28 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/17 07:46:31 by tescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft/ft_realloc.h"
#include "ft/ft_memcpy.h"

#define ALLOC_SEGMENT 50

static int	futils_read_buffsize_check(unsigned int i, char **line,
	unsigned int *buffsize)
{
	char	*new;

	if (i + 1 >= buffsize[0])
	{
		new = ft_realloc(line[0], buffsize[0], buffsize[0] + ALLOC_SEGMENT);
		if (new == 0)
			return (-1);
		line[0] = new;
		buffsize[0] = buffsize[0] + ALLOC_SEGMENT;
	}
	return (0);
}

static int	futils_read_exiter(int status, char *line, int i)
{
	if (line)
		line[i] = 0;
	return (status);
}

int	futils_read_line(int fd, char **line, unsigned int *buffsize)
{
	char				c;
	unsigned int		i;
	int					ret;

	if (line[0] == 0)
		buffsize[0] = 0;
	i = 0;
	while (1)
	{
		c = 1;
		ret = read(fd, &c, 1);
		if (ret < 0 || c == '\0')
			return (-1);
		if (ret == 0)
			break ;
		if (c == '\n')
			return (1);
		if (futils_read_buffsize_check(i, line, buffsize) < 0)
			return (-1);
		line[0][i] = c;
		line[0][i + 1] = '\0';
		i++;
	}
	return (futils_read_exiter(0, line[0], i));
}
