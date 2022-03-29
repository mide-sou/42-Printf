/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-sou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:01:20 by mide-sou          #+#    #+#             */
/*   Updated: 2022/03/29 15:58:59 by mide-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long	t_llu;

int	ft_printf(const char *s, ...);
int	ft_putchar(int s);
int	ft_putstr(char *s);
int	ft_putnbr(int n, int i);
int	ft_w_nu(t_llu n, t_llu base, int x, char s);

#endif