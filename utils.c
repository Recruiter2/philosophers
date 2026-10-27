/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:37:01 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/27 02:15:18 by tzinaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


//returns current time in ms
long	get_current_time(void)
{
	struct	timeval time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

// sleeps the required time, mostly sleeps for the required amount of ms
void	ft_usleep(long time_sleep_ms, t_data *data)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < time_sleep_ms)
	{
		if (check_if_dead(data)) // excessive control
			break;				// excessive safety
		usleep(500);
	}
}

void	free_and_destroy(t_data	*data)
{
	int	i;

	// Join threads : we wait for all philosophers to safely exit their routines
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}

	// Destroy fork mutexes
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}

	// Destroy shared lock mutexes
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->flag_lock);
	pthread_mutex_destroy(&data->meal_lock);

	// Free heap-allocated memory (assuming these were malloc'd in init) and dangling pointers
	if (data->forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->forks = NULL;
	}
}