/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:25 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 01:15:41 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

#include "libft.h"
#include <stdio.h>

// Function to calculate the number of substrings to allocate memory
// based on the delimiter
static int lenalloc(const char *str, char c)
{
	int i;
	int perm;

	i = 0;
	perm = 0;
	while (*str)
	{
		if (*str != c && perm == 0)
		{
			perm = 1;
			i++;
		}
		else if (*str == c)
			perm = 0;
		str++;
	}
	return i;
}


// Function to split a string into substrings based on a delimiter
// and store them in an array of strings
// The function returns the array of strings or NULL if the allocation fails
char **ft_split(char const *s, char c)
{
    int i;
    int j;
    int indx;
    char **split;

    if (!s)
        return NULL;

    // Calculate the number of substrings and allocate memory
    i = lenalloc(s, c) + 1;
    split = (char **)ft_calloc(i, sizeof(char *)); // Allocate memory and initialize to 0 with ft_calloc
    if (!split)
        return NULL;
    i = -1;
    j = 0;
    indx = -1;
    while (++i <= (int)ft_strlen(s)) 
    {
        if (s[i] != c && indx < 0) // Find the start of the substring
            indx = i;
        else if ((s[i] == c || !s[i]) && indx > -1) // Find the end of the substring
        {
            // Extract the substring and store it in the split array using ft_substr
            split[j] = (char *)ft_substr(s, indx, i - indx); 
            if (!split[j]) // Check if ft_substr failed
            {
                // Free previously allocated memory
                while (j > 0)
                    free(split[--j]);
                free(split);
                return NULL;
            }
            j++;
            indx = -1;
        }
    }
    return split;
}


// int main()
// {
// 	char *str = "Hello,World,Split,Test";
// 	char **result = ft_split(str, ',');

// 	if (result)
// 	{
// 		int i = 0;
// 		while (result[i])
// 		{
// 			printf("%s\n", result[i]);
// 			i++;
// 		}
// 	}

// 	// Free the memory allocated for the split array
// 	free(result);

// 	return 0;
// }
