/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:07:00 by mskerba           #+#    #+#             */
/*   Updated: 2022/06/01 12:27:23 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_philo_each;
	struct timeval	start;
	pthread_mutex_t	all_fork;
	pthread_mutex_t	*fork;
}					t_all;

typedef struct philosophers
{
	pthread_t		philo_life;
	t_all			*all;
	int				name;
	struct timeval	s_start;
	struct timeval	s_end;
	int				n_philo_each;
}					t_philo;

void				taken_fork_time(t_philo *data);
void				eating_time(t_philo *data);
void				*ft_check_thread(void *rcv);
void				die_time(t_philo *data);
void				sleeping_time(t_philo *data);
void				thinking_time(t_philo *data);
int					odd_philo(t_philo *data);
void				*ft_thread(void *rcv);
void				print_action(t_philo *data, double time, char *msg);
int					ft_atoi(const char *str);
#endif
