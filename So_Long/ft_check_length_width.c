/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_length_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:04:13 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 18:49:41 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_length_width(t_vars *vars, char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
	{
		if (i > 22)
			ft_err(vars);
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			ft_err(vars);
	}
}
