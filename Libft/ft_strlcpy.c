/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:43 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:09:24 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

// Function to copy a string from src to dst with a given size
// Returns the length of the source string
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i = 0;

	// If size is 0, return the length of src
	if (size == 0)
		return ft_strlen(src);

	// Copy characters from src to dst until size - 1 or '\0' is reached
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}

	// Add null terminator to the end of dst
	dst[i] = '\0';

	// Return the length of src
	return ft_strlen(src);
}




// int main()
// {
// 	char src[] = "Hello, world!";
// 	char dst[20];

// 	// Test case 1: Copy src to dst with size 10
// 	ft_strlcpy(dst, src, 10);
// 	printf("Test case 1: dst = %s\n", dst);

// 	// Test case 2: Copy src to dst with size 5
// 	ft_strlcpy(dst, src, 5);
// 	printf("Test case 2: dst = %s\n", dst);

// 	// Test case 3: Copy src to dst with size 0
// 	ft_strlcpy(dst, src, 0);
// 	printf("Test case 3: dst = %s\n", dst);

// 	return 0;
// }
