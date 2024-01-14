/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:57 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 00:56:03 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static	int	nbchar(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	i;
	char	*rest;

	i = nbchar(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	rest = (char *)malloc(i + 1);
	if (rest == NULL)
		return (NULL);
	if (n < 0)
	{
		rest[0] = '-';
		n *= -1;
	}
	rest[i] = '\0';
	i--;
	if (n == 0)
		rest[i] = '0';
	while (n > 0)
	{
		rest[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (rest);
}

// int main()
// {
// 	char *number = ft_itoa(-2147483648);
// 	printf("%s\n", number);
// 	return (0);
// }

/*
char	*ft_itoa(int n)
{
	int		i;
	long	cpy;
	char	*rest;

	cpy = (long)n;
	i = test(cpy);
	rest = malloc(i + 1);
	if (rest == 0)
		return (0);
	if (cpy < 0)
	{
		rest[0] = '-';
		cpy *= -1;
	}
	rest[i] = '\0';
	i--;
	if (cpy == 0)
		rest[i] = '0';
	while (cpy > 0)
	{
		rest[i] = (cpy % 10) + '0';
		cpy = cpy / 10;
	i--;
	}
	return (rest);
}
*/