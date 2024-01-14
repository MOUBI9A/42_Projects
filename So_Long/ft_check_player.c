/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:04:04 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:19:14 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_player(char **map, char c)
{
	int	i;
	int	j;
	int	errplayer;

	j = 0;
	i = 0;
	errplayer = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				errplayer++;
			j++;
		}
		i++;
	}
	return (errplayer);
}
