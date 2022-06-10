/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:06:11 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/04 13:02:45 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_die(t_philo *data)
{
	int		i;
	double	time;
	int		j;

	i = 0;
	j = 0;
	while (i < data[0].all->number_of_philosophers)
	{
		pthread_mutex_lock(&data[i].last);
		if (data[i].n_philo_each > data[i].all->number_philo_each
			&& data[i].all->number_philo_each != -1)
			j++;
		time = get_time() - data[i].s_start;
		if (time >= data[i].all->time_to_die && data[i].is_eating == 0)
		{
			die_time(&data[i]);
			return (-1);
		}
		pthread_mutex_unlock(&data[i].last);
		i++;
	}
	return (j);
}

void	*ft_check_thread(void *rcv)
{
	t_philo	*data;
	int		j;

	data = (t_philo *)rcv;
	while (1)
	{
		j = check_die(data);
		if (j == -1)
			return ("fail");
		if (j == data[0].all->number_of_philosophers
			&& data[0].all->number_philo_each != -1)
			return ("fail");
	}
	return (NULL);
}
