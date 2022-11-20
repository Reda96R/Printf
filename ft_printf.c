/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:29:42 by rerayyad          #+#    #+#             */
/*   Updated: 2022/11/20 16:34:11 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printer(char c, va_list arg)
{
	int	l;

	l = 0;
	if (c == 'c')
		ft_putchar(va_arg(arg, int), &l);
	else if (c == '%')
		ft_putchar('%', &l);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), &l);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg, int), &l);
	else if (c == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef", &l);
	else if (c == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF", &l);
	else if (c == 'u')
		ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", &l);
	else if (c == 'p')
		ft_adress(va_arg(arg, unsigned long), &l);
	else
		ft_putchar(c, &l);
	return (l);
}

int	ft_printf(const char *format, ...)
{
	int		l;
	int		i;
	va_list	arg;

	va_start(arg, format);
	l = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			i++;
			if (!format[i])
				return (l);
			l += ft_printer(format[i], arg);
		}
		else
			ft_putchar(format[i], &l);
			i++;
	}
	va_end(arg);
	return (l);
}
#include<limits.h>
#include<stdio.h>
#include <fcntl.h>

int main()
{
// char b[5] = "hello";
//void *ptr;

// ft_printf("%c \n%s",'c', "test", 100, 10);
//ft_printf("\ntest\n");
//unsigned long i = (unsigned long)(-1);
//printf("%lu\n", i);
// int fd = open("txt", O_RDWR);
// for(int i = 0; i < 9000; i++	)
// 	write(fd, "%", 1);
// close(fd);
// fd = open("txt", O_RDONLY);
// char buff[10000];
// read(fd, buff, 9000);
// buff[8999] = 'd';
// buff[9000] = '\0';
ft_printf("\n: %d", ft_printf("%%%"));
printf("\n");
printf("\n: %d", printf("%%%"));
printf("\n");
//printf("\n%X", -1000);
}
