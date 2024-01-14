/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:04:58 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:04:59 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	cleanup_and_exit(t_Environment *env,
	t_AssignementVariable *assignement_variables)
{
	free_linked_lists(env, assignement_variables);
	clear_history();
}

void	initialize_environment(t_Environment *env, char **env_data)
{
	env->head = NULL;
	setup_environment(env, env_data);
}

void	shell_loop(t_Environment *env)
{
	char	**allcommands;
	char	*input;

	input = NULL;
	allcommands = NULL;
	perform_shell_loop(env, allcommands, input);
}
