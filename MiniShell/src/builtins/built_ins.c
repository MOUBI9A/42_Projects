/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <wbousfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:01:50 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/16 10:42:59 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	check_all_built_ins(t_data *cmds, t_Environment *env)
{
	if (built_in_env_handling(env, cmds->str) == 0)
		return (0);
	if (built_in_export_handling(env, cmds->str) == 0)
		return (0);
	if (built_in_echo_handling(cmds->str, env) == 0)
		return (0);
	else if (built_in_pwd_handling(cmds->str, env) == 0)
		return (0);
	else
		return (1);
}

int	check_built_ins_special(char **args, t_Environment *env,
	t_AssignementVariable *assignement_variables)
{
	if (built_in_export_full_handling(env, args, assignement_variables) == 0)
		return (0);
	if (built_in_unset_handling(env, args, assignement_variables) == 0)
		return (0);
	if (handling_cd(args, env) == 0)
		return (0);
	else if (built_in_exit_handling(args, env) == 0)
		return (0);
	else
		return (1);
}

int	built_in_echo_handling(char **args, t_Environment *env)
{
	int	i;
	int	no_newline;

	no_newline = 0;
	if (ft_strcmp(args[0], "echo") == 0)
	{
		i = 1;
		while (args[i] != NULL)
		{
			if (ft_strncmp(args[i], "-n", 2) == 0)
				no_newline = 1;
			else
			{
				ft_putstr(args[i]);
				if (args[i + 1] != NULL)
					ft_putstr(" ");
			}
			i++;
		}
		if (no_newline != 1)
			ft_putstr("\n");
		set_env_var(env, "?", "0");
		return (0);
	}
	return (1);
}

int	built_in_pwd_handling(char **args, t_Environment *env)
{
	char	cwd[MAX_INPUT_LENGTH];

	if (ft_strcmp(args[0], "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd");
			exit(1);
		}
		ft_putstr(cwd);
		ft_putchar('\n');
		set_env_var(env, "?", "0");
		return (0);
	}
	return (1);
}
