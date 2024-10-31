/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:30:48 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 20:59:14 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Function to check if a character is an alphabet
int ft_isalpha(int c)
{
	// Check if the character is within the range of uppercase or lowercase alphabets
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return 1; // Return 1 if it is an alphabet
	return 0; // Return 0 if it is not an alphabet
}

// #include <stdio.h>
// int main()
// {
// 	char ch;
// 	printf("Enter a character: ");
// 	scanf("%c", &ch);

// 	if (ft_isalpha(ch))
// 		printf("%c is an alphabet.\n", ch);
// 	else
// 		printf("%c is not an alphabet.\n", ch);

// 	return 0;
// }
