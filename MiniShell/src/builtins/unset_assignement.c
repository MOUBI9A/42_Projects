/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_assignement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:02:40 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:02:41 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

t_AssignementVariable	*find_assignement_var(const char *var_name,
	t_AssignementVariable *assignement_variables)
{
	t_AssignementVariable	*current;

	current = assignement_variables;
	while (current != NULL)
	{
		if (ft_strncmp(current->assignment, var_name, ft_strlen(var_name)) == 0)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

void	remove_assignement_var(t_AssignementVariable *prev,
	t_AssignementVariable **assignement_variables)
{
	if (prev != NULL)
		prev->next = (*assignement_variables)->next;
	else
		*assignement_variables = (*assignement_variables)->next;
	free((*assignement_variables)->assignment);
	(*assignement_variables)->assignment = NULL;
	free(*assignement_variables);
	*assignement_variables = NULL;
}

void	free_var_name(char *var_name)
{
	if (var_name != NULL)
	{
		free(var_name);
		var_name = NULL;
	}
}

void	unset_assignement_var(const char *assignement,
	t_AssignementVariable **assignement_variables)
{
	char					*var_name;
	t_AssignementVariable	*prev;
	t_AssignementVariable	*current;
	t_AssignementVariable	*found_var;

	var_name = get_assignement_var_name(assignement);
	prev = NULL;
	current = *assignement_variables;
	found_var = find_assignement_var(var_name, current);
	if (found_var != NULL)
	{
		remove_assignement_var(prev, assignement_variables);
		free_var_name(var_name);
		return ;
	}
	free_var_name(var_name);
}
