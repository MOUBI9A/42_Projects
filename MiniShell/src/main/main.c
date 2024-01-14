/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:04:47 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/17 09:51:45 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	main_setup(t_Environment *env, t_data *cmds)
{
	if (cmds->str[0] == NULL)
		return (1);
	execute_multiple_pipe_commands(env,
		cmds);
	return (0);
}

void	perform_shell_loop(t_Environment *env, char **allcommands,
	char *input)
{
	t_data	*cmds;

	cmds = NULL;
	while (1)
	{
		print_prompt();
		if (parsing(&allcommands, input, env) == -25)
			continue ;
		cmds = to_data(allcommands, 0, NULL, env);
		if (cmds == NULL)
		{
			free(input);
			free_all(allcommands, cmds);
			continue ;
		}
		main_setup(env, cmds);
		free(input);
		free_all(allcommands, cmds);
	}
}

void	shell_loop_exit(char **allcommands, t_data *cmds,
	char *input, t_Environment *env)
{
	free(input);
	free_all(allcommands, cmds);
	set_env_var(env, "?", "0");
	exit(ft_atoi(get_get_env_var(env, "?")));
}

int	main(int argc, char **argv, char **env)
{
	t_Environment			env_copy;
	t_AssignementVariable	*assignement_variables;

	assignement_variables = NULL;
	(void)argv;
	(void)argc;
	initialize_environment(&env_copy, env);
	set_env_var(&env_copy, "?", "0");
	shell_loop(&env_copy);
	cleanup_and_exit(&env_copy, assignement_variables);
	return (0);
}
