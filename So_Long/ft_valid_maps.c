/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:00:18 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:14:40 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_valid_map(t_vars *vars)
{
	ft_top_bottom(vars, vars->splitmap);
	ft_check_length_width(vars, vars->splitmap);
	ft_left_right(vars, vars->splitmap);
	ft_valid_diff(vars, vars->splitmap);
	if ((ft_check_player(vars->splitmap, 'P') != 1
			|| ft_check_player(vars->splitmap, 'E') != 1
			|| ft_check_player(vars->splitmap, 'C') < 1))
		ft_err(vars);
}
