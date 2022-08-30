/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:31:06 by mpimenta          #+#    #+#             */
/*   Updated: 2022/08/30 13:24:54 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilib/mlx.h"

int main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1080, 920, "Fract-ol");
	mlx_string_put (mlx, window, 540, 460, 0xFFFFFF, "teste");
	mlx_loop(mlx);
	return (0);
}
