/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:21:22 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/15 22:55:01 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid_map(char **map, int player_x, int player_y, int map_size)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '.')
			{
				if (i == 0 || i == map_size - 1 || j == 0 
					|| j == ft_strlen(map[i]) - 1)
					print_error("Map not closed\n", 1);
				if (map[i - 1][j] == 0 || map[i + 1][j] == 0 
					|| map[i][j - 1] == 0 || map[i][j + 1] == 0)
					print_error("Map not closed\n", 1);
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' 
					|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					print_error("Map not closed\n", 1);
			}
			j++;
		}
		i++;
	}
}

int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && i == 0)
			return (0);
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_floor(t_map **data, char *str)
{
	int		i;
	char	*str2;
	char	**rgb;

	i = -1;
	if ((*data)->floor_rgb)
		print_error("Floor color already defined\n", 1);
	str2 = ft_strdup(str + 2);
	str2 = ft_strtrim(str2, " \t");
	rgb = ft_split(str2, ',');
	while (rgb[++i])
		if (is_digit_str(rgb[i]) == 0)
			print_error("Floor color must be in RGB format (F digit)\n", 1);
	if (i != 3)
		print_error("Floor color must be in RGB format\n", 1);
	i = -1;
	(*data)->floor_rgb = (int *)ft_calloc(sizeof(int), 3);
	while (++i < 3)
	{
		(*data)->floor_rgb[i] = ft_atoi(rgb[i]);
		if ((*data)->floor_rgb[i] < 0 || (*data)->floor_rgb[i] > 255)
			print_error("RGB value must be between 0 and 255\n", 1);
	}
}

void	player_check(t_map *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				if (data->player_x != -1 || data->player_y != -1)
					print_error("Multiple player\n", 1);
				data->player_x = i;
				data->player_y = j;
			}
			else if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != ' ' && data->map[i][j] != '\n'
				&& data->map[i][j] != 13)
				print_error("Invalid character in map\n", 1);
		}
	}
	if (data->player_x == -1 || data->player_y == -1)
		print_error("No player\n", 1);
}

void	map_check(t_map *data)
{
	init_struct(&data);
	file_to_arr(&data);
	player_check(data);
	floodfill_check(data->map, data->player_x, data->player_y, data->map_size);
}
