/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:59:00 by ikoukou           #+#    #+#             */
/*   Updated: 2022/03/13 02:46:00 by ikoukou          ###   ########.fr       */
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

void	send(int pid, const char *str)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] & 128 >> j) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(800);
			j++;
		}
		if (str[i] == 0)
			break ;
		i++;
	}
}

void	server_response(int sig)
{
	(void)sig;
	write(1, "MESSAGE SENT SUCCESSFULLY", 25);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		write(1, "----- invalid number of arguments -----", 39);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, server_response);
	pid = ft_atoi(av[1]);
	send(pid, av[2]);
	return (0);
}
