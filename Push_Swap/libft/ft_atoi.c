/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:07 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 01:19:39 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int			i;
	int			sng;
	long long	rest;

	i = 0;
	sng = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sng = -1;
		i++;
	}
	rest = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		rest = (rest * 10) + ((char)str[i] - '0');
		i++;
	}
	if ((rest * sng) > INT_MAX || (rest * sng) < INT_MIN)
		ft_err();
	return (rest * sng);
}
