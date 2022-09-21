/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:13:47 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/21 09:47:34 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *mlx, int x, int y, double zr, double zi)
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
		my_mlx_pixel_put(mlx, x, y, 0x000000);
	else
		my_mlx_pixel_put(mlx, x, y, 0xFFFFFF);
}
