/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:06:11 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/02 18:06:36 by mskerba          ###   ########.fr       */
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
			if (data[i].n_philo_each > data[i].all->number_philo_each
				&& data[i].all->number_philo_each != -1)
				j++;
			time = get_time() -  data[i].s_start;
			// printf("%d  %d %f\n",i,data[i].is_eating,time);
			if (time >= data[i].all->time_to_die && data[i].is_eating == 0)
			{
				die_time(&data[i]);
				return ("fail");
			}
			pthread_mutex_unlock(&data[i].last);
			i++;
			// usleep(500);
		}
		if (j == data[0].all->number_of_philosophers
			&& data[0].all->number_philo_each != -1)
			return ("fail");
		usleep(300);
	}
	return (NULL);
}
