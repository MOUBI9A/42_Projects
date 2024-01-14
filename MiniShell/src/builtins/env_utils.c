/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <wbousfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:02:03 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/16 03:26:45 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	check_if_assignement_utils(int i, t_data *cmds,
	t_AssignementVariable *assignement_variables, char *existing_variable)
{
	if (ft_strchr(cmds->str[i], '=') != NULL
		&& is_valid_variable_name_double(cmds->str[i]) == 1)
	{
		write(1, "bash: ", 6);
		write(1, cmds->str[i], ft_strlen(cmds->str[i]));
		write(2, ": command not found\n", 20);
		return (0);
	}
	else if (ft_strchr(cmds->str[i], '=') != NULL
		&& is_valid_variable_name_double(cmds->str[i]) == 0)
	{
		existing_variable
			= find_assignment_value(cmds->str[i],
				assignement_variables);
		if (existing_variable != NULL)
			update_assignment(assignement_variables, cmds->str[i]);
		else
			add_assignment(cmds->str[i], assignement_variables);
		return (0);
	}
	return (1);
}

int	check_if_assignement(t_data *cmds,
	t_AssignementVariable *assignement_variables)
{
	int		i;
	char	*existing_variable;

	i = 0;
	existing_variable = NULL;
	if (cmds->builtins == 0)
	{
		while (cmds->str[i] != NULL)
		{
			if (check_if_assignement_utils(i,
					cmds, assignement_variables, existing_variable) == 0)
				return (0);
			else
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

int	is_valid_variable_name_utils(const char *args, size_t j,
	const char *right_string)
{
	const char	*forbidden_characters_left;
	const char	*forbidden_characters_right;

	forbidden_characters_left = "-$*/%^-_çè!à£$ù%*()+{}[]|\\:;\"'<*>,.*?/";
	forbidden_characters_right = "-%\"',.";
	if (isdigit((unsigned char)args[0]) == 1 || args[0] == '=')
		return (1);
	while (j < ft_strlen(args))
	{
		if (ft_strchr(forbidden_characters_left, args[j]) != NULL
			|| quotes_checker_for_pipe(args, j) == 1)
			return (1);
		j++;
	}
	while (*right_string != '\0')
	{
		if (ft_strchr(forbidden_characters_right, *right_string) != NULL)
			return (1);
		right_string++;
	}
	return (0);
}

int	is_valid_variable_name_double(const char *args)
{
	size_t		j;
	const char	*equal_sign_pos;
	const char	*right_string;

	j = 0;
	equal_sign_pos = ft_strchr(args, '=');
	right_string = equal_sign_pos + 1;
	if (equal_sign_pos != NULL
		&& equal_sign_pos != args
		&& equal_sign_pos != args + ft_strlen(args) - 1)
	{
		if (is_valid_variable_name_utils(args, j, right_string) == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

char	*get_get_env_var_reverse(const t_EnvironmentVariable *current,
	char *key, int counter)
{
	size_t	key_len;
	char	*var_value;

	var_value = NULL;
	key_len = ft_strlen(key);
	if (current == NULL)
		return (NULL);
	if (current->next != NULL)
	{
		var_value = get_get_env_var_reverse(current->next, key, counter + 1);
		if (counter >= 1)
		{
			if (ft_strncmp(current->key, key, key_len) == 0
				&& (current->key[key_len] == '\0'))
				return (current->value);
		}
	}
	return (var_value);
}
