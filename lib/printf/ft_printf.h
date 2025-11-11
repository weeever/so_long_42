/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidebonl <tidebonl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:13:23 by tidebonl          #+#    #+#             */
/*   Updated: 2025/10/28 12:59:50 by tidebonl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *src, ...) __attribute__((format(printf, 1, 2)));
void	ft_putnbr(int n, int fd, int *count);
void	ft_putchar(char c, int fd, int *count);
void	ft_putstr(char *s, int fd, int *count);
void	ft_putnbr_unsigned(unsigned int n, int fd, int *count);
void	ft_putnbr_hexa(unsigned long n, int *count, char *base);
#endif
