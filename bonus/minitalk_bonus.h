/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:36:47 by saandria          #+#    #+#             */
/*   Updated: 2024/05/02 11:38:24 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
/*****client*****/
void	send_sig(char c, int pid, int size);
void	char_by_char(int c, int pid);
void	handle_client(int sig);
void	get_char(char *str, int pid);
/*****server*****/
void	handle_bonus(int sig, siginfo_t *info, void *content);

#endif
