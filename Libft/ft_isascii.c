/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:48 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 20:59:21 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// Function to check if a character is ASCII
int ft_isascii(int c)
{
	// ASCII characters range from 0 to 127
	if (c >= 0 && c <= 127)
		return 1; // Character is ASCII
	return 0; // Character is not ASCII
}


// #include <stdio.h>
// int main()
// {
// 	int c;

// 	printf("Enter a character: ");
// 	scanf("%d", &c);

// 	if (ft_isascii(c))
// 		printf("Character is ASCII.\n"); 
// 	else
// 		printf("Character is not ASCII.\n");

// 	return 0;
// }
