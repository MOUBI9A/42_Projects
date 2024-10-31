/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:52 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:14:08 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// Function to check if a character is a digit
int ft_isdigit(int c)
{
	// Check if the character is between '0' and '9'
	if (c >= '0' && c <= '9')
		return 1; // Return 1 if it is a digit
	return 0; // Return 0 if it is not a digit
}

// #include <stdio.h>
// int main()
// {
// 	char input;
// 	printf("Enter a character: ");
// 	scanf("%c", &input);

// 	// Check if the input character is a digit
// 	if (ft_isdigit(input))
// 		printf("%c is a digit.\n", input);
// 	else
// 		printf("%c is not a digit.\n", input);

// 	return 0;
// }
