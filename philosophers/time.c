/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:01 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/01 12:24:57 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating_time(t_philo *data)
{
	unsigned long	time;
	struct timeval	end;

	gettimeofday(&end, NULL);
	gettimeofday(&data->s_start, NULL);
	time = (((end.tv_sec - data->all->start.tv_sec) * 1000) + (end.tv_usec
				- data->all->start.tv_usec) / 1000);
	print_action(data, time, "is eating");
}

void	taken_fork_time(t_philo *data)
{
	unsigned long	time;
	struct timeval	end;

	time = 0;
	gettimeofday(&end, NULL);
	time = (((end.tv_sec - data->all->start.tv_sec) * 1000) + (end.tv_usec
				- data->all->start.tv_usec) / 1000);
	print_action(data, time, "has taken a fork");
}

void	sleeping_time(t_philo *data)
{
	unsigned long	time;
	struct timeval	end;

	gettimeofday(&end, NULL);
	time = (((end.tv_sec - data->all->start.tv_sec) * 1000) + (end.tv_usec
				- data->all->start.tv_usec) / 1000);
	print_action(data, time, "is sleeping");
}

void	thinking_time(t_philo *data)
{
	unsigned long time;
	struct timeval end;

	gettimeofday(&end, NULL);
	time = (((end.tv_sec - data->all->start.tv_sec) * 1000) + ((end.tv_usec
					- data->all->start.tv_usec) / 1000));
	print_action(data, time, "is thinking");
}

void	die_time(t_philo *data)
{
	unsigned long time;
	struct timeval end;

	gettimeofday(&end, NULL);
	time = (((end.tv_sec - data->all->start.tv_sec) * 1000) + ((end.tv_usec
					- data->all->start.tv_usec) / 1000));
	print_action(data, time, "die");
}
