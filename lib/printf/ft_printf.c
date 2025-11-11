/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:31:25 by tidebonl          #+#    #+#             */
/*   Updated: 2025/10/29 14:54:46 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hex(unsigned int n, char c, int *count, char *base)
{
	if (c == 'X')
	{
		base = "0123456789ABCDEF";
		ft_putnbr_hexa((unsigned long)n, &(*count), base);
	}
	else
		ft_putnbr_hexa((unsigned long)n, &(*count), base);
}

static void	ft_check_p(unsigned long n, int *count, char *base)
{
	if (n == 0)
	{
		write (1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	write (1, "0x", 2);
	(*count) += 2;
	ft_putnbr_hexa(n, &(*count), base);
}

static int	ft_check(const char *src, va_list lst, int count, int i)
{
	char	*base;

	base = "0123456789abcdef";
	while (src[i] != '\0')
	{
		if (src[i] == '%' && src[i + 1] == 'c' )
			(ft_putchar(va_arg(lst, int), 1, &count), i ++);
		else if (src[i] == '%' && src[i + 1] == 's')
			(ft_putstr(va_arg(lst, char *), 1, &count), i ++);
		else if (src[i] == '%' && (src[i + 1] == 'd' || src[i + 1] == 'i'))
			(ft_putnbr(va_arg(lst, int), 1, &count), i ++);
		else if (src[i] == '%' && src[i + 1] == 'u')
			(ft_putnbr_unsigned(va_arg(lst, unsigned int), 1, &count), i ++);
		else if (src[i] == '%' && src[i + 1] == 'p')
			(ft_check_p(va_arg(lst, unsigned long), &count, base), i ++);
		else if (src[i] == '%' && (src[i + 1] == 'x' || src[i + 1] == 'X'))
			(ft_hex(va_arg(lst, unsigned int), src[i + 1], &count, base), i ++);
		else if (src[i] == '%' && src[i + 1] == '%')
			(ft_putchar('%', 1, &count), i ++);
		else
			ft_putchar(src[i], 1, &count);
		i++;
	}
	return (count);
}

int	ft_printf(const char *src, ...)
{
	va_list	lst;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(lst, src);
	count = ft_check(src, lst, count, i);
	va_end(lst);
	return (count);
}
