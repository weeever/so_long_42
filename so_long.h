/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:13:23 by tidebonl          #+#    #+#             */
/*   Updated: 2025/11/11 16:39:44 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "lib/mlx_linux/includes/mlx.h"
# include "lib/mlx_linux/includes/mlx_extended.h"
# include "lib/mlx_linux/includes/mlx_profile.h"
# include <math.h>
# include <unistd.h>

typedef struct mlx
{
	mlx_context mlx;
	mlx_window win;
	mlx_image logo_png;
	mlx_image logo_jpg;
	mlx_image logo_bmp;
	mlx_image img;
} mlx_t;

void character_init(mlx_t mlx);

#endif
