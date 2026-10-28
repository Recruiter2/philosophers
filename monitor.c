/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 23:59:14 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/28 00:27:12 by tzinaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Checks if a single philosopher starved.
	Returns 1 if dead, 0 if alive.
*/
static	int	check_philosopher_death(t_philo *philo, t_data *data)
{
	long	time_since_last_meal;

	pthread_mutex_lock(&data->meal_lock);
	time_since_last_meal = get_current_time() - philo->last_meal_time;
	pthread_mutex_unlock(&data->meal_lock);

	if (time_since_last_meal >= data->time_to_die)
	{
		//Announce death
		pthread_mutex_lock(&data->write_lock);//error
		// Notice we DO NOT unlock write_lock here. This ensures no other
		// philosopher can print anything after the death message.
		printf("%ld %d died \n", get_current_time() - data->start_time, philo->id);
		// Set the global dead flag so threads stop
		pthread_mutex_lock(&data->flag_lock);
		data->dead_flag = 1;
		// print death message
		pthread_mutex_unlock(&data->flag_lock);
		pthread_mutex_unlock(&data->write_lock);
		return (1);
	}
	return (0);
}

// The mains supervisor loop that runs in the main thread.

void	monitor_loop(t_data *data)
{
	int	i;
	int	all_ate;

	while (1)
	{
		i = 0;
		all_ate = 1;
		while (i < data->num_of_philos)
		{
			// Check if this specific philosopher died
			if (check_philosopher_death(&data->philos[i], data))
				return ; //Someone died, exit the monitor loop


			// Check if this philosopher is still eating (if argument 5 exists)
			pthread_mutex_lock(&data->meal_lock);
			if (data->must_eat_count == -1 || data->philos[i].meals_eaten < data->must_eat_count)
				all_ate = 0;
			pthread_mutex_unlock(&data->meal_lock);

			i++;
		}

	// if argument 5 was provided and everyon ate enough, end simulation
	if (data->must_eat_count != -1 && all_ate == 1)
	{
		pthread_mutex_lock(&data->flag_lock);
		data->dead_flag = 1; //Signal threads to stop
		pthread_mutex_unlock(&data->flag_lock);
		return;  //if everyone ate enough, exit the monitor loop
	}

	//Sleep for 1ms to prevent the while loop from hogging the CPU
	usleep(1000);
	}	
}

















