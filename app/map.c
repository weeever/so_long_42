/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:40:46 by tidebonl          #+#    #+#             */
/*   Updated: 2025/11/12 13:14:47 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../lib/gnl/get_next_line.h"

char **malloc_tab(char **tab)
{
	int fd;
	int x_len[1024];
	int y_len;
	char *result;

	y_len = 0;
	fd = open("map.ber", O_RDONLY);
	result = get_next_line(fd);
	while (result != NULL)
	{
		x_len[y_len] = ft_strlen(result);
		y_len++;
		result = get_next_line(fd);
	}
	x_len[y_len] = -1;
	tab = malloc(sizeof(char *) * y_len + 1);
	y_len = 0;
	while (x_len[y_len] != -1)
	{
		tab[y_len] = malloc(sizeof(char) * (x_len[y_len] + 1));
		y_len++;
	}
	close(fd);
	return(tab);
}

char **map_in_tab(char **tab)
{
	int fd;
	char *result;
	int x;
	int y;

	y = 0;
	tab = malloc_tab(tab);
	fd = open("map.ber", O_RDONLY);
	result = get_next_line(fd);
	while (result != NULL)
	{
		x = 0;
		while (result[x] != '\0')
		{
			tab[y][x] = result[x];
			x++;
		}
		tab[y][x] = '\0';
		y++;
		result = get_next_line(fd);
	}
	close(fd);
	return (tab);
}
void	map_creator(char **tab)
{
	int x;
	int y;

	while (x )
}
int	main(void)
{
	char **tab;

	tab = map_in_tab(tab);
	map_creator(tab);
}
