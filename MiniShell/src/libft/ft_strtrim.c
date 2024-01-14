/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousbaa <mbousbaa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20../08 18:32:59 by hel-moue          #+#    #+#             */
/*   Updated: 20../08 20:33:20 by mbousbaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*normm(const char *str, size_t start, size_t trimmedlength)
{
	size_t	length;
	char	*trimmedstr;

	trimmedstr = (char *)malloc((trimmedlength + 1) * sizeof(char));
	if (trimmedstr == NULL)
		return (NULL);
	length = -1;
	while (++length < trimmedlength)
		trimmedstr[length] = str[start + length];
	trimmedstr[trimmedlength] = '\0';
	free((void *)str);
	return (trimmedstr);
}

char	*ft_strtrim(const char *str)
{
	size_t	length;
	size_t	start;
	size_t	end;
	size_t	trimmedlength;
	char	*trimmedstr;

	if (str == NULL)
		return (NULL);
	length = 0;
	while (str[length] != '\0')
		length++;
	start = 0;
	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
		start++;
	end = length - 1;
	while ((end > start) && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n'))
		end--;
	trimmedlength = end - start + 1;
	trimmedstr = normm(str, start, trimmedlength);
	return (trimmedstr);
}
