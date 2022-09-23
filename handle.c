/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:51:08 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/21 13:25:52 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
	else if (keycode == 125)
		move(mlx, 0.2, 'U');
	else if (keycode == 126)
		move(mlx, 0.2, 'D');
	else if (keycode == 123)
		move(mlx, 0.2, 'L');
	else if (keycode == 124)
		move(mlx, 0.2, 'R');
	draw_fractal(mlx, mlx->argc);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *mlx)
{
	double	zoom;
	double	centerr;
	double	centeri;

	x = x - y;
	centerr = mlx->min_r - mlx->max_r;
	centeri = mlx->max_i - mlx->min_i;
	if (button == 4)
	{
		zoom = 0.9;
		mlx->max_r = mlx->max_r + ((centerr) - zoom * (centerr)) / 2;
		mlx->min_r = mlx->max_r + zoom * (centerr);
		mlx->min_i = mlx->min_i + (centeri - zoom * centeri) / 2;
		mlx->max_i = mlx->min_i + zoom * centeri;
	}
	if (button == 5)
	{
		zoom = 1.1;
		mlx->max_r = mlx->max_r + ((centerr) - zoom * (centerr)) / 2;
		mlx->min_r = mlx->max_r + zoom * (centerr);
		mlx->min_i = mlx->min_i + (centeri - zoom * centeri) / 2;
		mlx->max_i = mlx->min_i + zoom * centeri;
	}
	draw_fractal(mlx, mlx->argc);
	return (0);
}
