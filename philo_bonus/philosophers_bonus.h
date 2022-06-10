/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:58:07 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/09 12:58:05 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	int			number_of_philosophers;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			number_philo_each;
	// pthread_mutex_t	all_fork;
	// pthread_mutex_t	*fork;
	long		start;
	sem_t		*fork;
}				t_all;

typedef struct philosophers
{
	pthread_t	philo_life;
	t_all		*all;
	int			name;
	long		s_start;
	long		s_end;
	int			is_eating;
	int			n_philo_each;
	// pthread_mutex_t	last;
}				t_philo;

int				ft_atoi(const char *str);
long			get_time(void);
void			eating_time(t_philo *data);
void			taken_fork_time(t_philo *data);
void			sleeping_time(t_philo *data);
void			thinking_time(t_philo *data);
void			die_time(t_philo *data);
void			create_pross(t_philo *data, t_all *all);
void			philo_man(t_philo *data, int *status);
void			ft_usleep(int time);
void			print_action(t_philo *data, double time, char *msg);

#endif
