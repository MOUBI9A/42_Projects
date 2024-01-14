/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20../08 18:32:25 by hel-moue          #+#    #+#             */
/*   Updated: 20../28 15:40:21 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include <stdio.h>

static int	lenalloc(const char *str, char c)
{
	int	i;
	int	perm;

	i = 0;
	perm = 0;
	while (*str)
	{
		if (*str != c && perm == 0)
		{
			perm = 1;
			i++;
		}
		else if (*str == c)
			perm = 0;
		str++;
	}
	return (i);
}

int	norm(const char *s, int i)
{
	if (s[i] == '\"')
	{
		i++;
		while (s[i] && s[i] != '\"')
			i++;
		i++;
	}
	else if (s[i] == '\'')
	{
		i++;
		while (s[i] && s[i] != '\'')
			i++;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		indx;
	char	**split;

	if (!s)
		return (NULL);
	i = (int)lenalloc(s, c) + 1;
	split = (char **)ft_calloc(i, sizeof(char *));
	i = -1;
	j = 0;
	indx = -1;
	while (++i <= (int)ft_strlen(s))
	{
		i = norm(s, i);
		if (s[i] != c && indx < 0)
			indx = i;
		else if ((s[i] == c || !s[i]) && indx > -1)
		{
			split[j++] = (char *)ft_substr(s, indx, i - indx);
			indx = -1;
		}
	}
	return (split);
}
