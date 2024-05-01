/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:54:47 by saandria          #+#    #+#             */
/*   Updated: 2024/05/01 15:57:39 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
/*****client*****/
void	send_sig(char c, int pid, int size);
void	to_char(int c, int pid);
void	get_char(char *str, int pid);
/*****server*****/
void	handle(int sig);

#endif
