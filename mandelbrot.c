/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:10:12 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/22 12:26:56 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color(t_fractol *mlx, int x, int y, int n)
{
	if (n >= 0 && n <= 10)
	   	my_mlx_pixel_put(mlx, x, y, 0x6F38C5);
	if (n > 10 && n < 20)
		my_mlx_pixel_put(mlx, x, y, 0x7B6DE0);
	if (n >= 20 && n <= 30)
		my_mlx_pixel_put(mlx, x, y, 0x8188EE);
	if (n > 30 && n < 40)
		my_mlx_pixel_put(mlx, x, y, 0x87A2FB);
	if (n >= 40 && n <= 50)
		my_mlx_pixel_put(mlx, x, y, 0x9AC0E6);
	if (n > 50 && n < 60)
		my_mlx_pixel_put(mlx, x, y, 0xA4CFDB);
	if (n >= 60 && n <= 70)
		my_mlx_pixel_put(mlx, x, y, 0xADDDD0);
	if (n > 70 && n < 80)
		my_mlx_pixel_put(mlx, x, y, 0xCEE6DF);
	if (n >= 80 && n <= 90)
		my_mlx_pixel_put(mlx, x, y, 0xDEEAE7);
	if (n > 90 && n <= 100)
		my_mlx_pixel_put(mlx, x, y, 0xEEEEEE);
}

void	mandelbrot(t_fractol *mlx, int x, int y, double cr, double ci)
{
	int		n;	
	double	zr;
	double	zi;
	double	tmp;
	int		is_in_set;

	zr = 0;
	zi = 0;
	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	if (is_in_set == 1)
		my_mlx_pixel_put(mlx, x, y, 0x000000);
	else
		put_color(mlx, x, y, n);
}
