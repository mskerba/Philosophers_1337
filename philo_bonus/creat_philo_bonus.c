/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:48:48 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/18 11:04:24 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	continue_create(t_all *all, t_philo *data, int *philo_id)
{
	int	id;
	int	pid;
	int	i;

	i = 0;
	while (i < all->number_of_philosophers)
	{
		id = fork();
		if (id == 0)
		{
			data[i].all = all;
			data[i].id = pid;
			philo_man(&data[i]);
		}
		if (id != 0)
		{
			pid = id;
			philo_id[i] = id;
		}
		i++;
	}
}

void	create_pross(t_philo *data, t_all *all)
{
	int	i;
	int	status;
	int	*philo_id;
	int	j;

	philo_id = malloc(4 * all->number_of_philosophers);
	all->start = get_time();
	continue_create(all, data, philo_id);
	i = -1;
	while (++i < all->number_of_philosophers)
	{
		waitpid(-1, &status, 0);
		if (!status)
		{
			j = -1;
			while (++j < all->number_of_philosophers)
				kill(philo_id[j], SIGKILL);
			exit(EXIT_SUCCESS);
		}
	}
}
