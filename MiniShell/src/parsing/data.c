/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:32 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 20:58:23 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	norm_to_data(char **str, int j)
{
	if (str[j + 1] == NULL && (ft_strncmp(str[j], ">", 1) == 0
			|| ft_strncmp(str[j], ">>", 2) == 0 || ft_strncmp(str[j], "<",
				1) == 0 || ft_strncmp(str[j], "<<", 2) == 0))
	{
		printf("minishell: syntax error `%s'\n", str[j]);
		return (1);
	}
	return (0);
}

int	is_her(char *command)
{
	int		i;
	char	*builtins[3];

	builtins[0] = "export";
	builtins[1] = "unset";
	builtins[2] = NULL;
	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(command, builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ll(t_data *cmds)
{
	if (is_her(cmds->str[0]) == 1
		&& (ft_strncmp(the_builtin(cmds->str[0]), "export", 5) == 0
			|| ft_strncmp(the_builtin(cmds->str[0]), "unset", 4) == 0))
		return (0);
	return (1);
}

char	*removeand(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '&')
		{
			tmp = ft_substr(str, 0, i);
			free(str);
			str = tmp;
			return (str);
		}
		i++;
	}
	return (str);
}
