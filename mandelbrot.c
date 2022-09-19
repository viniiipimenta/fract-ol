/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:10:12 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/19 11:04:10 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0x000000);
	else
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF);
}
