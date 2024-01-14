/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:40:29 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 02:53:11 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	is_valid_exit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	print_exit_handling(char *str, t_Environment *env)
{
	write(1, "exit\n", 5);
	write(2, "bash: ", 6);
	write(2, str, ft_strlen(str));
	write(2, ": numeric argument required\n", 28);
	set_env_var(env, "?", "255");
}
