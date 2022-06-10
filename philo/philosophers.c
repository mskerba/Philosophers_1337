/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:07:35 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/09 12:42:22 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	data_management(t_all *all, char **s)
{
	all->number_of_philosophers = ft_atoi(s[1]);
	all->time_to_die = ft_atoi(s[2]);
	all->time_to_eat = ft_atoi(s[3]);
	all->time_to_sleep = ft_atoi(s[4]);
	if (s[5])
		all->number_philo_each = ft_atoi(s[5]) - 1;
	else
		all->number_philo_each = -1;
}

static void	create_threads(t_philo *data, t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->number_of_philosophers)
	{
		data[i].all = all;
		pthread_mutex_init(&data[i].last, NULL);
		pthread_create(&data[i].philo_life, NULL, ft_thread, (void *)&data[i]);
		usleep(50);
	}
}

static void	philo_name(t_philo *data, t_all *all)
{
	int	i;
	int	j;

	i = -1;
	j = all->number_of_philosophers;
	while (++i < j)
		data[i].name = i + 1;
	all->number_of_philosophers = j;
}

static void check_arg()
{
	
}

int	main(int c, char **s)
{
	t_philo		*data;
	t_all		*all;
	int			i;
	pthread_t	check_philo_life;

	i = -1;
	if (c == 5 || c == 6)
	{
		data = malloc(sizeof(t_philo) * ft_atoi(s[1]));
		all = malloc(sizeof(t_all));
		data_management(all, s);
		chech_arg(all);
		all->fork = malloc(sizeof(pthread_mutex_t)
				* all->number_of_philosophers);
		while (++i < all->number_of_philosophers)
			pthread_mutex_init(&all->fork[i], NULL);
		pthread_mutex_init(&all->all_fork, NULL);
		philo_name(data, all);
		all->start = get_time();
		create_threads(data, all);
		pthread_create(&check_philo_life, NULL, ft_check_thread, (void *)data);
		if (!pthread_join(check_philo_life, NULL))
			return (0);
	}
}
