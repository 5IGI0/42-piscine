/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 06:40:46 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/03 14:31:11 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putnbr(int nbr);

int	main(void)
{
	ft_putnbr(-2147483648);
	fputc('\n', stdout);
	ft_putnbr(-2147483647);
	fputc('\n', stdout);
	ft_putnbr(2147483647);
	return (0);
}
