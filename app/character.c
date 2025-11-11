/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:37:41 by tidebonl          #+#    #+#             */
/*   Updated: 2025/11/11 17:20:20 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void character_init(mlx_t mlx)
{
	int w;
	int h;

	mlx.img = mlx_new_image_from_file(mlx.mlx, "lib/img/character.png", &w, &h);
	mlx_put_transformed_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0,
		 0.18, 0.18, 0);
}

void	move_key(mlx_t mlx)
{
	
}
