/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:01:24 by ikoukou           #+#    #+#             */
/*   Updated: 2021/12/22 13:05:28 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char c, int *len)
{
	write (1, &c, 1);
	*len += 1;
}

char	*put_str(char *str, int *len)
{
	int	i;

	if (!str)
		return (put_str("(null)", len));
	i = 0;
	while (str[i])
	{
		put_char(str[i], len);
		i++;
	}
	return (0);
}

void	put_id(int nb, int *len)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		put_char('-', len);
		n = -n;
	}
	if (n > 9)
	{
		put_id(n / 10, len);
		put_id(n % 10, len);
	}
	else
	{
		put_char(n + '0', len);
	}
}

void	put_uu(unsigned int nb, int *len)
{
	unsigned long int	u;

	u = nb;
	if (u > 9)
	{
		put_uu(u / 10, len);
		put_uu(u % 10, len);
	}
	else
	{
		put_char(u + '0', len);
	}
}
