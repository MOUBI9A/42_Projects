/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_wbousfir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:04:10 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/17 03:58:03 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*ft_strdup_wbousfir(char *src)
{
	int		i;
	int		length;
	char	*new;

	i = 0;
	length = 0;
	while (src[length])
		length++;
	new = malloc(sizeof(*new) * (length + 1));
	if (new != NULL)
	{
		while (src[i])
		{
			new[i] = src[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}

char	*ft_strdup_wbousfirr(const char *src)
{
	int		i;
	int		length;
	char	*new;

	i = 0;
	length = 0;
	while (src[length])
		length++;
	new = malloc(sizeof(*new) * (length + 1));
	if (new != NULL)
	{
		while (src[i])
		{
			new[i] = src[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
