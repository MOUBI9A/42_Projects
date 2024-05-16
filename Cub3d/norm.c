/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:29:08 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/16 12:57:13 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(char **map, int player_x, int player_y, int map_size)
{
	if (player_x < 0 || player_x >= map_size || player_y < 0 
		|| player_y >= ft_strlen(map[player_x])
		|| map[player_x][player_y] == '1'
		|| map[player_x][player_y] == ' ' || map[player_x][player_y] == '.')
		return ;
	map[player_x][player_y] = '.';
	flood_fill(map, player_x + 1, player_y, map_size);
	flood_fill(map, player_x - 1, player_y, map_size);
	flood_fill(map, player_x, player_y + 1, map_size);
	flood_fill(map, player_x, player_y - 1, map_size);
}

void	floodfill_check(char **map, int p_x, int p_y, int map_size)
{
	char	**mapcpy;
	int		i; 

	mapcpy = (char **)malloc(sizeof(char *) * map_size);
	i = 0;
	while (i < map_size)
	{
		mapcpy[i] = ft_strdup(map[i]);
		i++;
	}
	flood_fill(mapcpy, p_x, p_y, map_size);
	check_valid_map(mapcpy, p_x, p_y, map_size);
	i = 0;
	while (i < map_size)
	{
		free(mapcpy[i]);
		i++;
	}
	free(mapcpy);
}

void	check_rgb(char **rgb, t_map **data, int *i)
{
	while (rgb[*i])
	{
		if (!is_digit_str(rgb[*i]))
			print_error("RGB value must be a number\n", 1);
		(*i)++;
	}
}

void	check_ceiling(t_map **data, char *str)
{
	int		i;
	int		j;
	char	*str2;
	char	**rgb;

	i = 0;
	j = 0;
	if ((*data)->ceiling_rgb)
		print_error("Ceiling color already defined\n", 1);
	str2 = ft_strtrim(ft_strdup(str + 2), " \t");
	rgb = ft_split(str2, ',');
	check_rgb(rgb, data, &i);
	if (i != 3)
		print_error("Ceiling color must be in RGB format\n", 1);
	(*data)->ceiling_rgb = (int *)ft_calloc(sizeof(int), 3);
	while (j < 3)
	{
		(*data)->ceiling_rgb[j] = ft_atoi(rgb[j]);
		if ((*data)->ceiling_rgb[j] < 0 || (*data)->ceiling_rgb[j] > 255)
			print_error("RGB value must be between 0 and 255\n", 1);
		j++;
	}
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	free(str2);
}
