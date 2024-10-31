/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:27 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 03:00:55 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

/*
** The ft_strchr function searches for the first occurrence of the character c
** in the string s. It returns a pointer to the located character, or NULL if
** the character is not found.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c) // Check if the value of the character is equal to c
			return ((char *)s); // Return a pointer to the located character
		s++; // Move to the next character using pointer arithmetic  
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}


// int	main(void)
// {
// 	const char *str = "Hello, world!";
// 	int ch = 'o';
// 	char *result = ft_strchr(str, ch);

// 	if (result != NULL)
// 		printf("Character '%c' found at position: %ld\n", ch, result - str);
// 	else
// 		printf("Character '%c' not found\n", ch);

// 	return (0);
// }
