/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:54:04 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:44:15 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_map_assist(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->splitmap[y] != NULL)
	{
		x = 0;
		while (vars->splitmap[y][x] != '\0')
		{
			if (vars->splitmap[y][x] == '1')
				mlx_put_image_to_window(vars->mlx,
					vars->window, vars->mur_img, (x * 60), (y * 60));
			if (vars->splitmap[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx,
					vars->window, vars->lmakla_img, (x * 60), (y * 60));
			if (vars->splitmap[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx,
					vars->window, vars->lkharja_img, (x * 60), (y * 60));
			if (vars->splitmap[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx,
					vars->window, vars->pacman_img, (x * 60), (y * 60));
			x++;
		}
		y++;
	}
}

int	printmap(t_vars *vars)
{
	print_map_assist(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	*c;

	if (argc != 2)
		return (write(2, "ERR\n", 4));
	c = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (c == NULL)
		return (write(2, "ERR\n", 4));
	if (ft_strlen(c) != 4)
		return (write(2, "ERR\n", 4));
	vars.steps = 0;
	vars.splitmap = ft_read_map(argv[1], vars.splitmap, &vars);
	ft_valid_map(&vars);
	ft_valid_path(&vars);
	vars.mlx = mlx_init();
	ft_img(&vars);
	mlx_loop_hook(vars.mlx, printmap, &vars);
	mlx_key_hook(vars.window, key_hook, &vars);
	mlx_hook(vars.window, 17, 0, ft_err2, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	ft_img(t_vars *vars)
{
	vars->winsizex = ft_strlen(vars->splitmap[0]) * 60;
	vars->winsizey = ft_gv_line(vars->splitmap) * 60;
	ft_player(vars);
	vars->window = mlx_new_window(vars->mlx, vars->winsizex,
			vars->winsizey, "PACMAN");
	vars->pacman_img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pacman_d.xpm", &vars->img_width, &vars->img_height);
	vars->mur_img = mlx_xpm_file_to_image(vars->mlx, "./textures/mur.xpm",
			&vars->img_width, &vars->img_height);
	vars->lmakla_img = mlx_xpm_file_to_image(vars->mlx, "./textures/lmakla.xpm",
			&vars->img_width, &vars->img_height);
	vars->lkharja_img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/lkherja.xpm", &vars->img_width, &vars->img_height);
}
