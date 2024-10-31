/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:03 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:14:24 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

/*
** ft_memcmp - Compare two memory areas
** @s1: First memory area
** @s2: Second memory area
** @n: Number of bytes to compare
**
** This function compares the first @n bytes of the memory areas @s1 and @s2.
** It returns an integer less than, equal to, or greater than zero if the first
** differing byte is less than, equal to, or greater than the corresponding byte
** in @s2, respectively. If @n is zero, the function always returns zero.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1 = (const unsigned char *)s1;
	const unsigned char	*ss2 = (const unsigned char *)s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
