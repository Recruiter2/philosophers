#ifndef PHILO_H
# define PHILO_H

#include <bits/pthreadtypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	int			meals_eaten;
	long		last_meal_time;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	t_data		*data;
}	t_philo;
typedef struct s_data
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_count;

	long		start_time;
	int			dead_flag;

	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;

	t_philo		*philos;
}	t_data;

int		check_args(int argc, char **argv, t_data *data);
int		ft_atoi(const char *c);
int		check_if_dead(t_data *data);
void	ft_usleep(long time_in_ms, t_data *data);


void	print_action(t_philo *philo, char *action);
int		start_simulation(t_data *data);
void	*philosopher_routine(void *arg);

long	get_current_time(void);

void	monitor_loop(t_data *data);


#endif