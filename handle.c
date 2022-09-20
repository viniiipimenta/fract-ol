/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:51:08 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/20 16:00:11 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	handle_close(t_fractol *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_fractol *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *mlx)
{
	double	zoom;

	x = 0;
	y = 0;
	if (button == 4)
	{
		zoom = 0.9;
		mlx->max_r = mlx->max_r + ((mlx->min_r - mlx->max_r) - zoom * (mlx->min_r - mlx->max_r)) / 2;
		mlx->min_r = mlx->max_r + zoom * (mlx->min_r - mlx->max_r);
		mlx->min_i = mlx->min_i + ((mlx->max_i - mlx->min_i) - zoom * (mlx->max_i - mlx->min_i)) / 2;
		mlx->max_i = mlx->min_i + zoom * (mlx->max_i - mlx->min_i);
		draw_fractal(mlx, mlx->argc);
	}
	if (button == 5)
	{
		zoom = 1.1;
		mlx->max_r = mlx->max_r + ((mlx->min_r - mlx->max_r) - zoom * (mlx->min_r - mlx->max_r)) / 2;
		mlx->min_r = mlx->max_r + zoom * (mlx->min_r - mlx->max_r);
		mlx->min_i = mlx->min_i + ((mlx->max_i - mlx->min_i) - zoom * (mlx->max_i - mlx->min_i)) / 2;
		mlx->max_i = mlx->min_i + zoom * (mlx->max_i - mlx->min_i);
		draw_fractal(mlx, mlx->argc);
	}
	return (0);
}
