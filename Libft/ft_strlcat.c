/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:39 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 01:17:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>

/* 
** ft_strlcat - Concatenate strings with size restriction
** @dst: Destination string
** @src: Source string
** @dstsize: Size of the destination buffer
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	j;

	i = 0;
	srclen = (int)ft_strlen(src); // Calculate the length of the source string
	if (dstsize == 0) // If the destination size is 0, return the length of the source string
		return (srclen);
	j = (int)ft_strlen(dst);// Calculate the length of the destination string
	dstlen = (int)ft_strlen(dst); // Save the length of the destination string
	if (dstsize < dstlen) // If the destination size is less than the length of the destination string, return the sum of the source length and destination size
		return (srclen + dstsize);
	while (src[i] && j < dstsize - 1) // Copy the source string to the destination string until the end of the source string or the destination size
	{
		dst[j] = (char)src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dstlen + srclen);
}


// int main()
// {
// 	char dst[20] = "Hello";
// 	const char *src = " World!";
// 	size_t dstsize = sizeof(dst);

// 	// Concatenate src to dst using ft_strlcat
// 	size_t result = ft_strlcat(dst, src, dstsize);

// 	// Print the concatenated string and the result
// 	printf("Concatenated string: %s\n", dst);
// 	printf("Result: %zu\n", result);

// 	return 0;
// }
