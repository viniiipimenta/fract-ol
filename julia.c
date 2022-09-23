/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:13:47 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/22 12:34:55 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_julia(t_fractol *mlx, int x, int y, int n)
{
	if (n >= 0 && n <= 10)
		my_mlx_pixel_put(mlx, x, y, 0x002B5B);
	if (n > 10 && n < 20)
		my_mlx_pixel_put(mlx, x, y, 0x0B335E);
	if (n >= 20 && n <= 30)
		my_mlx_pixel_put(mlx, x, y, 0x163A60);
	if (n > 30 && n < 40)
		my_mlx_pixel_put(mlx, x, y, 0x2B4865);
	if (n >= 40 && n <= 50)
		my_mlx_pixel_put(mlx, x, y, 0x2A526D);
	if (n > 50 && n < 60)
		my_mlx_pixel_put(mlx, x, y, 0x285B75);
	if (n >= 60 && n <= 70)
		my_mlx_pixel_put(mlx, x, y, 0x256D85);
	if (n > 70 && n < 80)
		my_mlx_pixel_put(mlx, x, y, 0x5AA8AA);
	if (n >= 80 && n <= 90)
		my_mlx_pixel_put(mlx, x, y, 0x75C6BD);
	if (n > 90 && n <= 100)
		my_mlx_pixel_put(mlx, x, y, 0x8FE3CF);
}

void	julia(t_fractol *mlx, double zr, double zi)
{
	int		n;
	double	tmp;
	int		is_in_set;

	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = 2 * zr * zi + mlx->ki;
		zr = zr * zr - zi * zi + mlx->kr;
		zi = tmp;
	}
	if (is_in_set == 1)
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x000000);
	else
		put_color_julia(mlx, mlx->x, mlx->y, n);
}
