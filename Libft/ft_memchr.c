/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:59 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:01:27 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

/*
** ft_memchr - Locate byte in byte string
** @s: Pointer to the memory area
** @c: Byte to be located
** @n: Number of bytes to be searched
**
** This function searches for the first occurrence of the byte @c
** in the first @n bytes of the memory area pointed to by @s.
** It returns a pointer to the matching byte or NULL if the byte is not found.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}


// #include <stdio.h>

// int main(void)
// {
// 	char str[100];
// 	char *result;
// 	char search_char;

// 	printf("Enter a string without spaces: ");
// 	scanf("%s", str);
// 	printf("Enter a character to search: ");
// 	scanf(" %c", &search_char);
// 	// printf("String: %s\n", str);
// 	// Test case: Search for the entered character in str
// 	result = ft_memchr(str, search_char, sizeof(str));
// 	if (result != NULL)
// 		printf("Found '%c' at index %ld\n", search_char, result - str);
// 	else
// 		printf("Character '%c' not found\n", search_char);

// 	return 0;
// }
