/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:08:14 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:08:15 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	is_normal_builtin(char **command)
{
	int		i;
	char	*builtins[5];

	builtins[0] = "echo";
	builtins[1] = "pwd";
	builtins[2] = "export";
	builtins[3] = "env";
	builtins[4] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(command[0], builtins[i]) == 0)
		{
			if (ft_strcmp(command[0], "export") == 0 && command[1] != 0)
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_special_builtin(char **command)
{
	int		i;
	char	*builtins[5];

	builtins[0] = "cd";
	builtins[1] = "unset";
	builtins[2] = "export";
	builtins[3] = "exit";
	builtins[4] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(command[0], builtins[i]) == 0)
		{
			if (ft_strcmp(command[0], "export") == 0 && command[1] == 0)
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_builtin(char **command)
{
	int		i;
	char	*builtins[8];

	builtins[0] = "env";
	builtins[1] = "echo";
	builtins[2] = "export";
	builtins[3] = "cd";
	builtins[4] = "unset";
	builtins[5] = "pwd";
	builtins[6] = "exit";
	builtins[7] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (is_special_builtin(command) == 1)
			return (2);
		if (is_normal_builtin(command) == 1)
			return (1);
		i++;
	}
	return (0);
}

char	*the_builtin(char *command)
{
	int		i;
	char	*builtins[8];

	builtins[0] = "env";
	builtins[1] = "echo";
	builtins[2] = "export";
	builtins[3] = "cd";
	builtins[4] = "unset";
	builtins[5] = "pwd";
	builtins[6] = "exit";
	builtins[7] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(command, builtins[i]) == 0)
			return (builtins[i]);
		i++;
	}
	return (NULL);
}
