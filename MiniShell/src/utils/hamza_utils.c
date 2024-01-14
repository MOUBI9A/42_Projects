/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hamza_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:08:20 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:08:21 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

size_t	ft_strlen_helmoue(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strcspn_helmoue(const char *str, const char *reject)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (str[len] != '\0')
	{
		i = 0;
		while (reject[i] != '\0')
		{
			if (str[len] == reject[i])
				return (len);
			i++;
		}
		len++;
	}
	return (len);
}

void	print2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		printf("[%d]%s", i, str[i]);
		i++;
	}
	printf("\n");
}
