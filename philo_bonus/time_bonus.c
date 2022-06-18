/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:01 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/18 13:30:38 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	eating_time(t_philo *data)
{
	unsigned long	time;

	time = get_time() - data->all->start;
	print_action(data, time, "is eating");
}

void	taken_fork_time(t_philo *data)
{
	unsigned long	time;

	if (data->is_died == 1 && data->all->number_of_philosophers == 1)
	{
		die_time(data);
		exit(0);
	}
	time = get_time() - data->all->start;
	print_action(data, time, "has taken a fork");
}

void	sleeping_time(t_philo *data)
{
	unsigned long	time;

	time = get_time() - data->all->start;
	print_action(data, time, "is sleeping");
	data->is_eating = 0;
}

void	thinking_time(t_philo *data)
{
	unsigned long	time;

	time = get_time() - data->all->start;
	print_action(data, time, "is thinking");
}

void	die_time(t_philo *data)
{
	unsigned long	time;

	time = get_time() - data->all->start;
	print_action(data, time, "died");
}
