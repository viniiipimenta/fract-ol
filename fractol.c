/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:31:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/19 13:31:13 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int count_power(const char *str)
{
    int i;
    int post_comma;

    i = 0;
    post_comma = 0;
    while (str[i])
    {
        if (str[i] == '.')
        {
            while(str[i])
            {
                i++;
                post_comma++;
            }
        }
        i++;
    }
    return (pow(10, post_comma - 1));
}

double	ft_atod(const char *str)
{
	int     i;
	int     signal;
	double  result;
	int     power;

	result = 0;
	signal = 1;
	i = 0;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57 || str[i] == '.')
	{
		if (result >= 9223372036854775807 && signal == 1)
			return (-1);
		if (result > 9223372036854775807 && signal == -1)
			return (0);
        if (str[i] == '.')
            i++;
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	power = count_power(str);
	return ((result * signal) / power);
}

void	error(void)
{
	write(1, "invalid number of arguments!", 28);
	write(1, "./fractol julia <real number> <imaginary number>", 48);
	write(1, "\n", 1);
	write(1, "./fractol mandelbrot", 20);
}

int	main(int argc, char **argv)
{
	t_fractol	mlx;
	double		kr;
	double		ki;

	if (argc == 1 || argc > 4)
	{
		error();
		return (0);
	}
	else if (argc > 2 && argc < 5)
	{
		kr = ft_atoid(argv[2]);
		ki = ft_atoid(argv[3]);
		mlx.kr = kr;
		mlx.ki = ki;
	}
	mlx.mlx = mlx_init();
	mlx.min_r = -2.0;
	mlx.max_r = 1.0;
	mlx.min_i = -1.5;
	mlx.max_i = mlx.min_i + (mlx.max_r - mlx.min_r) * HEIGHT / WIDTH;
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Fract-ol");
	draw_fractal(&mlx, argc);
	mlx_loop(mlx.mlx);
	return (0);
}
