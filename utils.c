/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:37:01 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/24 19:01:23 by tzinaliy         ###   ########.fr       */
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