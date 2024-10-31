/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:19 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 18:32:20 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

// Function to print an integer to a file descriptor
// The function uses recursion to print each digit of the integer
// The function handles negative numbers by printing a '-' sign
// The function converts the integer to a long to handle INT_MIN
void	ft_putnbr_fd(int n, int fd)
{
	long nb = n; // Convert the integer to a long

	// Handle negative numbers
	if (nb < 0)
	{
		write(fd, "-", 1); // Print '-' sign
		nb = -nb; // Make the number positive
	}

	// Recursive call to print each digit
	if (nb > 9)
		ft_putnbr_fd((nb / 10), fd); // Print the remaining digits

	// Print the last digit
	char digit = (nb % 10) + '0'; // Convert the digit to a character by adding '0' (48) to it
	write(fd, &digit, 1); // Print the digit
}


// int main()
// {
// 	// Test cases
// 	int num1 = 123;
// 	int num2 = -456;
// 	int num3 = 0;

// 	// Print the numbers using ft_putnbr_fd
// 	ft_putnbr_fd(num1, 1); // Output: 123
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(num2, 1); // Output: -456
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(num3, 1); // Output: 0
// 	write(1, "\n", 1);

// 	return 0;
// }
