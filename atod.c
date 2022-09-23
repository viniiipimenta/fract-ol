/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:23:50 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/23 13:08:59 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					signal;
	unsigned long int	result;

	result = 0;
	signal = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (result >= 9223372036854775807 && signal == 1)
			return (-1);
		if (result > 9223372036854775807 && signal == -1)
			return (0);
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	return (result * signal);
}

size_t	nbsize_atof(double n)
{
	size_t	i;
	int		x;

	x = (int)n;
	i = 0;
	if (x <= 0)
		i++;
	while (x != 0)
	{
		i++;
		x = x / 10;
	}
	return (i);
}

double	check_signal(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (-1);
	else
		return (1);
}

double	ft_atod(char *str)
{
	double	number;
	size_t	size;
	int		i;
	double	signal;
	double	p;

	i = 1;
	p = 1;
	signal = check_signal(str);
	number = (double)ft_atoi((const char *)str);
	if (signal < 0)
	{
		number = -number;
		i = 2;
	}
	size = nbsize_atof(number);
	while (str[size + i] >= '0' && str[size + i] <= '9')
	{
		number += (str[size + i] - 48) / pow(10, p);
		i++;
		p++;
	}
	return (number * signal);
}
