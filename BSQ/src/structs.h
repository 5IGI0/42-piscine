/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:34:13 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/14 16:44:08 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct s_map
{
	char			full;
	char			obstacle;
	char			empty;
	unsigned int	line;
	unsigned int	col;
	unsigned char	**map;
};
/* map -> empty: 0, obstacle: 1 */

struct s_square
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	size;
};

#endif
