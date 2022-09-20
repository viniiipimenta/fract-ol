/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:31:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/20 09:45:33 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	write(1, "invalid number of arguments!", 28);
	write(1, "\n", 1);
	write(1, "./fractol julia <real number> <imaginary number>", 48);
	write(1, "\n", 1);
	write(1, "./fractol mandelbrot", 20);
	write(1, "\n", 1);
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
		kr = ft_atod(argv[1]);
		ki = ft_atod(argv[2]);
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
