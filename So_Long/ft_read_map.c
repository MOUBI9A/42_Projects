/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:01:06 by hel-moue          #+#    #+#             */
/*   Updated: 2023/05/15 18:38:16 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(char *argv, char	**splitmap, t_vars *vars)
{
	char	*c;
	int		fd;
	int		readline;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(2, "ERR - OEPN ERR\n", 17);
		exit(1);
	}
	c = malloc(sizeof(char) * 4128);
	ft_memset(c, 0, sizeof(char) * 4128);
	readline = read(fd, c, 4128);
	if (readline < 17 || readline > 4128)
		ft_free(c);
	ft_check_newlines(c);
	splitmap = ft_split(c, '\n');
	vars->cpymap = ft_split(c, '\n');
	free(c);
	return (splitmap);
}

void	ft_free(char *c)
{
	write(2, "ERR - BIG MAP\n", 16);
	free(c);
	exit(1);
}
