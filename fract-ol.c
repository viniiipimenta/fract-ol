/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:31:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/08/30 12:52:27 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilib/mlx.h"

int main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 1080, 920, "Fract-ol");
	mlx_loop(mlx);
	return (0);
}
