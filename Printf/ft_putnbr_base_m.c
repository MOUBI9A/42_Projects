/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_m.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:04:05 by hel-moue          #+#    #+#             */
/*   Updated: 2022/11/06 00:18:21 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_m(unsigned long n, unsigned long base)
{
	int		ret;
	char	*set;

	set = "0123456789ABCDEF";
	ret = 0;
	if (n >= base)
		ret = ret + ft_putnbr_base_m(n / base, base);
	ret = ret + ft_putchar(set[(n % base)]);
	return (ret);
}
