/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:11 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:04:16 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

/*
** ft_memset - Fills a block of memory with a specified value.
** @param b: Pointer to the block of memory.
** @param c: Value to be set.
** @param len: Number of bytes to be set.
** @return: Pointer to the block of memory.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)b;
	while (i < len)
		str[i++] = (char)c;
	return b;
}


// int main()
// {
// 	char str[20] = "Hello, World!";
// 	printf("Before memset: %s\n", str);

// 	ft_memset(str, '*', 5);
// 	printf("After memset: %s\n", str); // Output: ***** World!

// 	return 0;
// }
