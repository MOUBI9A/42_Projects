/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:06 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 22:01:38 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


#include <stdio.h>

/*
** ft_memcpy - Copy memory area
** @dst: Destination memory address
** @src: Source memory address
** @n: Number of bytes to copy
**
** This function copies @n bytes from memory area @src to memory area @dst.
** If @dst and @src overlap, behavior is undefined.
** Returns the original value of @dst.
*/


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}


// void	*ft_memcpy1(void *dst, const void *src, size_t n)
// {
// 	size_t	i;
// 	char	*str;
// 	char	*srcc;

// 	srcc = (char *)src;
// 	str = (char *)dst;
// 	i = 0;
// 	while (i++ < n)
// 		str[i] = srcc[i];
// 	dst = (void *)str;
// 	return (dst);
// }

// int	main(void)
// {
// 	char src[] = "Hello, world!";
// 	char dst[20];

// 	ft_memcpy(dst, src, sizeof(src));
// 	printf("Copied string: %s\n", dst);// Should print "Hello, world!"

// 	return (0);
// }
