/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:08 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 21:03:38 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
** ft_memmove: Copies 'len' bytes from 'src' to 'dst'.
** The memory areas may overlap.
** Returns a pointer to 'dst'.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;

	// If 'dst' and 'src' are both NULL, return NULL.
	if (!dst && !src)
		return (NULL);

	// If 'dst' is before 'src' in memory, use memcpy.
	if (dst < src)
		return (ft_memcpy(dst, src, len));

	// Copy 'len' bytes from 'src' to 'dst' in reverse order.
	while (len--)
		d[len] = s[len];

	return (dst);
}

/*
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	tmp[];

	if ((dst == NULL && src == NULL))
		return (dst);
	ft_bzero(tmp, len);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	tmp = NULL;
	return (dst);
}
*/