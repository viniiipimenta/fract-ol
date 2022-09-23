/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:31:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/22 21:44:44 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_name(char *str, int argc)
{
	int	ret_julia;
	int	ret_mandel;

	ret_julia = ft_strcmp(str, "julia");
	ret_mandel = ft_strcmp(str, "mandelbrot");
	if ((ret_julia == 0 && argc == 4) || (ret_mandel == 0 && argc == 2))
		return (0);
	else
		error();
	return (0);
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
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	draw_fractal(mlx, argc);
	mlx_mouse_hook(mlx->win, handle_mouse, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, 17, 0L, handle_close, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	mlx;

	mlx.argc = argc;
	if (argc == 1 || argc > 4 || argc == 3)
		error();
	else if (argc > 2 && argc < 5)
	{
		mlx.kr = ft_atod(argv[2]);
		mlx.ki = ft_atod(argv[3]);
		if (mlx.kr < -2 || mlx.kr > 2)
			error();
		if (mlx.ki < -2 || mlx.ki > 2)
			error();
	}
	check_name(argv[1], argc);
	cmd_mlx(&mlx, argc);
	return (0);
}
