/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:32:44 by saandria          #+#    #+#             */
/*   Updated: 2024/05/03 09:02:42 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *len);
void	ft_putstr(const char *s, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_put_u_nbr(unsigned long nb, int *len);
void	ft_put_low_hex(unsigned long n, int *len);
void	ft_put_up_hex(unsigned long n, int *len);
void	ft_putadd(void *p, int *len);
void	ft_format(char c, int *len, va_list args);
int		ft_printf(const char *s, ...);
char	*ft_strchr(const char *s, int c);
int		ft_len(const char *str);

#endif
