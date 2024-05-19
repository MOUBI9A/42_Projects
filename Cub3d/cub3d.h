/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:56:19 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/16 12:56:19 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//---------get-next-line Header---------//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
// # include <sys/syslimits.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strchr(char	*s1, char s2);
void	*ft_calloc(unsigned int size, unsigned int len);
char	*get_next_line(int fd);

//---------cub3d Header---------//
typedef struct s_map
{
	char	*file_path;
	int		fd_file;
	char	**file_data;
	char	**data_filtered;
	int 	data_size;

	char	**map;//
	int		map_size;
	bool	map_exist;
	bool	map_finsh;
	
	int		player_x;//
	int		player_y;//
	char 	player_dir;//

	char	*no;//
	char	*so;//
	char	*we;//
	char	*ea;//

	int 	*floor_rgb;//
	int		*ceiling_rgb;//

}t_map;

void	init_struct(t_map **data);
void	file_to_arr(t_map **data);
void	check_no(t_map **data, char *str);
void	check_so(t_map **data, char *str);
void	check_we(t_map **data, char *str);
void	check_ea(t_map **data, char *str);
void	check_floor(t_map **data, char *str);
void	check_ceiling(t_map **data, char *str);
void	print_error(char *str, int i, t_map *data);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
int		is_digit_str(char *str);
int		ft_atoi(char *str);
char	*ft_strdup(char *str);
int		data_count(int fd);
char	**alloc_data(int size);
void	check_valid_map(char **map, t_map *data);
void	check_floor(t_map **data, char *str);
void	check_ceiling(t_map **data, char *str);
void	check_n_s_w_e(t_map **data, char *str);
bool	data_check(t_map **data);
void	file_to_arr(t_map **data);
void	floodfill_check(t_map **data);
void	check_theline_map(char *str, t_map *data);
void	player_check(t_map *data);
void	flood_fill(char **map, int x, int y, int map_size);
void	map_check(t_map *data);
void	check_ceiling(t_map **data, char *str);
void	print_all(t_map *data);
void	free_all(t_map *data);
#endif