/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:31:59 by tidebonl          #+#    #+#             */
/*   Updated: 2025/11/13 11:47:01 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(void)
{
	char **tab;

	mlx_t mlx;
	int i = 0;
	mlx_window_create_info info = {0};

	info.title = "so_long";
	info.width = 1280;
	info.height = 720;
	info.is_resizable = false;

	mlx.mlx = mlx_init();

	mlx.win = mlx_new_window(mlx.mlx, &info);
	tab = map_in_tab(tab);
	show_map(mlx, tab);
	mlx_loop(mlx.mlx);
}
