/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:04:04 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/17 04:00:11 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

size_t	ft_strspn(const char *str, const char *charset)
{
	size_t	count;

	count = 0;
	while (*str && ft_strchr(charset, *str) != NULL)
	{
		++count;
		++str;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

void	ft_strtok_utils(char *tokenend, char *lasttoken)
{
	if (*tokenend != '\0') 
	{
		*tokenend = '\0';
		lasttoken = tokenend + 1;
	}
	else
		lasttoken = NULL;
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*lasttoken;
	char		*tokenend;

	lasttoken = NULL;
	if (str == NULL)
		str = lasttoken;
	if (*str == '\0')
	{
		lasttoken = NULL;
		return (NULL);
	}
	str += ft_strspn(str, delim);
	if (*str == '\0')
	{
		lasttoken = NULL;
		return (NULL);
	}
	tokenend = str + ft_strcspn_helmoue(str, delim);
	ft_strtok_utils(tokenend, lasttoken);
	return (str);
}

char	**copy_double_ptr(char **env)
{
	int		envsize;
	char	**copy;
	int		i;

	i = 0;
	envsize = len_env(env);
	copy = (char **)malloc(sizeof(char *) * (envsize + 1));
	while (env[i])
	{
		copy[i] = ft_strdup_wbousfir(env[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
