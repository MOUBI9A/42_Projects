/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:37 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 22:57:23 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Concatenates two strings and returns the result.
** If either of the input strings is NULL, returns NULL.
** The returned string must be freed by the caller.
** exmple: ft_strjoin("Hello, ", "world!") returns "Hello, world!"
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s1 || !s2) // Check if either of the input strings is NULL
		return (NULL);

	len = strlen(s1) + strlen(s2); // Calculate the length of the concatenated string (excluding the null terminator)
	str = (char *)ft_calloc((len + 1), sizeof(char)); // Allocate memory for the concatenated string using ft_calloc to initialize it to 0
	if (!str)
		return (NULL);

	i = 0;
	while (s1[i] != '\0') // Copy the first string to the concatenated string
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')// Copy the second string to the concatenated string
		str[i++] = s2[j++];

	return (str);
}



// int	main(void)
// {
// 	char *s1 = "Hello, ";
// 	char *s2 = "world!";
// 	char *result = ft_strjoin(s1, s2);

// 	if (result)
// 	{
// 		printf("Concatenated string: %s\n", result); // Output: Hello, world!
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Invalid input strings.\n");
// 	}

// 	return (0);
// }
