/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:03:26 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 17:20:15 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left_right(t_vars *vars, char **map)
{
	int	i;
	int	j;

	j = (ft_strlen(map[0]) - 1);
	if (ft_strlen(map[0]) > 42)
		ft_err(vars);
	i = -1;
	while (map[++i] != 0)
	{
		if (map[i][0] != '1')
			ft_err(vars);
	}
	i = -1;
	while (map[++i] != 0)
	{
		if (map[i][j] != '1')
			ft_err(vars);
	}
}
