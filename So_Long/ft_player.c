/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:02:48 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:19:11 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(t_vars *vars)
{
	vars->yplayer = 0;
	vars->cpyy = 0;
	while (vars->splitmap[vars->yplayer] != '\0')
	{
		vars->i = 0;
		vars->cpyx = 0;
		while (vars->splitmap[vars->yplayer][vars->i] != '\0')
		{
			if ((char)vars->splitmap[vars->yplayer][vars->i] == 'P')
				return ;
			vars->i++;
			vars->cpyx++;
		}
		vars->yplayer++;
		vars->cpyy++;
	}
}
