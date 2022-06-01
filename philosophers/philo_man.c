/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:36:09 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/01 17:07:23 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <string.h>
void	print_action(t_philo *data, double time, char *msg)
{
	pthread_mutex_lock(&data->all->all_fork);
	printf("%.0f %d %s\n", time, data->name, msg);
	if (strcmp("die",msg))
		pthread_mutex_unlock(&data->all->all_fork);

}

void	ft_usleep(int time_to_sleep)
{
	struct timeval	sleep_start;
	struct timeval	sleep_end;

	gettimeofday(&sleep_start, NULL);
	gettimeofday(&sleep_end, NULL);
	while ((((sleep_end.tv_sec - sleep_start.tv_sec) * 1000000)
			+ (sleep_end.tv_usec - sleep_start.tv_usec)) <= time_to_sleep
		* 1000)
		gettimeofday(&sleep_end, NULL);
}

int	odd_philo(t_philo *data)
{
	gettimeofday(&data->s_start, NULL);
	while (1)
	{
		pthread_mutex_lock(&data->all->fork[data->name - 1]);
		taken_fork_time(data);
		pthread_mutex_lock(&data->all->fork[data->name
				% data->all->number_of_philosophers]);
		taken_fork_time(data);
		gettimeofday(&data->s_start, NULL);
		eating_time(data);
		gettimeofday(&data->s_start, NULL);
		ft_usleep(data->all->time_to_eat);
		pthread_mutex_unlock(&data->all->fork[data->name - 1]);
		pthread_mutex_unlock(&data->all->fork[data->name
				% data->all->number_of_philosophers]);
		data->n_philo_each++;
		sleeping_time(data);
		// printf("%ld\n",data->all->time_to_sleep);
		ft_usleep(data->all->time_to_sleep);
		thinking_time(data);
	}
	return (0);
}

void	*ft_thread(void *rcv)
{
	t_philo *data;

	data = (t_philo *)rcv;
	data->n_philo_each = 0;
	odd_philo(data);
	return (NULL);
}