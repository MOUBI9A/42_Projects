/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 03:54:16 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:48:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_valid_diff(t_vars *vars, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if ((map[y][x] == 'P') || (map[y][x] == 'E')
				|| (map[y][x] == 'C')
				|| (map[y][x] == '0')
				|| (map[y][x] == '1'))
				x++;
			else
				free(vars);
		}
		y++;
	}
}

void	ft_valid_path(t_vars *vars)
{
	int	y;

	y = 0;
	ft_player(vars);
	ft_check_path(vars, vars->cpymap, vars->cpyx, vars->cpyy);
	while (vars->cpymap[y] != NULL)
	{
		if (ft_strchr(vars->cpymap[y], 'C') == 0)
			y++;
		else
			ft_err(vars);
	}
	y = 0;
	while (vars->cpymap[y] != NULL)
	{
		free(vars->cpymap[y]);
		y++;
	}
	free(vars->cpymap);
}

void	ft_check_path(t_vars *vars, char **cpymap, int x, int y)
{
	if (cpymap[y] == NULL || cpymap[y][x] == '\0')
		return ;
	if (x < 0 || x >= (int)ft_strlen(cpymap[0]) || y < 0
		|| y >= ft_gv_line(cpymap))
		return ;
	if (cpymap[y][x] == '1')
		return ;
	if (cpymap[y][x] == 'E')
		return ;
	cpymap[y][x] = '1';
	ft_check_path(vars, cpymap, x + 1, y);
	ft_check_path(vars, cpymap, x - 1, y);
	ft_check_path(vars, cpymap, x, y + 1);
	ft_check_path(vars, cpymap, x, y - 1);
}
