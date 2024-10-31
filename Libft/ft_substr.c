/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:33:02 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 02:40:18 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s && !start)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof (char)));
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	s = s + start;
	i = 0;
	while (*s != '\0' && i < len)
	{
		str[i] = *s;
		s++;
		i++;
	}
	return (str);
}
*/


/*
** The ft_substr function returns a newly allocated substring from the given string 's'.
** The substring starts at index 'start' and has a maximum length of 'len'.
** If 's' is NULL or 'start' is out of range, it returns NULL.
** If 'len' is greater than the remaining length of 's' starting from 'start',
** the substring will be truncated to match the remaining length.
** The returned substring is allocated using ft_calloc and should be freed by the caller.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!(s) && !(start))// If s is NULL and start is 0, return NULL
		return (NULL);
	if (start >= ft_strlen(s))// If start is greater than the length of s, return an empty string
		return (ft_calloc(1, sizeof (char)));// Allocate memory for an empty string and return it
	if (len > ft_strlen(s) - start)// If len is greater than the remaining length of s starting from start
		len = ft_strlen(s) - start;// Set len to the remaining length of s starting from start
	p = ft_calloc((len + 1), sizeof (char));// Allocate memory for the substring 
	if (!p)
		return (NULL);
	s = s + start;// Move the pointer to the start index
	ft_memmove(p, s, len);// Copy len characters from s to p
	return (p);
}

// int	main(void)
// {
// 	char *str = "Hello, World!";
// 	char *substr = ft_substr(str, 7, 5);
// 	printf("Substring: %s\n", substr);
// 	free(substr);

// 	substr = ft_substr(str, 0, 5);
// 	printf("Substring: %s\n", substr);
// 	free(substr);

// 	substr = ft_substr(str, 13, 5);
// 	printf("Substring: %s\n", substr);
// 	free(substr);

// 	substr = ft_substr(NULL, 0, 5);
// 	printf("Substring: %s\n", substr);
// 	free(substr);

// 	return (0);
// }

