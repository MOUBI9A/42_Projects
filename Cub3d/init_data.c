/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:01:23 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/15 21:53:35 by hel-moue         ###   ########.fr       */
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
	printf("Struct initialized DONE\n");
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
		print_error("Empty file\n", 1);
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
		print_error("Malloc failed [ERROR 7]\n", 1);
	while (i < size)
	{
		data[i] = NULL;
		i++;
	}
	data[i] = NULL;
	return (data);
}
