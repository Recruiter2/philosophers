/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:45:22 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/27 01:04:43 by tzinaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data data;

	//parse arguments
	if (check_args(argc, argv, &data) != 0)
		return (1);

	//initialize structures, allocate memory, and INIT MUTEXES
	// (initializing data.write_lock, data.flag_lock, data.meal_lock,
	// and an array of forks using pthread_mutex_init)
	if (init_all(&data) != 0)
		return (1);

	//start the simulation (creating my threads)
	if (start_simulation(&data) != 0)
	{
		free_and_destroy(&data);
		return (1);
	}

	// the supervisor loop Monitor for deaths
	// Main thread should sit in a loop here checking if anyone starved
	monitor_loop(&data);
	// or if everyone ate enough. If someone dies, it sets.dead_flag = 1.
	// check_death(&data);

	// cleanup
	// (pthread_mutex_destroy for all mutexes, free all mallocs)
	free_and_destroy(&data);
	return (0);
}

