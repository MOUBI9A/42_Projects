/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:54 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:11:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

/*
** The ft_strnstr function finds the first occurrence of the substring 'needle'
** in the string 'haystack', up to 'len' characters. It returns a pointer to the
** beginning of the substring if found, or NULL otherwise.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	b;

	x = 0;
	b = 0;
	if (((char *)needle)[x] == '\0') // If needle is an empty string, return haystack
		return ((char *)haystack);
	while (x < len && haystack[x]) // Loop through the haystack string until the end or len
	{
		if (haystack[x] == needle[b]) // If the characters match, check the rest of the substring
		{
			while ((haystack[x + b] == needle[b] && haystack[x + b])// Loop through the substring
				&& (x + b) < len)
				b++;
			if (needle[b] == '\0')// If the entire substring is found, return the pointer
				return ((char *)haystack + x);
			else // Otherwise, reset the counter and continue searching 
				b = 0;
		}
		x++;
	}
	return (NULL);
}




// int	main(void)
// {
// 	const char *haystack = "Hello, world!";
// 	const char *needle = "world";
// 	char *result = ft_strnstr(haystack, needle, 13);
// 	if (result)
// 		printf("Substring found at index: %ld\n", result - haystack);
// 	else
// 		printf("Substring not found\n");
// 	return (0);
// }
