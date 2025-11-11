/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:31:59 by tidebonl          #+#    #+#             */
/*   Updated: 2025/11/11 16:39:47 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(void)
{
	mlx_t mlx;
	int i = 0;
	mlx_window_create_info info = {0};

	info.title = "so_long";
	info.width = 1280;
	info.height = 720;
	info.is_resizable = false;

	mlx.mlx = mlx_init();

	mlx.win = mlx_new_window(mlx.mlx, &info);
	character_init(mlx);
	mlx_loop(mlx.mlx);
}
