/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:31:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/19 10:35:24 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractol f; // Structure for fract'ol variables

	f.mlx = mlx_init(); // Initialize mlx
	// Value of complex numbers on left edge of window:
	f.min_r = -2.0;
	// Value of complex numbers on right edge of window:
	f.max_r = 1.0;
	// Value of complex numbers on top edge of window:
	f.min_i = -1.5;
	// Value of complex numbers on bottom edge of window:
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	// Create window:
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract-ol");
	// Start fractal calculation:
	draw_fractal(&f);
	// mlx's infinite loop:
	mlx_loop(f.mlx);
}

