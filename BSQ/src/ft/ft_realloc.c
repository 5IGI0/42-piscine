/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:00:13 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/14 11:03:24 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_memcpy.h"

void	*ft_realloc(void *old, unsigned int old_size,
		unsigned int new_size)
{
	void	*new;

	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, old, old_size);
	free(old);
	return (new);
}
