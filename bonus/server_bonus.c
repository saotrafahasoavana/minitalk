/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:58:24 by saandria          #+#    #+#             */
/*   Updated: 2024/05/02 11:41:12 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_bonus(int sig, siginfo_t *info, void *content)
{
	static unsigned char	c;
	static int				size;

	if (sig == SIGUSR2)
		c |= (1 << (7 - size));
	size++;
	if (size == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n\033[1;93m [NEW MESSAGE] : \033[0m");
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &c, 1);
		c = 0;
		size = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_bonus;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("error");
		return (0);
	}
	ft_printf("\033[1;91m [PID] :  \033[0m%d\n", getpid());
	ft_printf("\n\033[1;93m [NEW MESSAGE] : \033[0m");
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
}
