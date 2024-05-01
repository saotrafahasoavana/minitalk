/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:33:00 by saandria          #+#    #+#             */
/*   Updated: 2024/05/01 16:05:12 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	handle(int sig)
{
	static unsigned char c;
	static int	size;

	if (sig == SIGUSR2)
		c |= (1 << (7 - size));
	size++;
	if (size == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		write(1, &c, 1);
		c = 0;
		size = 0;
	}
}

int	main(void)
{
	ft_printf("\033[1;91m [PID] :  \033[0m%d\n" , getpid());
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	ft_printf("\033[1;89m [NEW MESSAGE] :  \033[0m");
	while (1)
	{
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	}
}
