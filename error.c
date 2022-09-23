/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:37:10 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/22 21:46:06 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	write(1, "Try one of these options", 24);
	write(1, "\n", 1);
	write(1, "./fractol julia <num between -2.0", 33); 
	write(1, "and 2.0> <num between -2.0 and 2.0>", 35);
	write(1, "\n", 1);
	write(1, "./fractol mandelbrot", 20);
	write(1, "\n", 1);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (str[i] - str2[i]);
	while (str[i] == str2[i] && (str[i] != '\0' || str2[i] != '\0'))
		i++;
	return (str[i] - str2[i]);
}
