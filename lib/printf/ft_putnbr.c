/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:10:46 by tidebonl          #+#    #+#             */
/*   Updated: 2025/10/28 12:59:20 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int fd, int *count)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	else if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		(*count) += 10;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', fd, &(*count));
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr((n / 10), fd, &(*count));
		ft_putchar((n % 10) + '0', fd, &(*count));
	}
	else
		ft_putchar((n + '0'), fd, &(*count));
}

void	ft_putnbr_unsigned(unsigned int n, int fd, int *count)
{
	if (n == 4294967295)
	{
		write(fd, "4294967295", 10);
		(*count) += 10;
		return ;
	}
	if (n > 9)
	{
		ft_putnbr((n / 10), fd, &(*count));
		ft_putchar((n % 10) + '0', fd, &(*count));
	}
	else
		ft_putchar((n + '0'), fd, &(*count));
}

void	ft_putnbr_hexa(unsigned long n, int *count, char *base)
{
	if (n >= 16)
	{
		ft_putnbr_hexa((n / 16), &(*count), base);
		write(1, &base[n % 16], 1);
		(*count)++;
	}
	else
	{
		write(1, &base[n % 16], 1);
		(*count)++;
	}
}
