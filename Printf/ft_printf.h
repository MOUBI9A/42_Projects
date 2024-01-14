/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:45:05 by hel-moue          #+#    #+#             */
/*   Updated: 2022/11/05 23:55:43 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *s, ...);
int	ft_putnbr_base(unsigned long n, unsigned long base);
int	ft_putnbr_base_m(unsigned long n, unsigned long base);
int	ft_putstr(const char *s);
int	ft_putnbr(long n);
int	ft_putchar(int s);

#endif