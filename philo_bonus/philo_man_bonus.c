/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_man_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:36:09 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/18 13:30:33 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_check_life(void *rcv)
{
	t_philo	*data;
	long	time;

	data = (t_philo *)rcv;
	while (1)
	{
		time = get_time() - data->s_start;
		if (time >= data->all->time_to_die)
		{
			if (data->all->number_of_philosophers == 1)
				sem_post(data->all->fork);
			data->is_died = 1;
		}
		usleep(100);
	}
}

void	check_died(t_philo *data, int is_eat)
{
	sleeping_time(data);
	ft_usleep(data->all->time_to_sleep);
	thinking_time(data);
	if (is_eat == data->all->number_philo_each)
		exit(1);
	if (data->is_died == 1)
	{
		die_time(data);
		exit(0);
	}
}

void	philo_man(t_philo *data)
{
	int			is_eat;
	pthread_t	check_life;

	is_eat = 0;
	data->is_eating = 0;
	data->s_start = get_time();
	data->is_died = 0;
	pthread_create(&check_life, NULL, ft_check_life, (void *)data);
	while (1)
	{
		sem_wait(data->all->fork);
		taken_fork_time(data);
		sem_wait(data->all->fork);
		taken_fork_time(data);
		eating_time(data);
		data->s_start = get_time();
		is_eat++;
		data->is_eating = 1;
		ft_usleep(data->all->time_to_eat);
		sem_post(data->all->fork);
		sem_post(data->all->fork);
		check_died(data, is_eat);
	}
}
