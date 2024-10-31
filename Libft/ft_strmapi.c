/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:50 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:15:33 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
** This function applies the function 'f' to each character of the string 's'
** and creates a new string with the results.
** The function 'f' takes two arguments: the index of the character and the character itself.
** The new string is allocated dynamically using ft_calloc.
** Returns the new string or NULL if allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}


// #include <stdio.h>
// #include <stdlib.h>

// /*
// ** Test function for ft_strmapi.
// ** Prints the transformed string.
// */
// void	test_strmapi(char const *s, char (*f)(unsigned int, char))
// {
// 	char *result = ft_strmapi(s, f);
// 	if (result)
// 	{
// 		printf("Transformed string: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Allocation failed.\n");
// 	}
// }

// /*
// ** Example usage of ft_strmapi.
// ** Transforms each character to uppercase.
// */
// char	uppercase_func(unsigned int index, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	printf("Original string: %s\n", str);
// 	test_strmapi(str, uppercase_func);
// 	return (0);
// }
