/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:02:20 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:02:20 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	update_existing_var(t_EnvironmentVariable *current, const char *value)
{
	free(current->value);
	current->value = NULL;
	current->value = ft_strdup_wbousfirr(value);
	if (current->value == NULL)
		exit(EXIT_FAILURE);
}

t_EnvironmentVariable	*create_new_var(const char *key, const char *value)
{
	t_EnvironmentVariable	*new_var;

	new_var = malloc(sizeof(t_EnvironmentVariable));
	if (new_var == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	new_var->key = ft_strdup_wbousfirr(key);
	if (new_var->key == NULL)
		exit(EXIT_FAILURE);
	new_var->value = ft_strdup_wbousfirr(value);
	if (new_var->value == NULL)
		exit(EXIT_FAILURE);
	new_var->next = NULL;
	return (new_var);
}

void	add_new_var_to_head(t_Environment *env, t_EnvironmentVariable *new_var)
{
	new_var->next = env->head;
	env->head = new_var;
}

void	set_env_var(t_Environment *env, const char *key, const char *value)
	{
	t_EnvironmentVariable	*current;
	t_EnvironmentVariable	*new_var;

	current = env->head;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, (char *)(key)) == 0)
		{
			update_existing_var(current, value);
			return ;
		}
		current = current->next;
	}
	new_var = create_new_var(key, value);
	add_new_var_to_head(env, new_var);
}
