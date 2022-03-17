/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:07:43 by ikoukou           #+#    #+#             */
/*   Updated: 2022/03/13 12:43:22 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void	reset(char *s, int *b, int pid)
{
	*s = 0xff;
	*b = 0;
	g_pid = pid;
}

void	handler(int sig, siginfo_t *siginfo, void *oact)
{
	static char	chr = 0xff;
	static int	bit;

	(void)oact;
	if (g_pid != siginfo->si_pid)
		reset(&chr, &bit, siginfo->si_pid);
	if (sig == SIGUSR1)
		chr = chr | 128 >> bit;
	else if (sig == SIGUSR2)
		chr = chr ^ 128 >> bit;
	bit++;
	if (bit == 8)
	{
		if (chr == '\0')
			kill(siginfo->si_pid, SIGUSR1);
		else
			write (1, &chr, 1);
		bit = 0;
		chr = 0xff;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write (1, "\n", 1);
	write (1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n\n", 2);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
