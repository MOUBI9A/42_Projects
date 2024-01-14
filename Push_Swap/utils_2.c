/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:43:58 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 01:19:26 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_set(void *src, unsigned char val, int size)
{
	unsigned char	*b_src;
	int				i;

	b_src = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		b_src[i] = val;
		i++;
	}
}

void	ft_first_check(char *all)
{
	int	i;

	i = 0;
	while (all[i] != '\0')
	{
		if (all[i])
		{
			if ((all[i] >= '0' && all[i] <= '9')
				|| all[i] == ' ' || all[i] == '-'
				|| all[i] == '+')
			i++;
			else
			{
				free(all);
				ft_err();
			}
		}
	}
}

void	ft_second_check(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < calc_size(args))
	{
		if ((args[i][0] == '-' || args[i][0] == '+')
			&& ft_isdigit(args[i][1]) == 0)
			ft_err();
		j = 0;
		if ((args[i][0] == '-' || args[i][0] == '+')
			&& ft_isdigit(args[i][1]) == 1)
				j++;
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0)
				ft_err();
			j++;
		}
		i++;
	}
}
