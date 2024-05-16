/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:06:00 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/16 12:55:04 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line_one(char *str)
{
	if (str[0] != 'N' && str[0] != 'S' 
		&& str[0] != 'W' && str[0] != 'E' 
		&& str[0] != 'F' && str[0] != 'C' 
		&& str[0] != '1' && str[0] != '0' 
		&& str[0] != '\0' && str[0] != '\n' 
		&& str[0] != 13)
		print_error("Invalid Map [ERROR 15]\n", 1);
}

int	check_line_two(char *str)
{
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		return (1);
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		return (1);
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		return (1);
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		return (1);
	else if (str[0] == 'F' && str[1] == ' ')
		return (1);
	else if (str[0] == 'C' && str[1] == ' ')
		return (1);
	return (0);
}

void	check_n_s_w_e(t_map **data, char *str)
{
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		check_no(data, str);
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		check_so(data, str);
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		check_we(data, str);
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		check_ea(data, str);
	else if (str[0] == 'F' && str[1] == ' ')
		check_floor(data, str);
	else if (str[0] == 'C' && str[1] == ' ')
		check_ceiling(data, str);
}

bool	data_check(t_map **data)
{
	if ((*data)->no && (*data)->so && (*data)->we 
		&& (*data)->ea && (*data)->floor_rgb && (*data)->ceiling_rgb)
		return (true);
	return (false);
}

void	file_to_arr(t_map **data)
{
	char	*line;
	char	*str;
	int		i;

	i = 0;
	(*data)->data_size = data_count((*data)->fd_file);
	(*data)->file_data = alloc_data((*data)->data_size);
	(*data)->fd_file = open((*data)->file_path, O_RDONLY);
	while (((*data)->file_data[i] = get_next_line((*data)->fd_file)))
	{
		str = ft_strtrim((*data)->file_data[i], " \t");
		check_line_one(str);
		if (check_line_two(str) == 1)
			check_n_s_w_e(data, str);
		else if ((str[0] == '1' || str[0] == '0'))
		{
			if (data_check(data) == true)
			{
				if (!(*data)->map)
				{
					(*data)->map = alloc_data((*data)->data_size - i);
					(*data)->map_exist = true;
				}
				if ((*data)->map_finsh == true)
					print_error("Map not at the end\n", 1);
				(*data)->map[(*data)->map_size] = ft_strdup((*data)->file_data[i]);
				(*data)->map_size++;
			}
			else
				print_error("Invalid Map [ERROR 16]", 1);
		}
		else if (str[0] == '\n' && (*data)->map_exist == true)
			(*data)->map_finsh = true;
		i++;
		free(str);
	}
	close((*data)->fd_file);
	return ;
}
