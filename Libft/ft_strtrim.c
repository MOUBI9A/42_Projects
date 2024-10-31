/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:59 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 02:46:03 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** The ft_strtrim() function allocates and returns a copy of 's1' with the characters
** specified in 'set' removed from the beginning and the end of the string.
** The function uses ft_strchr() to check if the character is in the set.
** The function then uses ft_substr() to return the substring from the first non-matching
** character to the last non-matching character.
** Returns the trimmed string or NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;

	first = 0;
	last = (int)ft_strlen(s1);
	if (!s1 || (s1[0] == '\0' && !set)) // If the string is empty, return NULL
		return (NULL);
	while (s1[first] && ft_strchr(set, s1[first])) // Find the first non-matching character from the set
		first++;
	while (ft_strchr(set, s1[last]) && last > 0) // Find the last non-matching character from the set
		last--;
	return (ft_substr(s1, first, (last - first) + 1)); // Return the substring from first to last
}


// int main()
// {
// 	// Test cases
// 	char *s1 = "   hello world   ";
// 	char *set = " ";
// 	char *trimmed = ft_strtrim(s1, set);
// 	printf("Original: \"%s\"\n", s1);
// 	printf("Trimmed: \"%s\"\n", trimmed);
// 	free(trimmed);

// 	s1 = "abcde";
// 	set = "xyz";
// 	trimmed = ft_strtrim(s1, set);
// 	printf("Original: \"%s\"\n", s1);
// 	printf("Trimmed: \"%s\"\n", trimmed);
// 	free(trimmed);

// 	s1 = "   ";
// 	set = " ";
// 	trimmed = ft_strtrim(s1, set);
// 	printf("Original: \"%s\"\n", s1);
// 	printf("Trimmed: \"%s\"\n", trimmed);
// 	free(trimmed);

// 	return 0;
// }
