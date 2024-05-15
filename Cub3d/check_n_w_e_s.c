/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_w_e_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:37:16 by hel-moue          #+#    #+#             */
/*   Updated: 2024/05/15 21:48:42 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_th(char *str)
{
	int	i;

	i = 0;
	if (str[0] == 0)
		print_error("Path can't be empty\n", 1);
	if (str[0] != '.' || str[1] != '/')
		print_error("Path must start by ./\n", 1);
	while (str[i])
	{
		if (str[i] == ' ')
			print_error("Path can't contain space\n", 1);
		i++;
	}
}

void	check_no(t_map **data, char *str)
{
	char	*str2;

	str2 = ft_strdup(str + 3);
	if ((*data)->no)
		print_error("NO path already defined\n", 1);
	(*data)->no = ft_strtrim(str2, " \t");
	check_th((*data)->no);
}

void	check_so(t_map **data, char *str)
{
	char	*str2;

	str2 = ft_strdup(str + 3);
	if ((*data)->so)
		print_error("SO path already defined\n", 1);
	(*data)->so = ft_strtrim(str2, " \t");
	check_th((*data)->so);
}

void	check_we(t_map **data, char *str)
{
	char	*str2;

	str2 = ft_strdup(str + 3);
	if ((*data)->we)
		print_error("WE path already defined\n", 1);
	(*data)->we = ft_strtrim(str2, " \t");
	check_th((*data)->we);
	printf("WE path checked\n");
	printf("==%s\n", (*data)->we);
}

void	check_ea(t_map **data, char *str)
{
	char	*str2;

	str2 = ft_strdup(str + 3);
	if ((*data)->ea)
		print_error("EA path already defined\n", 1);
	(*data)->ea = ft_strtrim(str2, " \t");
	check_th((*data)->ea);
}
