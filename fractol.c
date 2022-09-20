/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:31:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/20 14:06:39 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

//void	check_name(char *str)
//{
//	char	*julia_check;
//	char	*mandelbrot_check;
//
//	julia_check = malloc(6);
//	julia_check = "julia\0";
//	mandelbrot_check = malloc(11);
//	mandelbrot_check = "mandelbrot\0";
//	if (ft_strncmp(str, julia_check, 6) != 0)
//	{
//		printf("%d\n", ft_strncmp(str, julia_check, 6));
//		error();
//		exit(0);
//	}
//	if (ft_strncmp(str, mandelbrot_check, 11) != 0)
//	{
//		error();
//		exit(0);
//	}
//	free(julia_check);
//	free(mandelbrot_check);
//}

void	cmd_mlx(t_fractol *mlx, int argc)
{
	mlx->mlx = mlx_init();
	mlx->min_r = -2.0;
	mlx->max_r = 2.0;
	mlx->min_i = -1.5;
	mlx->max_i = mlx->min_i + (mlx->max_r - mlx->min_r) * HEIGHT / WIDTH;
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fract-ol");
	draw_fractal(mlx, argc);
	mlx_mouse_hook(mlx->win, handle_mouse, mlx);
	mlx_loop(mlx->mlx);
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
		kr = ft_atod(argv[2]);
		ki = ft_atod(argv[3]);
		mlx.kr = kr;
		mlx.ki = ki;
	}
//	check_name(argv[1]);
	cmd_mlx(&mlx, argc);
	return (0);
}
