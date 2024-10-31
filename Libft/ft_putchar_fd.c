/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:14 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 18:32:15 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

/*
** This function writes a single character to the specified file descriptor.
** It takes two parameters:
** - c: the character to be written
** - fd: the file descriptor to write to
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	char c;

// 	// Testing with stdin
// 	write(1, "Enter a character: ", 19);
// 	read(0, &c, 1);// Read a character from stdin
// 	ft_putchar_fd(c, 1);// Write the character to stdout
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }
