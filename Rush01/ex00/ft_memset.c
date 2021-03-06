/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:43:06 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/06 08:03:40 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *dest, int c, unsigned int n)
{
	while (n > 0)
	{
		((unsigned char *)dest)[n - 1] = c;
		n--;
	}
	return (dest);
}	
