/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:34 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:14:48 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

// Function to iterate over each character in a string and apply a given function

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	// Check if the string is NULL
	if (!s)
		return ;
	i = 0;
	while (s[i]) // Iterate over each character in the string
	{
		f(i, (s + i)); // Call the given function with the current index and character
		i++;
	}
}


// // Example function to print the index and character of a string
// void print_index_char(unsigned int index, char *c)
// {
// 	printf("Index: %u, Character: %c\n", index, *c);
// }

// int main()
// {
// 	char str[] = "Hello, World!";

// 	// Call ft_striteri with the print_index_char function
// 	ft_striteri(str, print_index_char);

// 	return 0;
// }
