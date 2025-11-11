/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:59:29 by tidebonl          #+#    #+#             */
/*   Updated: 2025/10/28 12:59:51 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int fd, int *count)
{
	write (fd, &c, 1);
	(*count)++;
}

void	ft_putstr(char *s, int fd, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write (fd, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i], fd, &(*count));
			i++;
		}
	}
}
