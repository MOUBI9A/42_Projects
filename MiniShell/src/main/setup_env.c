/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:05:04 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:05:06 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	handle_signal(void)
{
	signal(SIGINT, ctrlchandler);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}

char	*find_equal_sign(char *str)
{
	return (ft_strchr(str, '='));
}

void	setup_save_env_user(t_Environment *env_copy)
{
	char	*user;

	user = getenv("USER");
	if (user != NULL)
		save_environment_variable(env_copy, "USER", user);
	else
		save_environment_variable(env_copy, "USER", "hel-moue");
}

void	setup_process_environment_variable(t_Environment *env_copy,
	char *name, char *value)
{
	save_environment_variable(env_copy, name, value);
}

void	setup_environment(t_Environment *env_copy, char **env)
{
	int		i;
	char	*equal_sign;

	i = 0;
	handle_signal();
	while (env[i] != NULL)
	{
		equal_sign = find_equal_sign(env[i]);
		if (equal_sign != NULL)
		{
			*equal_sign = '\0';
			if (ft_strcmp(env[i], "USER") == 0)
				setup_save_env_user(env_copy);
			setup_process_environment_variable(env_copy,
				env[i], equal_sign + 1);
			*equal_sign = '=';
		}
		i++;
	}
}
