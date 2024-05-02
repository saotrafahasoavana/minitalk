/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:54:23 by saandria          #+#    #+#             */
/*   Updated: 2024/05/02 11:46:38 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

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

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		ft_printf("error");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	get_char(argv[2], pid);
	return (0);
}
