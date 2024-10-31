/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:33:04 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:13:17 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
** This function converts an uppercase letter to its corresponding lowercase letter.
** If the input character is not an uppercase letter, it remains unchanged.
** The function returns the converted character.
*/
int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return c;
}

// #include <stdio.h>
// int main()
// {
// 	int c;
// 	printf("Enter a character: ");
// 	c = getchar();
// 	printf("Original character: %c\n", c);
// 	printf("Converted character: %c\n", ft_tolower(c));
// 	return 0;
// }
