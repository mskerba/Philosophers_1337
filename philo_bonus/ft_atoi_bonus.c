/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:30:22 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/17 11:41:13 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] == s1[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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

static int	check_c(const char *str, int j)
{
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (1);
		j++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = check_sign(str[i], sign);
		i++;
	}
	if (check_c(str, i))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res >= 9223372036854775807)
		return (check_max_min(res, sign));
	return (res * sign);
}
