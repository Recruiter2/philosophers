/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 21:02:08 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/26 17:37:34 by tzinaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
/*
Initialization of the global mutexes, allocates memory, and sets up each
philosopher. Returns 0 on success, 1 on failure.
*/

int	init_all(t_data *data)
{
	int	i;

	//Allocate arrays based on num_of_philos
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->forks || !data->philos)
		return (1);

	//initialize global data mutexes
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);

	//initialize all fork mutexes
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}

	// populate each philosopher's variables
	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = get_current_time();
		data->philos[i].data = data;

		//Assign forks : left is their own index, right is the next index.
		//The modulo creates the circular table (last philo's right fork's index 0)
		//couldn't explain
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_of_philos];
	}
	return (0);
}

int	start_simulation(t_data *data)
{
	int	i;

	//Record the exact start time before launching threads
	data->start_time = get_current_time();

	i = 0;
	while (i < data->num_of_philos)
	{
		// initialize the first meal time to the start of the simulation
		data->philos[i].last_meal_time = data->start_time;

		//create a thread for each philosopher
		if (pthread_create(&data->philos[i].thread, NULL, &philosopher_routine, &data->philos[i]) != 0)
		{
			// Note : in a bulletproof project, we add logic here to join threads already created before return and arror
			return (1);
		}
		i++;
	}
	return (0);
}