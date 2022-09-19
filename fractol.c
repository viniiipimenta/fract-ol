/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:31:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/19 12:56:08 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	mlx;
	double		kr;
	double		ki;

	if (argc > 4)
	{
		write(1, "invalid number of arguments!", 28);
		return (0);
	}
	else if (argc > 1 && argc < 5)
	{
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
