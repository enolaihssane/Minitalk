/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_cnvrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:25:56 by ikoukou           #+#    #+#             */
/*   Updated: 2021/12/22 13:09:23 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_x(unsigned long int n, int *len)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (n <= 15)
		put_char(tab[n], len);
	if (n > 15)
	{
		put_x(n / 16, len);
		put_x(n % 16, len);
	}
}

void	put_x_upper(unsigned int n, int *len)
{
	char	*tab;

	tab = "0123456789ABCDEF";
	if (n <= 15)
		put_char(tab[n], len);
	if (n > 15)
	{
		put_x_upper(n / 16, len);
		put_x_upper(n % 16, len);
	}
}

void	put_p(unsigned long int ptr, int *len)
{
	unsigned long long int	p;

	p = ptr;
	put_str("0x", len);
	put_x(p, len);
}
