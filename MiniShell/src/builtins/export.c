/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:59:35 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 04:59:38 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	print_env_export_reverse(const t_EnvironmentVariable *current)
{
	int	counter;

	counter = 0;
	if (current == NULL)
		return ;
	if (current->next != NULL)
	{
		print_env_export_reverse(current->next);
		if (counter >= 0 && ft_strcmp(current->key, "?") != 0)
		{
			ft_putstr("declare -x ");
			ft_putstr(current->key);
			if (ft_strcmp(current->value, "\0") != 0)
			{
				ft_putstr("=");
				ft_putchar('"');
				ft_putstr(current->value);
				ft_putchar('"');
			}
			ft_putchar('\n');
		}
		counter++;
	}
}

void	print_env_export(const t_Environment *env)
{
	print_env_export_reverse(env->head);
}

char	*get_exitt(const t_EnvironmentVariable *current)
{
	int	counter;

	counter = 0;
	if (current == NULL)
		return (NULL);
	if (current->next != NULL)
	{
		get_exitt(current->next);
		if (counter >= 0 && ft_strcmp(current->key, "?") != 0)
		{
			if (ft_strcmp(current->key, "?") != 0)
				return (current->value);
		}
		counter++;
	}
	return (NULL);
}

char	*get_exit(const t_Environment *env)
{
	char	*var;

	var = get_exitt(env->head);
	return (var);
}
