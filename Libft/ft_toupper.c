/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:33:06 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:13:24 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

// Function to convert lowercase characters to uppercase
int ft_toupper(int c)
{
	// Check if the character is a lowercase letter
	if (c >= 'a' && c <= 'z')
		c = c - 32; // Convert to uppercase by subtracting 32 from ASCII value

	return c;
}

// int main()
// {
// 	int ch;

// 	printf("Enter a character: ");
// 	ch = getchar();

// 	// Convert the character to uppercase
// 	ch = ft_toupper(ch);

// 	printf("Uppercase character: %c\n", ch);

// 	return 0;
// }
