/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:02:16 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:02:17 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	check_if_assignement_variable_exist(const char *assignment,
	t_AssignementVariable *assignement_variables)
{
	t_AssignementVariable	*current;
	char					*var_name;

	current = assignement_variables;
	var_name = get_assignement_var_name(assignment);
	while (current != NULL)
	{
		if (ft_strncmp(current->assignment, var_name, ft_strlen(var_name)) == 0)
		{
			if (var_name != NULL)
			{
				free(var_name);
				var_name = NULL;
			}
			return (1);
		}
		current = current->next;
	}
	if (var_name != NULL)
	{
		free(var_name);
		var_name = NULL;
	}
	return (0);
}

void	update_assignment(t_AssignementVariable *variable,
	const char *assignment)
{
	free(variable->assignment);
	variable->assignment = NULL;
	variable->assignment = ft_strdup(assignment);
	if (variable->assignment == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
}

char	*find_assignment_value(char *search_key,
	t_AssignementVariable *assignement_variables)
{
	t_AssignementVariable	*current;
	char					*key;
	char					*value;

	current = assignement_variables;
	while (current != NULL)
	{
		key = my_strtok(current->assignment, '=');
		value = my_strtok(NULL, '=');
		if (key != NULL && value != NULL && ft_strcmp(key, search_key) == 0)
			return (value);
		current = current->next;
	}
	return (NULL);
}

t_AssignementVariable	*find_assignment(const char *assignment,
	t_AssignementVariable *assignement_variables)
{
	t_AssignementVariable	*current;

	current = assignement_variables;
	while (current != NULL)
	{
		if (ft_strncmp(current->assignment,
				assignment, ft_strlen(assignment)) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
