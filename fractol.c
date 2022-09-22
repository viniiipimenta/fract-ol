/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:31:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/22 13:25:32 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	check_name(char *str)
{
	if (ft_strncmp(str, "julia", 5) >= 1)
	{
		error();
		exit(0);
	}
	if (ft_strncmp(str, "mandelbrot", 10) >= 1)
	{
		error();
		exit(0);
	}
}

void	cmd_mlx(t_fractol *mlx, int argc)
{
	mlx->mlx = mlx_init();
	mlx->min_r = -0.5;
	mlx->max_r = 2.5;
	mlx->min_i = -1.5;
	mlx->max_i = mlx->min_i + (mlx->max_r - mlx->min_r) * (HEIGHT / WIDTH);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fract-ol");
	mlx->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length,
								&mlx->endian);
	draw_fractal(mlx, argc);
	mlx_mouse_hook(mlx->win, handle_mouse, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0L, handle_close, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	mlx;
	double		kr;
	double		ki;

	mlx.argc = argc;
	if (argc == 1 || argc > 4)
	{
		error();
		return (0);
	}
	else if (argc > 2 && argc < 5)
	{
		kr = ft_atod(argv[2]);
		ki = ft_atod(argv[3]);
		mlx.kr = kr;
		mlx.ki = ki;
		if (kr < -2.0 && kr > 2.0)
			error_size();
		if (ki < -2.0 && kr > 2.0)
			error_size();
	}
	check_name(argv[1]);
	cmd_mlx(&mlx, argc);
	return (0);
}
