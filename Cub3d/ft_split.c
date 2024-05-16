/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:32:17 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/16 12:57:01 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_split(char *s1, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = 0;
	j = 0;
	k = 0;
	str = (char **)ft_calloc(sizeof(char *), (ft_strlen(s1) + 1));
	while (s1[i])
	{
		if (s1[i] == c)
			i++;
		else
		{
			j = i;
			while (s1[j] && s1[j] != c)
				j++;
			str[k] = (char *)malloc(sizeof(char) * (j - i + 1));
			j = 0;
			while (s1[i] && s1[i] != c)
				str[k][j++] = s1[i++];
			str[k++][j] = '\0';
		}
	}
	return (str);
}
