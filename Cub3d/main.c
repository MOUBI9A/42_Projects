/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:30:38 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/15 21:30:38 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *str, int ext)
{
	printf("\x1b[31mError\n\x1b[0m%s\n", str);
	exit(ext);
}

int	check_path(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (path[i - 1] == 'b' && path[i - 2] == 'u'
		&& path[i - 3] == 'c' && path[i - 4] == '.')
		return (0);
	return (1);
}


void	first_check(int argc, char **argv, t_map *data)
{
	data->file_path = argv[1];
	if (check_path(data->file_path))
		print_error("File extension must finish by .cub\n", 1);
	data->fd_file = open(data->file_path, O_RDONLY);
	if (data->fd_file == -1)
		print_error("Error Can't open the file \n", 1);
	return ;
}

void	check_theline_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != 13 && str[i] != '1' 
			&& str[i] != '0' && str[i] != ' ' 
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W'
			&& str[i] != 'E' )
			print_error("Invalid character in map\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	data;

	if (argc == 2)
	{
		first_check(argc, argv, &data);
		map_check(&data);
		// free_unused(&data);
		print_all(&data);
		free_all(&data);
	}
	else
		print_error("the programme he need just the map \n", 1);
	while(1);
	return (0);
}

// int main(int ac, char **av)
// {
// 	ft_main(ac,av);
// 	while(1);
// 	return 0;

// }
