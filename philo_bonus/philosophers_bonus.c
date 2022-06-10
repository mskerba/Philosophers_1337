/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:25:15 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/09 20:31:26 by mskerba          ###   ########.fr       */
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

void	create_pross(t_philo *data, t_all *all)
{
	int	i;
	int	id;
	int	pid;
	int	status;

	i = 0;
	all->start = get_time();
	// printf("id_main_proc= %d\n",getpid());
	while (i < all->number_of_philosophers)
	{
		id = fork();
		if (id == 0)
		{
			data[i].all = all;
			philo_man(&data[i], &status);
		}
		if (id != 0)
			pid = id;
		i++;
	}
	status = 5;
	// printf("--%d\n",pid);
	waitpid(pid, &status, 0);
	// printf("===%d %d\n",pid,getpid());
}

int	main(int c, char **s)
{
	t_philo	*data;
	t_all	*all;
	int		i;

	// sem_t	*las;
	// int		k;
	i = -1;
	if (c == 5 || c == 6)
	{
		data = malloc(sizeof(t_philo) * ft_atoi(s[1]));
		all = malloc(sizeof(t_all));
		data_management(all, s);
		philo_name(data, all);
		sem_unlink("ok");
		all->fork = sem_open("ok", O_CREAT, 777, all->number_of_philosophers);
		// k = sem_wait(las);
		// printf("%d\n", k);
		// sem_post(las);
		// printf("dsdjkfld\n");
		create_pross(data, all);
		sem_close(all->fork);
	}
}
