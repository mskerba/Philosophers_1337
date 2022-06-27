/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:25:15 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/27 06:46:12 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	data_management(t_all *all, char **s)
{
	all->number_of_philosophers = ft_atoi(s[1]);
	all->time_to_die = ft_atoi(s[2]);
	all->time_to_eat = ft_atoi(s[3]);
	all->time_to_sleep = ft_atoi(s[4]);
	if (s[5])
		all->number_philo_each = ft_atoi(s[5]);
	else
		all->number_philo_each = -1;
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

static int	check_arg(char **s)
{
	if (ft_atoi(s[1]) <= 0)
		return (0);
	if (ft_atoi(s[2]) <= 0)
		return (0);
	if (ft_atoi(s[3]) <= 0)
		return (0);
	if (ft_atoi(s[4]) <= 0)
		return (0);
	if (s[5])
		if (ft_atoi(s[5]) <= 0)
			return (0);
	return (1);
}

int	main(int c, char **s)
{
	t_philo	*data;
	t_all	*all;
	int		i;

	i = -1;
	if (c == 5 || c == 6)
	{
		data = malloc(sizeof(t_philo) * ft_atoi(s[1]));
		all = malloc(sizeof(t_all));
		if (!check_arg(s))
			return (0);
		data_management(all, s);
		philo_name(data, all);
		sem_unlink("sem_fork");
		sem_unlink("sem_print");
		all->print = sem_open("sem_print", O_CREAT, 777, 1);
		all->fork = sem_open("sem_fork", O_CREAT, 777,
				all->number_of_philosophers);
		create_pross(data, all);
		sem_close(all->fork);
		sem_close(all->print);
	}
}
