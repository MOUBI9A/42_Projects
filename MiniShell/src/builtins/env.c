/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:01:59 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:02:00 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	save_environment_variable(t_Environment *env, const char *key,
	const char *value)
{
	t_EnvironmentVariable	*new_variable;

	new_variable = malloc(sizeof(t_EnvironmentVariable));
	if (new_variable == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	new_variable->key = ft_strdup_wbousfirr(key);
	new_variable->value = ft_strdup_wbousfirr(value);
	if (new_variable->key == NULL || new_variable->value == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	new_variable->next = env->head;
	env->head = new_variable;
}

void	add_assignment(char *assignment,
	t_AssignementVariable *assignement_variables)
{
	t_AssignementVariable	*new_variable;

	new_variable = malloc(sizeof(t_AssignementVariable));
	if (new_variable == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	new_variable->assignment = ft_strdup_wbousfirr(assignment);
	if (new_variable->assignment == NULL)
		exit(EXIT_FAILURE);
	new_variable->next = assignement_variables;
	assignement_variables = new_variable;
}

void	unset_env_var(t_Environment *env, const char *key,
	t_AssignementVariable *assignement_variables)
{
	t_EnvironmentVariable	*current;
	t_EnvironmentVariable	*prev;

	current = env->head;
	prev = NULL;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, (char *)(key)) == 0)
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				env->head = current->next;
			free(current->key);
			current->key = NULL;
			free(current->value);
			current->value = NULL;
			free(current);
			current = NULL;
			return ;
		}
		prev = current;
		current = current->next;
	}
	unset_assignement_var(key, &assignement_variables);
}
