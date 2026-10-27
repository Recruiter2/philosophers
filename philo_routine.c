/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 00:23:17 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/27 14:40:12 by tzinaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//The function each thread will execute
void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	//prevent deadlock: delay even-numbered philosophers slightly so
	// odd-numbered ones grab the forks first
	if (philo->id % 2 == 0)
		usleep(1000); // Wait 1ms so odd philos grab forks first

	while (!check_if_dead(philo->data)) //sim loop
	{
		// Check if someone died (requires locking flag_lock)
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		// EDGE CASE: if there is only 1 philosopher,they only have 1 fork.
		// They should just wait here until they starve, otherwise they will
		// try to lock a non-existent right fork and segfault
		if (philo->data->num_of_philos == 1)
		{
			pthread_mutex_unlock(philo->right_fork);
			ft_usleep(philo->data->time_to_die, philo->data);
			break;
		}
		// 1 & 2. Take forks
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		

		// 3. Eat (update last_meal_time, lock meal_lock)
		print_action(philo, "is eating");

		// Protect updates to meal variables with meal_lock
		pthread_mutex_lock(&philo->data->meal_lock);
		philo->last_meal_time = get_current_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->data->meal_lock);

		// Wait for the eating time to pass
		ft_usleep(philo->data->time_to_eat, philo->data);

		// 4. Drop forks (order doesn't matter here)
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);

		// 5. Sleep
		print_action(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
		
		// 6. Think
		print_action(philo, "is thinking");
	}
	return (NULL);
}