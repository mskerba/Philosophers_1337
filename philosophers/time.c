/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:01 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/02 17:48:57 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating_time(t_philo *data)
{
	unsigned long	time;

	time = get_time() - data->all->start;
	print_action(data, time, "is eating");
}

void	taken_fork_time(t_philo *data)
{
	unsigned long	time;

	time = get_time() - data->all->start;
	print_action(data, time, "has taken a fork");
}

void	sleeping_time(t_philo *data)
{
	unsigned long	time;

	time = get_time() - data->all->start;
	print_action(data, time, "is sleeping");
	pthread_mutex_lock(&data->last);
	data->is_eating = 0;
	pthread_mutex_unlock(&data->last);
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
	print_action(data, time, "die");
}
