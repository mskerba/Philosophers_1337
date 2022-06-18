/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:36:09 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/16 13:07:38 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_philo *data, double time, char *msg)
{
	pthread_mutex_lock(&data->all->all_fork);
	printf("%.0f %d %s\n", time, data->name, msg);
	if (ft_strcmp("died", msg))
		pthread_mutex_unlock(&data->all->all_fork);
}

long	get_time(void)
{
	struct timeval	tv;
	long			end;

	gettimeofday(&tv, NULL);
	end = ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
	return (end);
}

void	ft_usleep(int time)
{
	long	start;

	start = get_time();
	usleep(time * 800);
	while (get_time() < start + time)
		usleep(50);
}

int	odd_philo(t_philo *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->all->fork[data->name - 1]);
		taken_fork_time(data);
		pthread_mutex_lock(&data->all->fork[data->name
			% data->all->number_of_philosophers]);
		taken_fork_time(data);
		eating_time(data);
		pthread_mutex_lock(&data->last);
		data->s_start = get_time();
		data->is_eating = 1;
		data->n_philo_each++;
		pthread_mutex_unlock(&data->last);
		ft_usleep(data->all->time_to_eat);
		pthread_mutex_unlock(&data->all->fork[data->name - 1]);
		pthread_mutex_unlock(&data->all->fork[data->name
			% data->all->number_of_philosophers]);
		sleeping_time(data);
		ft_usleep(data->all->time_to_sleep);
		thinking_time(data);
	}
	return (0);
}

void	*ft_thread(void *rcv)
{
	t_philo	*data;

	data = (t_philo *)rcv;
	pthread_mutex_lock(&data->last);
	data->n_philo_each = 0;
	data->is_eating = 0;
	data->s_start = get_time();
	pthread_mutex_unlock(&data->last);
	odd_philo(data);
	return (NULL);
}
