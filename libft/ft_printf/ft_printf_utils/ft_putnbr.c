/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:47:15 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/06/13 13:01:05 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	long	a;
	int		i;

	a = n;
	i = 0;
	if (a < 0)
	{
		i += ft_putchar('-');
		a = -a;
	}
	if (a >= 10)
	{
		i += ft_putnbr(a / 10);
		a %= 10;
		i += ft_putchar(a + '0');
	}
	else
	{
		i += ft_putchar(a + '0');
		return (i);
	}
	return (i);
}
