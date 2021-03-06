/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 06:38:57 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/04 08:36:43 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	out;

	if (nb < 0)
		return (0);
	out = 1;
	while (nb > 1)
	{
		out *= nb;
		nb--;
	}
	return (out);
}
