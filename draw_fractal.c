/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:11:07 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/21 12:48:49 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractol *mlx)
{
	int		x;
	int		y;
	double	num_real;
	double	num_imaginary;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			num_real = mlx->min_r + (double)x
				* (mlx->max_r - mlx->min_r) / WIDTH;
			num_imaginary = mlx->min_i + (double)y
				* (mlx->max_i - mlx->min_i) / HEIGHT;
			julia(mlx, x, y, num_real, num_imaginary);
		}
	}
}

void	draw_mandelbrot(t_fractol *mlx)
{
	int		x;
	int		y;
	double	num_real;
	double	num_imaginary;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			num_real = mlx->min_r + (double)x
				* (mlx->max_r - mlx->min_r) / WIDTH;
			num_imaginary = mlx->min_i + (double)y
				* (mlx->max_i - mlx->min_i) / HEIGHT;
			mandelbrot(mlx, x, y, num_real, num_imaginary);
		}
	}
}

void	draw_fractal(t_fractol *mlx, int arg)
{
	if (arg > 2)
		draw_julia(mlx);
	else
		draw_mandelbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
