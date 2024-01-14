/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gv_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:03:41 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:14:58 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_gv_line(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
		i++;
	return (i);
}

void	ft_check_newlines(char	*str)
{
	size_t		i;

	i = 0;
	if (str[0] == '\n')
	{
		write(2, "ERR\n", 4);
		free(str);
		exit(1);
	}
	while (i < ft_strlen(str))
	{
		if (i + 1 < ft_strlen(str) && str[i] == '\n' && str[i + 1] == '\n' )
		{
			write(2, "ERR\n", 4);
			free(str);
			exit(1);
		}
		i++;
	}
}
