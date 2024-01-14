/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:02:33 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:02:34 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	count(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

void	handle_export_args(t_Environment *env,
	char **args, t_AssignementVariable *assignement_variable)
{
	int		i;
	char	*var_assignment;

	i = 1;
	while (args[i] != NULL)
	{
		var_assignment = retrieve_assignement_variable(args[i],
				assignement_variable);
		if (var_assignment != NULL)
			handle_var_assignment(env, var_assignment);
		else
			handle_no_var_assignment(env, args[i]);
		i++;
	}
}

void	handle_var_assignment(t_Environment *env, char *var_assignment)
{
	char	*var_name;
	char	*var_value;

	printf("var_assignment: %s\n", var_assignment);
	if (is_valid_variable_name_double(var_assignment) == 1)
	{
		write(1, "export: '", 9);
		write(1, var_assignment, ft_strlen(var_assignment));
		write(2, "': not a valid identifier\n", 26);
		set_env_var(env, "?", "1");
		return ;
	}
	var_name = ft_strdup_wbousfir(var_assignment);
	var_value = ft_strchr(var_name, '=') + 1;
	*ft_strchr(var_name, '=') = '\0';
	set_env_var(env, var_name, var_value);
	free(var_name);
	var_name = NULL;
}

void	handle_no_var_assignment(t_Environment *env, char *args)
{
	char	*var_name;
	char	*var_value;
	char	*equal_sign;

	if (is_valid_variable_name_double(args) == 1
		|| ft_isdigit(args[0]) == 1 || args[0] == '=')
	{
		write(1, "export: '", 9);
		write(1, args, ft_strlen(args));
		write(2, "': not a valid identifier\n", 26);
		set_env_var(env, "?", "1");
		return ;
	}
	equal_sign = ft_strchr(args, '=');
	if (equal_sign != NULL)
	{
		*equal_sign = '\0';
		var_name = args;
		var_value = equal_sign + 1;
		set_env_var(env, var_name, var_value);
	}
	else
		set_env_var(env, args, "");
}
