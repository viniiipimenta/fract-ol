/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:52:03 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/20 14:05:47 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./minilib/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# define MAX_ITERATIONS 80 
# define WIDTH 900
# define HEIGHT 700

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
void	julia(t_fractol *mlx, int x, int y, double zr, double zi);
void	error(void);
double	ft_atod(char *str);
int		handle_mouse(int button, int x, int y, t_fractol *mlx);
int		ft_strncmp(const char *s1, const char *s2,size_t n);
#endif
