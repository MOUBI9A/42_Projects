/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:30 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:07:38 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** The ft_strdup function duplicates a string.
** It allocates memory for the duplicate string and copies the content of the
** original string into it.
** If the allocation fails, it returns NULL.
** Otherwise, it returns a pointer to the duplicate string.
*/

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	len = strlen(s1); // Calculate the length of the original string
	str = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the duplicate string
	// you can also use ft_calloc(len + 1, sizeof(char)) to allocate memory and initialize to 0
	// and remove the last line of the function that adds the null terminator to the string
	if (!str)
		return (NULL); // Return NULL if memory allocation fails
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i]; // Copy each character from the original string to the duplicate string
		i++;
	}
	str[i] = '\0'; // Add the null terminator at the end of the duplicate string
	return (str); // Return the pointer to the duplicate string
}





// int	main(void)
// {
// 	char *original = "Hello, world!";
// 	char *duplicate = ft_strdup(original);
// 	if (duplicate)
// 	{
// 		printf("Original: %s\n", original);
// 		printf("Duplicate: %s\n", duplicate);
// 		free(duplicate); // Remember to free the allocated memory
// 	}
// 	return (0);
// }
