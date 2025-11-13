/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:57:42 by tidebonl          #+#    #+#             */
/*   Updated: 2025/11/13 13:01:07 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_wall_at_pos(mlx_t mlx, char *wall, int pos_x, int pos_y)
{
	int w;
	int h;

	mlx.img = mlx_new_image_from_file(mlx.mlx, wall, &w, &h);
	mlx_put_transformed_image_to_window(mlx.mlx, mlx.win, mlx.img,
		pos_x, pos_y, 4, 4, 0);
}

void	put_up_map(mlx_t mlx, char **tab, int *y)
{
	int x;
	int i;

	i = 0;
	x = 0;
	put_wall_at_pos(mlx, "lib/img/L_Up_W.png", x, 0);
	while (tab[0][i + 1] != '\n')
	{
		i++;
		x += 64;
		put_wall_at_pos(mlx, "lib/img/M_Up_W.png", x, 0);
	}
	put_wall_at_pos(mlx, "lib/img/R_Up_W.png", x, 0);
}
void	put_mid_map(mlx_t mlx, char **tab, int *y)
{
	int i;
	int pos_y;
	int x;

	x = 0;
	pos_y = 0;
	i = 0;
	while (i++ != *y)
		pos_y += 64;
	i = 0;
	put_wall_at_pos(mlx, "lib/img/L_Mid_W.png", x, pos_y);
	while (tab[*y][i] != '\0')
	{
		i++;
		x += 64;
		if (tab[*y][i] == '0')
			put_wall_at_pos(mlx, "lib/img/floor.png", x, pos_y);
		else if (tab[*y][i] == '1' && tab[*y][i + 1] == '\n')
			put_wall_at_pos(mlx, "lib/img/R_Mid_W.png", x, pos_y);
		else if (tab[*y][i] == '1')
			put_wall_at_pos(mlx, "lib/img/wall.png", x, pos_y);
	}

}
void	put_down_map(mlx_t mlx, char **tab, int *y)
{
	int x;
	int i;
	int pos_y;

	pos_y = 0;
	i = 0;
	x = 0;
	while (i++ != *y)
		pos_y += 64;
		i = 0;
	put_wall_at_pos(mlx, "lib/img/L_Down_W.png", x, pos_y);
	while (tab[*y][i + 1] != '\n')
	{
		i++;
		x += 64;
		put_wall_at_pos(mlx, "lib/img/M_Down_W.png", x, pos_y);
	}
	put_wall_at_pos(mlx, "lib/img/R_Down_W.png", x, pos_y);
}

void	show_map(mlx_t mlx, char **tab)
{
	int x;
	int y;

	y = 0;
	x = 0;

	put_up_map(mlx, tab, &y);
	y++;
	while (tab[y +1] != NULL)
	{
		put_mid_map(mlx, tab, &y);
		y++;
	}
	put_down_map(mlx, tab, &y);
}
