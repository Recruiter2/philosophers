/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:19:43 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/23 21:45:33 by tzinaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

//check if a string contains only digits
static	int is_digit_str(char *s)
{
	int	i = 0;

	if (s[i] == '+')
		i++;
	if (s[i] == '\0')
		return 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return 0;
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv, t_data *data)
{
	int	i = 1;

	if (argc != 5 && argc != 6)
	{
		printf("Error: invalid number of arguments\n");
		return (1);
	}
	while (i < argc)
	{
		if (!is_digit_str(argv[i]))
		{
			printf("Error: arguments must be positive integers\n");
		}
		i++;
	}
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = -1;
	if (data->num_of_philos <= 0 || data ->time_to_die <=0 ||
		data->time_to_eat <= 0 || data->time_to_sleep <=0)
	{
		printf("Error: arguments must be greater than 0\n");
		return (1);
	}
	return (0);
}