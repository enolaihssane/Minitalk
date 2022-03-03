/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:34:31 by ikoukou           #+#    #+#             */
/*   Updated: 2022/03/03 19:07:05 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
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
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("----- invalid number of arguments -----");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	send(pid, av[2]);
	return (0);
}
