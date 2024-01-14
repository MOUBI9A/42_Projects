/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_bottom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:20:30 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:14:47 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_top_bottom(t_vars *vars, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
		i++;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1')
			ft_err(vars);
		j++;
	}
	j = 0;
	while (map[i - 1][j] != '\0')
	{
		if (map[i - 1][j] != '1')
			ft_err(vars);
		j++;
	}
}
