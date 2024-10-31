/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:57 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 02:29:50 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			str = (char *)s;
		s++;
	}
	if (str != NULL)
		return (str);
	else if (c == '\0')
		return ((char *)s);
	else
		return (NULL);
}
*/


/*
** ft_strrchr - Locate the last occurrence of a character in a string
** @s: The string to be searched
** @c: The character to be located
**
** This function returns a pointer to the last occurrence of the character 'c'
** in the string 's'. If the character is not found, it returns NULL.
*/
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s); // Find the length of the string
	while (len >= 0) // start from the end of the string and move backwards 
	{
		if (s[len] == (char)c) // Check if character matches
			return ((char *)(s + len)); // move the pointer to the location of the character and return it
		len--;
	}
	return (0);
}

// int	main(void)
// {
// 	const char *str = "Hello, world!";
// 	char *result;

// 	result = ft_strrchr(str, 'o');
// 	if (result != NULL)
// 		printf("Last occurrence of 'o': %s\n", result);
// 	else
// 		printf("Character not found.\n");

// 	result = ft_strrchr(str, 'z');
// 	if (result != NULL)
// 		printf("Last occurrence of 'z': %s\n", result);
// 	else
// 		printf("Character not found.\n");

// 	return (0);
// }
