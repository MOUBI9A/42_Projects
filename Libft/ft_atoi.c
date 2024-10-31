/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:07 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 02:55:45 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_atoi function converts the initial portion of the string pointed to by
** str to int representation.
** It skips any white space characters until the first non-white space character
** is found. Then, it checks if the first non-white space character is a sign
** character ('-' or '+'). If it is, it sets the sign accordingly.
** Finally, it converts the remaining characters into an integer by multiplying
** the previous result by 10 and adding the current digit.
** The function returns the converted integer.
*/

int skipspace(const char *str, int i) // Function to skip white space characters
{
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		return 1;
	return 0;
}


int ft_atoi(const char *str)
{
	if (!str)
		return 0;

	int i = 0;
	int sng = 1;
	int rest = 0;

	while (skipspace(str, i)) // Skip white space characters
		i++;
	if (str[i] == '-' || str[i] == '+') // Check if the first character is a sing 
	{
		sng = (str[i] == '-') ? -1 : 1; // Set the sign accordingly 
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9') // Convert the remaining characters to an integer
	{
		rest = (rest * 10) + (str[i] - '0'); // Multiply the previous result by 10 and add the current digit
		i++;
	}

	return rest * sng;
}

// #include <stdio.h>
// #include "libft.h"

// int main(void)
// {
// 	char input[100];
// 	printf("Enter a string: ");
// 	fgets(input, sizeof(input), stdin);
// 	int result = ft_atoi(input);
// 	printf("Converted integer: %d\n", result);
// 	return 0;
// }

