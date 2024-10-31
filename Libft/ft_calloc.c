/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:38 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 20:58:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
** ft_calloc - Allocates memory for an array of elements and initializes them to 0.
** @param count: Number of elements to allocate.
** @param size: Size of each element.
** @return: Pointer to the allocated memory, or NULL if allocation fails.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);// Allocate memory for count * size bytes
	if (!(str))
		return (NULL);// Return NULL if allocation fails
	ft_bzero(str, (size * count)); // Initialize the allocated memory to 0
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
// 	int *arr;
// 	int i;

// 	arr = (int*)ft_calloc(5, sizeof(int)); // Allocate memory for 5 integers
// 	if (arr == NULL)
// 	{
// 		printf("Memory allocation failed\n");
// 		return 1;
// 	}

// 	// Print the allocated memory
// 	for (i = 0; i < 5; i++)
// 	{
// 		printf("%d ", arr[i]); // Should print 0 0 0 0 0
// 	}
// 	printf("\n");

// 	free(arr); // Free the allocated memory

// 	return 0;
// }