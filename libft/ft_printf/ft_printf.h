/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:04:54 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/06/13 12:45:49 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

int				ft_putadress(void *format);
int				ft_puthexa(unsigned long n, char format);
int				ft_putunsigned(unsigned long n);
int				ft_printf(const char *str, ...);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_putstr(const char *s);
int				ft_putchar(char c);
int				ft_putnbr(int n);
char			*ft_strchr(char const *s, int c);
void			ft_putstr_fd(char *s, int fd);
unsigned long	ft_strlen(const char *s);
long			ft_abs(long n);

#endif