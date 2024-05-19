/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:01:23 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/16 13:08:11 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_map **data)
{
	(*data)->file_data = NULL;
	(*data)->data_size = 0;
	(*data)->no = NULL;
	(*data)->so = NULL;
	(*data)->we = NULL;
	(*data)->ea = NULL;
	(*data)->floor_rgb = NULL;
	(*data)->ceiling_rgb = NULL;
	(*data)->map = NULL;
	(*data)->map_size = 0;
	(*data)->map_exist = false;
	(*data)->map_finsh = false;
	(*data)->player_x = -1;
	(*data)->player_y = -1;
	(*data)->player_dir = 0;
}

int	data_count(int fd)
{
	int		count;
	int		i;
	char	*line;

	count = 0;
	i = 0;
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	if (count == 0)
		print_error("Empty file\n", 1, NULL);
	close(fd);
	return (count);
}

char	**alloc_data(int size)
{
	char	**data;
	int		i;

	i = 0;
	data = (char **)malloc(sizeof(char *) * (size + 1));
	if (!data)
		print_error("Malloc failed [ERROR 7]\n", 1, NULL);
	while (i < size)
	{
		data[i] = NULL;
		i++;
	}
	data[i] = NULL;
	return (data);
}

void	print_all(t_map *data)
{
	int	i;

	i = 0;
	printf("NO: %s\n", data->no);
	printf("SO: %s\n", data->so);
	printf("WE: %s\n", data->we);
	printf("EA: %s\n", data->ea);
	printf("FLOOR: %d %d %d\n", data->floor_rgb[0], data->floor_rgb[1], data->floor_rgb[2]);
	printf("CEILING: %d %d %d\n", data->ceiling_rgb[0], data->ceiling_rgb[1], data->ceiling_rgb[2]);
	printf("MAP:\n");
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	printf("PLAYER: %d %d\n", data->player_x, data->player_y);
	printf("PLAYER DIR: %c\n", data->player_dir);
}

void	free_all(t_map *data)
{
	int	i;

	i = 0;
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->floor_rgb)
		free(data->floor_rgb);
	if (data->ceiling_rgb)
		free(data->ceiling_rgb);
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			data->map[i] = NULL;
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
	// if(data->file_data)
	// {
	// 	i = 0;
	// 	while (data->file_data[i])
	// 	{
	// 		free(data->file_data[i]);
	// 		data->file_data[i] = NULL;
	// 		i++;
	// 	}
	// 	free(data->file_data);
	// 	data->file_data = NULL;
	// }
}