/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:32:39 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 01:17:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	j;

	i = 0;
	srclen = (int)ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	j = (int)ft_strlen(dst);
	dstlen = (int)ft_strlen(dst);
	if (dstsize < dstlen)
		return (srclen + dstsize);
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = (char)src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dstlen + srclen);
}
