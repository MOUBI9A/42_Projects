/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:22 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 18:32:23 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

// Function to print a string to a file descriptor
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	// Check if file descriptor or string is NULL
	if (!fd || !s)
		return ;
	// Loop through each character of the string
	while (s[i] != '\0')
	{
		// Write each character to the file descriptor
		write(fd, &s[i], 1);
		i++;
	}
}

// int	main(void)
// {
// 	char *str = "Hello, world!";
// 	int fd = 1; // File descriptor for stdout

// 	// Test case: Print the string to stdout
// 	ft_putstr_fd(str, fd);

// 	return 0;
// }
