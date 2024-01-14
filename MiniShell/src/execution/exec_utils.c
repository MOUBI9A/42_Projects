/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:03:56 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:03:57 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	execute_builtin_special(t_data *cmds, t_Environment *env)
{
	t_AssignementVariable	*assignement_variables;

	assignement_variables = NULL;
	if (check_built_ins_special(cmds->str, env, assignement_variables) == 0)
		return (0);
	return (1);
}

int	get_number_of_pipe(t_data *cmds)
{
	int	i;

	i = 0;
	while (cmds != NULL)
	{
		if (cmds->next != NULL)
			i++;
		cmds = cmds->next;
	}
	return (i);
}

char	*check_if_command_include_path(char *command)
{
	char	*path;

	path = ft_strchr(command, '/');
	if (command[0] == '.' && command[1] == '/')
	{
		path = command;
		if (is_executable(path))
			return (path);
		else
			return (NULL);
	}
	if (path != NULL)
	{
		if (is_executable(path))
			return (path);
		else
			return (NULL);
	}
	return (NULL);
}

void	check_after_execution(t_data *cmds, t_Environment *env)
{
	if (access(cmds->str[0], F_OK) == -1)
		return ;
	write(1, "bash: ", 6);
	write(1, cmds->str[0], ft_strlen(cmds->str[0]));
	if (access(cmds->str[0], X_OK) == -1)
		write(2, ": Permission denied\n", 20);
	else if (access(cmds->str[0], F_OK) != -1
		&& access(cmds->str[0], X_OK) != -1)
	{
		write(2, ": is a directory\n", 17);
		set_env_var(env, "?", "126");
	}
}

int	execute_builtin_special_or_assign(t_data *cmds, t_Environment *env,
	bool *in_fork)
{
	if (cmds->builtins == 2
		&& (!cmds->next && !cmds->prev && !cmds->redirections))
	{
		if (execute_builtin_special(cmds, env) == 0)
		{
			*in_fork = false;
			return (0);
		}
	}
	return (1);
}
