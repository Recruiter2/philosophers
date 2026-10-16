/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzinaliy <tzinaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 12:56:42 by tzinaliy          #+#    #+#             */
/*   Updated: 2026/10/08 13:36:39 by tzinaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isspace(int c)
{
	return (((c > 8) && (c <= 13)) || c == 32);
}

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int	ft_atoi(const char *c)
{
	int	sign;
	int	res;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (isspace(c[i]))
		i++;
	if (c[i] == '+' && c[i + 1] == '-')
		return (0);
	if ((c[i] == '+'))
		i++;
	if (c[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(c[i]))
	{
		res = res * 10 + c[i] - 48;
		i++;
	}
	res *= sign;
	return (res);
}
