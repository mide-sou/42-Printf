/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:53:47 by mide-sou          #+#    #+#             */
/*   Updated: 2022/03/31 12:05:06 by mide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_arg(va_list args, const char *s, int i)
{
	if (s[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (s[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s[i + 1] == 'p')
		return (ft_putstr("0x") + write_nu(va_arg(args, t_llu), 16, 0, 'x'));
	else if (s[i + 1] == 'd' || (s[i + 1] == 'i'))
		return (ft_putnbr(va_arg(args, int), 0));
	else if (s[i + 1] == 'u')
		return (write_nu((t_llu)va_arg(args, unsigned int), 10, 0, 'x'));
	else if (s[i + 1] == 'x')
		return (write_nu((t_llu)va_arg(args, unsigned int), 16, 0, 'x'));
	else if (s[i + 1] == 'X')
		return (write_nu((t_llu)va_arg(args, unsigned int), 16, 0, 'X'));
	else if (s[i + 1] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	int		sum;

	va_start(args, s);
	sum = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			sum += type_arg(args, s, i);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			sum++;
		}
		i++;
	}
	va_end(args);
	return (sum);
}

/* int	main()
{
	char	str[10] = "ola";
	printf("%d", printf("5%", 5));
	return 0;
} */