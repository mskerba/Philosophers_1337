/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:12:58 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/18 10:13:21 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_action(t_philo *data, double time, char *msg)
{
	sem_wait(data->all->print);
	printf("%.0f %d %s\n", time, data->name, msg);
	if (ft_strcmp(msg, "died"))
		sem_post(data->all->print);
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
