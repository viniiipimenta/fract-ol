/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:52:03 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/19 12:59:12 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./minilib/mlx.h"
# include <unistd.h>
# define MAX_ITERATIONS 80 
# define WIDTH 900
# define HEIGHT 900

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
}	t_fractol;

void	draw_fractal(t_fractol *f, int arg);
void	mandelbrot(t_fractol *f, int x, int y, double cr, double ci);
#endif
