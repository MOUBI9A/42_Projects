/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:33:02 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/09 02:40:18 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s && !start)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof (char)));
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	s = s + start;
	i = 0;
	while (*s != '\0' && i < len)
	{
		str[i] = *s;
		s++;
		i++;
	}
	return (str);
}
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!(s) && !(start))
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof (char)));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	p = ft_calloc((len + 1), sizeof (char));
	if (!p)
		return (NULL);
	s = s + start;
	ft_memmove(p, s, len);
	return (p);
}
