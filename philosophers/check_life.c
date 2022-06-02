/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:06:11 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/02 13:57:30 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_check_thread(void *rcv)
{
	t_philo	*data;
	int		i;
	int		j;
	double	time;

	data = (t_philo *)rcv;
	usleep(100);
	while (1)
	{
		j = 0;
		i = 0;
		while (i < data[0].all->number_of_philosophers)
		{
			pthread_mutex_lock(&data[i].last);
			gettimeofday(&data[i].s_end, NULL);
			if (data[i].n_philo_each > data[i].all->number_philo_each
				&& data[i].all->number_philo_each != -1)
				j++;
			time = (((data[i].s_end.tv_sec - data[i].s_start.tv_sec) * 1000)
					+ ((data[i].s_end.tv_usec - data[i].s_start.tv_usec)
						/ 1000));
			if (time >= data[i].all->time_to_die)
			{
				die_time(data);
				return ("fail");
			}
			pthread_mutex_unlock(&data[i].last);
			i++;
			// usleep(100);
		}
		if (j == data[0].all->number_of_philosophers
			&& data[0].all->number_philo_each != -1)
			return ("fail");
		usleep(300);
	}
	return (NULL);
}
