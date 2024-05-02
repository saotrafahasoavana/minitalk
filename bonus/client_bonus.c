/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:39:27 by saandria          #+#    #+#             */
/*   Updated: 2024/05/02 11:42:33 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_sig(char c, int pid, int size)
{
	if ((c >> size) & 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

void	char_by_char(int c, int pid)
{
	int	size;

	size = 7;
	while (size >= 0)
	{
		send_sig(c, pid, size);
		size--;
		usleep(100);
	}
}

void	get_char(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_by_char(str[i], pid);
		i++;
	}
	char_by_char('\0', pid);
}

void	handle_client(int sig)
{
	ft_printf("received🫡\n");
}

int	main(int argc, char *argv[])
{
	int	pid_server;

	signal(SIGUSR1, handle_client);
	if (argc != 3)
	{
		ft_printf("error");
		return (0);
	}
	pid_server = ft_atoi(argv[1]);
	get_char(argv[2], pid_server);
}
