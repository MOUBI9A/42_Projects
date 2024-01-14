/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:01:53 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:01:54 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	built_in_exit_handling(char **args, t_Environment *env)
{
	if (ft_strcmp(args[0], "exit") == 0 && args[1] == NULL)
	{
		exit(0);
	}
	else if (ft_strcmp(args[0], "exit") == 0 && args[1] != NULL)
	{
		if (is_valid_exit(args[1]) == 0)
		{
			print_exit_handling(args[1], env);
			exit(255);
		}
		else if (args[2] != NULL)
		{
			write(1, "exit\n", 5);
			write(2, "bash: exit: too many arguments\n", 31);
			set_env_var(env, "?", "1");
		}
		else
		{
			printf("exit\n");
			exit(ft_atoi(args[1]));
		}
	}
	return (1);
}

int	built_in_env_handling(t_Environment *env, char **args)
{
	if (ft_strcmp(args[0], "env") == 0)
	{
		print_var_env(env);
		set_env_var(env, "?", "0");
		return (0);
	}
	return (1);
}

int	built_in_export_handling(t_Environment *env, char **args)
{
	if (ft_strcmp(args[0], "export") == 0 && args[1] == NULL)
	{
		print_env_export(env);
		set_env_var(env, "?", "0");
		return (0);
	}
	return (1);
}

int	built_in_export_full_handling(t_Environment *env,
	char **args, t_AssignementVariable *assignement_variables)
{
	(void)assignement_variables;
	if (ft_strcmp(args[0], "export") == 0 && args[1] != NULL)
	{
		handle_export_args(env, args, assignement_variables);
		set_env_var(env, "?", "0");
		return (0);
	}
	return (1);
}

int	built_in_unset_handling(t_Environment *env, char **args,
	t_AssignementVariable *assignement_variable)
{
	int	i;

	if (ft_strcmp(args[0], "unset") == 0)
	{
		if (args[1] != NULL)
		{
			i = 1;
			while (args[i] != NULL)
			{
				unset_env_var(env, args[i], assignement_variable);
				i++;
			}
		}
		set_env_var(env, "?", "0");
		return (0);
	}
	return (1);
}
