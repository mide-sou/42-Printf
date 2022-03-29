/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:06:00 by mide-sou          #+#    #+#             */
/*   Updated: 2022/03/29 15:59:51 by mide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int num)
{
	if (n == -2147483648)
			num += ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		num += ft_putnbr(-n, num);
		num++;
	}
	else if (n > 9)
	{
		num += ft_putnbr(n / 10, num);
		num += ft_putchar(n % 10 + '0');
	}
	else
		num += ft_putchar(n + '0');
	return (num);
}

int	ft_w_nu(t_llu n, t_llu base, int num, char s)
{
	if (s == 'x')
	{
		if (n > base - 1)
			num += ft_w_nu(n / base, base, num, s);
		write(1, &"0123456789abcdef"[n % base], 1);
	}
	else if (s == 'X')
	{
		if (n > base - 1)
			num += ft_w_nu(n / base, base, num, s);
		write(1, &"0123456789ABCDEF"[n % base], 1);
	}
	return (++num);
}
