/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:52 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 18:32:53 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

/*
** ft_strncmp: Compare two strings up to a specified number of characters.
** @param s1: The first string to compare.
** @param s2: The second string to compare.
** @param n: The maximum number of characters to compare.
** @return: An integer less than, equal to, or greater than zero if s1 is found,
** respectively, to be less than, to match, or be greater than s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char *str1 = "Hello";
// 	const char *str2 = "Hello";
// 	const char *str3 = "World";
// 	const char *str4 = "Hell";
// 	const char *str5 = "Helloo";

// 	printf("Comparison result: %d\n", ft_strncmp(str1, str2, 5)); // 0
// 	printf("Comparison result: %d\n", ft_strncmp(str1, str3, 5)); // -15
// 	printf("Comparison result: %d\n", ft_strncmp(str1, str4, 5)); // 111
// 	printf("Comparison result: %d\n", ft_strncmp(str1, str5, 5)); // 0

// 	return (0);
// }
