/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:32 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 20:58:23 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

/*
** The ft_bzero function sets the first 'n' bytes of the memory area pointed to by 's' to zero.
** It is equivalent to memset(s, 0, n).
** 
** Parameters:
** - s: Pointer to the memory area to be zeroed.
** - n: Number of bytes to be zeroed.
** 
** Return:
** - The pointer to the memory area 's'.
*/

// ttih implementation uses ft_memset function to set the memory area to zero.
void	*ft_bzero_mem(void *s, size_t n)
{
	return (ft_memset(s, '\0', n));
}

// This implementation uses a while loop to set the memory area to zero.
void	*ft_bzero(void *s, size_t n)
{
	unsigned char *ptr = (unsigned char *)s;

	while (n--)
		*ptr++ = 0;
	return s;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>


// int main(void)
// {
// 	char str[100];

// 	printf("Enter a string: ");
// 	fgets(str, sizeof(str), stdin);

// 	printf("Before ft_bzero: %s\n", str);
// 	ft_bzero(str, strlen(str));
// 	printf("After ft_bzero: %s\n", str);
// 	printf("if the string is empty, ft_bzero works correctly.\n");

// 	return 0;
// }
