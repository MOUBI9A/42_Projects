/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:37:22 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 03:37:22 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**remove_empty_str(char **str)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (str[i])
	{
		if (ft_strlen_helmoue(str[i]) != 0)
		{
			new[j] = ft_strdup(str[i]);
			free(str[i]);
			j++;
		}
		i++;
	}
	free(str);
	new[j] = NULL;
	return (new);
}
