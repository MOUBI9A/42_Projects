/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:21:11 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 19:43:54 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_vars {
	void	*mlx;
	void	*window;
	char	**splitmap;
	int		winsizey;
	int		winsizex;
	int		img_width;
	int		img_height;
	void	*mur_img;
	void	*pacman_img;
	void	*lmakla_img;
	void	*lkharja_img;
	int		yplayer;
	int		i;
	int		lmakla;
	char	**cpymap;
	int		cpyx;
	int		cpyy;
	int		steps;
}				t_vars;

int		ft_check_player(char **map, char c);
void	ft_check_length_width(t_vars *vars, char **map);
void	ft_check_newlines(char *str);
void	ft_left_right(t_vars *vars, char **map);
void	ft_top_bottom(t_vars *vars, char **map);
int		key_hook(int keycode, t_vars *vars);
int		ft_gv_line(char **map);
char	**ft_read_map(char *argv, char	**splitmap, t_vars *vars);
void	ft_valid_map(t_vars *vars);
void	ft_player(t_vars *vars);
void	ft_move(t_vars	*vars, char c);
void	ft_move_a(t_vars *vars, int lmakla);
void	ft_move_d(t_vars *vars, int lmakla);
void	ft_move_w(t_vars *vars, int lmakla);
void	ft_move_s(t_vars *vars, int lmakla);
void	ft_valid_diff(t_vars *vars, char **splitmap);
void	ft_check_path(t_vars *vars, char **cpymap, int x, int y);
void	ft_valid_path(t_vars *vars);
void	ft_err(t_vars *vars);
int		ft_err2(t_vars *vars);
void	ft_img(t_vars *vars);
void	ft_free(char *c);
#endif
