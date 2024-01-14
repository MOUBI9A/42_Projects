/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:51:54 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:43:02 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_err(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->splitmap[y] != NULL)
	{
		free(vars->splitmap[y]);
		free(vars->cpymap[y]);
		y++;
	}
	free(vars->splitmap);
	free(vars->cpymap);
	write(2, "ERR - INVALID MAP\n", 19);
	exit (1);
}

int	ft_err2(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->splitmap[y] != NULL)
	{
		free(vars->splitmap[y]);
		y++;
	}
	free(vars->splitmap);
	mlx_destroy_image(vars->mlx, vars->lkharja_img);
	mlx_destroy_image(vars->mlx, vars->lmakla_img);
	mlx_destroy_image(vars->mlx, vars->mur_img);
	mlx_destroy_image(vars->mlx, vars->pacman_img);
	mlx_destroy_window(vars->mlx, vars->window);
	free(vars->mlx);
	exit (0);
	return (0);
}
