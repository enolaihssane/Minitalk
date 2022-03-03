/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:44:17 by ikoukou           #+#    #+#             */
/*   Updated: 2021/12/22 13:09:39 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	choose_cnvrs(va_list arg, char c, int *len)
{
	if (c == 'c')
		put_char(va_arg(arg, int), len);
	if (c == 's')
		put_str(va_arg(arg, char *), len);
	if (c == 'u')
		put_uu(va_arg(arg, unsigned int), len);
	if (c == 'x')
		put_x(va_arg(arg, unsigned int), len);
	if (c == 'X')
		put_x_upper(va_arg(arg, unsigned int), len);
	if (c == 'i' || c == 'd')
		put_id(va_arg(arg, int), len);
	if (c == 'p')
		put_p(va_arg(arg, unsigned long int), len);
	if (c == '%')
		put_char('%', len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] != '%')
			put_char(format[i], &len);
		else
		{
			choose_cnvrs(arg, format[i + 1], &len);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
