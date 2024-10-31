/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:57 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 00:56:03 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

/*
** Function to calculate the number of characters required to represent an integer.
** It handles negative numbers and zero separately.
*/
static int nbchar(int n)
{
	int i = 0;

	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/*
** Function to convert an integer to a string.
** It allocates memory for the string and handles negative numbers separately.
** It uses the nbchar function to calculate the number of characters required.
** It then converts the integer to a string by taking the remainder of the number
*/
char *ft_itoa(int n)
{
	long i = nbchar(n);
	char *rest;

	if (n == -2147483648)
		return (ft_strdup("-2147483648")); // Handle the minimum integer value
	rest = (char *)malloc(i + 1);
	if (rest == NULL)
		return (NULL);
	if (n < 0)
	{
		rest[0] = '-';
		n *= -1;
	}
	rest[i] = '\0';
	i--;
	if (n == 0)
		rest[i] = '0';
	while (n > 0)
	{
		// Convert using the remainder of the number divided by 10 and adding '0' to it to get the ASCII value of the digit character 
		// example: 42 % 10 = 2 + '0' = '2' , ascii exmple: 42 % 10 = 2 + 48 (ascii value of 0) = 50(ascii value of 2)
		rest[i] = (n % 10) + '0'; 
		n = n / 10;
		i--;
	}
	return (rest);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	int num1;

// 	printf("Enter a numbers: ");
// 	scanf("%d", &num1);
// 	char *str1 = ft_itoa(num1);
// 	printf("Number: %d, String: %s\n", num1, str1);
// 	free(str1);
// 	return 0;
// }
