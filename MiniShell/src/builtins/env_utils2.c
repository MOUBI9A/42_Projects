/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:02:07 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:02:08 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*get_get_env_var(const t_Environment *env, char *key)
{
	return (get_get_env_var_reverse(env->head, key, 0));
}

char	*get_exit_status_utils(const t_EnvironmentVariable *current)
{
	char	*var_value;

	var_value = NULL;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, "?") == 0)
			return (current->value);
		current = current->next;
	}
	return (var_value);
}

char	*get_exit_status(const t_Environment *env)
{
	return (get_exit_status_utils(env->head));
}

void	print_var_env_reverse(const t_EnvironmentVariable *current, int counter)
{
	if (current == NULL)
		return ;
	if (current->next != NULL)
	{
		print_var_env_reverse(current->next, counter + 1);
		if (counter >= 0)
		{
			if (ft_strcmp(current->value, "\0") != 0
				&& ft_strcmp(current->key, "?") != 0)
			{
				ft_putstr(current->key);
				ft_putstr("=");
				ft_putstr(current->value);
				ft_putchar('\n');
			}
		}
	}
}

void	print_var_env(const t_Environment *env)
{
	print_var_env_reverse(env->head, 0);
}
