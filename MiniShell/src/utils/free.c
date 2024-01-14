/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:08:17 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/17 05:21:53 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	free_linked_lists(t_Environment *env_copy,
	t_AssignementVariable *assignement_variables)
{
	t_EnvironmentVariable	*current;
	t_AssignementVariable	*current_assignement;
	t_AssignementVariable	*next_a;
	t_EnvironmentVariable	*next_e;

	current = env_copy->head;
	current_assignement = assignement_variables;
	while (current != NULL)
	{
		next_e = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next_e;
	}
	while (current_assignement != NULL)
	{
		next_a = current_assignement->next;
		free(current_assignement->assignment);
		free(current_assignement);
		current_assignement = next_a;
	}
}

void	free_double_pointer(char **env)
{
	int	envsize;
	int	i;

	envsize = len_env(env);
	i = 0;
	while (i < envsize)
	{
		free(env[i]);
		i++;
	}
	free (env);
}
