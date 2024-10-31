/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:41 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 20:58:37 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to check if a character is alphanumeric
int	ft_isalnum(int c)
{
	// Check if the character is alphabetic or a digit
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1); // Return 1 if it is alphanumeric
	return (0); // Return 0 if it is not alphanumeric
}


// #include <stdio.h>

// int main() {
// 	char ch;

// 	printf("Enter a character: ");
// 	scanf("%c", &ch); // Input a character

// 	if (ft_isalnum(ch) == 1) // Check if the character is alphanumeric
// 		printf("%c is alphanumeric\n", ch);
// 	else
// 		printf("%c is not alphanumeric\n", ch);
// 	return 0;
// }
