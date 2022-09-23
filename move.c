/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:49:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/09/21 13:25:16 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_fractol *mlx, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = mlx->max_r - mlx->min_r;
	center_i = mlx->max_i - mlx->min_i;
	if (direction == 'R')
	{
		mlx->min_r += center_r * distance;
		mlx->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		mlx->min_r -= center_r * distance;
		mlx->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		mlx->min_i -= center_i * distance;
		mlx->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		mlx->min_i += center_i * distance;
		mlx->max_i += center_i * distance;
	}
}
