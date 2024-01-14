/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:02:11 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:02:12 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*retrieve_assignement_variable(const char *var_name,
	t_AssignementVariable *assignement_variables)
{
	t_AssignementVariable	*current;
	const char				*equal_sign;

	current = assignement_variables;
	while (current != NULL)
	{
		equal_sign = ft_strchr(current->assignment, '=');
		if (equal_sign != NULL && ft_strncmp(current->assignment, var_name,
				equal_sign - current->assignment) == 0)
		{
			return (current->assignment);
		}
		current = current->next;
	}
	return (NULL);
}

int	check_if_enviroment_variable_exist(const char *key,
	t_EnvironmentVariable *environment_variables)
{
	t_EnvironmentVariable	*current;

	current = environment_variables;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, (char *)(key)) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

char	*get_assignement_var_name(const char *input)
{
	const char	*delimiter_position;
	size_t		substring_length;
	char		*substring;

	delimiter_position = ft_strchr(input, '=');
	if (delimiter_position == NULL)
		return (ft_strdup(input));
	substring_length = delimiter_position - input;
	substring = (char *)malloc(substring_length + 1);
	if (substring == NULL)
	{
		printf("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	ft_strncpy(substring, input, substring_length);
	substring[substring_length] = '\0';
	return (substring);
}

int	len_env(char **env)
{
	int	envsize;

	envsize = 0;
	while (env[envsize] != NULL)
		envsize++;
	return (envsize);
}
