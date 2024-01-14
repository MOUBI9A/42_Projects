/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:54:04 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:39:38 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	int	lmakla;

	lmakla = ft_check_player(vars->splitmap, 'C');
	if ((keycode == 0 || keycode == 123)
		&& vars->splitmap[vars->yplayer][vars->i - 1] != '1')
		ft_move_a(vars, lmakla);
	if ((keycode == 2 || keycode == 124)
		&& vars->splitmap[vars->yplayer][vars->i + 1] != '1')
		ft_move_d(vars, lmakla);
	if ((keycode == 13 || keycode == 126)
		&& vars->splitmap[vars->yplayer - 1][vars->i] != '1')
		ft_move_w(vars, lmakla);
	if ((keycode == 1 || keycode == 125)
		&& vars->splitmap[vars->yplayer + 1][vars->i] != '1')
		ft_move_s(vars, lmakla);
	if (keycode == 53)
		ft_err2(vars);
	return (0);
}

void	ft_move_a(t_vars *vars, int lmakla)
{
	mlx_clear_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->pacman_img);
	vars->pacman_img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pacman_a.xpm", &vars->img_width, &vars->img_height);
	if (vars->splitmap[vars->yplayer][vars->i - 1] == 'E' && lmakla == 0)
		ft_err2(vars);
	if (vars->splitmap[vars->yplayer][vars-> i - 1] == 'E' && lmakla > 0)
		return ;
	vars->splitmap[vars->yplayer][vars->i] = '0';
	vars->i--;
	vars->splitmap[vars->yplayer][vars->i] = 'P';
	ft_putnbr_fd(++vars->steps, 1);
	write(1, " STEP\n", 6);
}

void	ft_move_d(t_vars *vars, int lmakla)
{
	mlx_clear_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->pacman_img);
	vars->pacman_img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pacman_d.xpm", &vars->img_width, &vars->img_height);
	if (vars->splitmap[vars->yplayer][vars->i + 1] == 'E' && lmakla == 0)
		ft_err2(vars);
	if (vars->splitmap[vars->yplayer][vars->i + 1] == 'E' && lmakla > 0)
		return ;
	vars->splitmap[vars->yplayer][vars->i] = '0';
	vars->i++;
	vars->splitmap[vars->yplayer][vars->i] = 'P';
	ft_putnbr_fd(++vars->steps, 1);
	write(1, " STEP\n", 6);
}

void	ft_move_w(t_vars *vars, int lmakla)
{
	mlx_clear_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->pacman_img);
	vars->pacman_img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pacman_w.xpm", &vars->img_width, &vars->img_height);
	if (vars->splitmap[vars->yplayer - 1][vars->i] == 'E' && lmakla == 0)
		ft_err2(vars);
	if (vars->splitmap[vars->yplayer - 1][vars->i] == 'E' && lmakla > 0)
		return ;
	vars->splitmap[vars->yplayer][vars->i] = '0';
	vars->yplayer--;
	vars->splitmap[vars->yplayer][vars->i] = 'P';
	ft_putnbr_fd(++vars->steps, 1);
	write(1, " STEP\n", 6);
}

void	ft_move_s(t_vars *vars, int lmakla)
{
	mlx_clear_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->pacman_img);
	vars->pacman_img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pacman_s.xpm", &vars->img_width, &vars->img_height);
	if (vars->splitmap[vars->yplayer + 1][vars->i] == 'E' && lmakla == 0)
		ft_err2(vars);
	if (vars->splitmap[vars->yplayer + 1][vars->i] == 'E' && lmakla > 0)
		return ;
	vars->splitmap[vars->yplayer][vars->i] = '0';
	vars->yplayer++;
	vars->splitmap[vars->yplayer][vars->i] = 'P';
	ft_putnbr_fd(++vars->steps, 1);
	write(1, " STEP\n", 6);
}
