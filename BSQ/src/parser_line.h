/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:10:16 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/16 19:25:45 by tescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_LINE_H
# define PARSER_LINE_H

# include "structs.h"

int	parser_read_lines(int fd, struct s_map *map, char **line,
		unsigned int *buffsize);

#endif
