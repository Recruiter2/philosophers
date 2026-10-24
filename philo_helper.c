/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 01:43:34 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/24 18:41:00 by tzinaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "src/philo.h"
#include <pthread.h>

// Safely check if the simulation should stop
int	check_if_dead(t_data *data)
{
	int	is_dead;

	pthread_mutex_lock(&data->dead_lock);
	is_dead = data->dead_flag;
	pthread_mutex_unlock(&data->dead_lock);
	return (is_dead);
}

// Safely print actins, ensuring we don't print if someone just died
void	print_action(t_philo *philo, char *action)
{
	long	time;

	//lock the write_lock so only one thread prints at a time
	pthread_mutex_lock(&philo->data->write_lock);

	//check if anyone is dead before printing
	time = get_current_time() - philo->data->start_time;
	// Only print if no one is dead yet
	if (!check_if_dead(philo->data))
		printf("%ld %d %s\n", time, philo->id, action);
	// unlock at the end
	pthread_mutex_unlock(&philo->data->write_lock);
}

