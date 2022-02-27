/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:34:42 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/14 11:57:35 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_aatoi(char *str, int sign, char *start)
{
	int	ret;
	int	mult;

	ret = 0;
	mult = 1;
	while (str > start)
	{
		str--;
		ret += (str[0] - '0') * mult;
		mult *= 10;
		if (ret == INT_MIN && str == start && sign == -1)
			return (INT_MIN);
		else if (ret < 0)
			return (0);
	}
	return (ret);
}

int	ft_atoi(char *str)
{
	int		sign;
	char	*start;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	start = str;
	while (str[0] >= '0' && str[0] <= '9')
		str++;
	if (str == start)
		return (0);
	return (ft_aatoi(str, sign, start));
}
