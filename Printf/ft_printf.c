/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:52:03 by hel-moue          #+#    #+#             */
/*   Updated: 2022/11/06 02:50:14 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dir(const char s, int ret, va_list va)
{
	if (s == ('i') || s == ('d'))
		ret = ret + ft_putnbr(va_arg(va, int));
	if (s == 's')
			ret = ret + ft_putstr(va_arg(va, char *));
	if (s == 'c')
		ret += ft_putchar(va_arg(va, int));
	if (s == 'x')
		ret = ret + ft_putnbr_base(va_arg(va, unsigned int), 16);
	if (s == 'X')
		ret = ret + ft_putnbr_base_m(va_arg(va, unsigned int), 16);
	if (s == '%')
		ret += ft_putchar('%');
	if (s == 'u')
		ret = ret + ft_putnbr_base(va_arg(va, unsigned int), 10);
	if (s == 'p')
	{	
		ft_putstr("0x");
		ret = ret + 2 + ft_putnbr_base(va_arg(va, unsigned long), 16);
	}
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		ret;
	va_list	va;

	i = 0;
	ret = 0;
	va_start(va, s);
	while (s[i] != '\0')
	{		
		if (s[i] == '%')
		{
			i++;
			ret = ft_dir(s[i], ret, va);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			ret++;
			i++;
		}
	}
	return (ret);
}
