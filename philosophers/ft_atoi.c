/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:30:22 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/02 17:30:31 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"


int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] == s1[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] -(unsigned char)s2[i]);
}

static int	check_max_min(unsigned long res, int sign)
{
	if (res >= 9223372036854775807)
	{
		if (sign > 0)
			return (-1);
	}
	return (0);
}

static int	check_sign(char s, int sign)
{
	if (s == '+' || s == '-')
	{
		if (s == '-')
			sign = -1;
		else
			sign = 1;
	}
	return (sign);
}

int	ft_atoi(const char	*str)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = check_sign(str[i], sign);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res >= 9223372036854775807)
		return (check_max_min(res, sign));
	return (res * sign);
}
