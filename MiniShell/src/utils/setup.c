/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 03:15:13 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/15 03:15:13 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	print_prompt(void)
{
	char	hostname[MAX_INPUT_LENGTH];
	char	*username;
	char	cwd[MAX_INPUT_LENGTH];

	username = getenv("USER");
	get_hostname_local(hostname);
	if (username == NULL)
		username = "minishell";
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		exit(1);
	}
	// printf("\033[32m%s\033[0m@\033[35m%s\033[0m :: \033[33m%s\033[0m\n",
	// 	username, hostname, cwd);
}

void	copy_to_array(t_Environment *env, char **result)
{
	t_EnvironmentVariable	*current;
	int						index;

	index = 0;
	current = env->head;
	while (current != NULL)
	{
		if (ft_strcmp(current->value, "\0") != 0)
		{
			result[index] = (char *)malloc(ft_strlen(current->key)
					+ ft_strlen(current->value) + 2);
			if (result[index] == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
			ft_strcpy(result[index], current->key);
			ft_strcat(result[index], "=");
			ft_strcat(result[index], current->value);
			index++;
		}
		current = current->next;
	}
}

char	**convert_to_double_pointer(t_Environment *env)
{
	int		count;
	char	**result;

	count = count_non_empty_pairs(env);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (result == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	copy_to_array(env, result);
	result[count] = NULL;
	return (result);
}
