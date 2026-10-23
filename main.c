/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:45:22 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/23 20:47:39 by tzinaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (check_args(argc, argv, &data) != 0)
		return (1);

	printf("Philos: %d, Die: %d, Eat: %d, Sleep: %d, Must Eat: %d\n", data.num_of_philos, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.must_eat_count);
	return (0);
}

