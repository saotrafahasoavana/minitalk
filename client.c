/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:54:23 by saandria          #+#    #+#             */
/*   Updated: 2024/05/01 15:57:57 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	send_sig(char c, int pid, int size)
{/*
	int	i;

	i = 0;
	while (bin[i])
	{
		if (bin[i] == '0')
			kill(pid, SIGUSR1);
		else if (bin[i] == '1')
			kill(pid, SIGUSR2);
		usleep(42);
		i++;
	}*/
	if ((c >> size) & 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
}

void	to_char(int c, int pid)
{
	/*int		i;
	char	*bin;

	bin = malloc(sizeof(char) * 9);
	bin[8] = '\0';
	i = 7;
	while(c != 0)
	{
		bin[i] = (c % 2) + '0';
		c /= 2;
		i--;
	}
	bin[i] = 0;
	send_sig(bin, pid);
	free(bin);*/
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
		to_char(str[i], pid);
		i++;
	}
	to_char('\0', pid);
}

int	main(int argc, char *argv[])
{
	int		pid;

	pid = ft_atoi(argv[1]);
	get_char(argv[2], pid);
}
