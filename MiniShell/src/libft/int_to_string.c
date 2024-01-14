/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:04:37 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:04:38 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	int_to_string_count_digits(int num)
{
	int	count;

	count = 1;
	while (1)
	{
		num /= 10;
		if (num == 0)
			break ;
		count++;
	}
	return (count);
}

char	*int_to_string_allocate_memory(int size)
{
	return ((char *)malloc(size + 1));
}

void	int_to_string_fill_string(char *str, int num, int numdigits)
{
	int	i;

	i = numdigits - 1;
	while (i >= 0)
	{
		str[i] = '0' + num % 10;
		num /= 10;
		i--;
	}
	str[numdigits] = '\0';
}

char	*int_to_string(int num)
{
	int		numdigits;
	char	*str;

	numdigits = int_to_string_count_digits(num);
	str = int_to_string_allocate_memory(numdigits);
	int_to_string_fill_string(str, num, numdigits);
	return (str);
}
