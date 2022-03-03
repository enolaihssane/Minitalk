/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:04:57 by ikoukou           #+#    #+#             */
/*   Updated: 2022/03/03 19:06:34 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(const char *a)
{
	return (*a == '\t'
		|| *a == '\n'
		|| *a == '\v'
		|| *a == '\f'
		|| *a == '\r'
		|| *a == ' ');
}

int	ft_atoi(const char *str)
{
	char	*a;
	int		i;
	int		res;
	int		sign;

	a = (char *)str;
	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(&a[i]))
		i++;
	if (a[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (a[i] == '+')
		i++;
	while (a[i] >= '0' && a[i] <= '9')
		res = res * 10 + a[i++] - '0';
	return (res * sign);
}