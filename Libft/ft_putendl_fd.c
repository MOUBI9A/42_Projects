/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:16 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 18:32:17 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putendl_fd - Writes a string followed by a newline to the given file
** descriptor.
** @s: The string to be written.
** @fd: The file descriptor on which to write.
*/
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!fd || !s) // Check if the file descriptor or string is NULL
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1); // Write each character of the string to the file descriptor
		i++;
	}
	write(fd, "\n", 1); // Write a newline character to the end of the string 
}




// #include <fcntl.h> 
// int	main(void)
// {
// 	char *str = "Hello, world!";

// 	// Testing with stdout
// 	ft_putendl_fd(str, 1);

// 	// Testing with a file descriptor
// 	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
// 	ft_putendl_fd(str, fd);
// 	close(fd);

// 	return (0);
// }
