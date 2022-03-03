/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:17:05 by ikoukou           #+#    #+#             */
/*   Updated: 2022/03/03 19:07:49 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static char	chr = 0xff;
	static int	bit;

	if (sig == SIGUSR1)
		chr = chr | 128 >> bit;
	else if (sig == SIGUSR2)
		chr = chr ^ 128 >> bit;
	bit++;
	if (bit == 8)
	{
		write (1, &chr, 1);
		bit = 0;
		chr = 0xff;
	}
}

int	main(int ac, char **av)
{
	ft_printf("\n%d\n\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}