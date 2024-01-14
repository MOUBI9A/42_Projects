/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:03:25 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/17 04:01:43 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*get_path_copy(t_Environment *env)
{
	char					*path_copy;
	t_EnvironmentVariable	*current;

	current = env->head;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, "PATH") == 0)
		{
			path_copy = malloc(ft_strlen(current->value) + 1);
			if (path_copy == NULL)
			{
				perror("malloc");
				_exit(EXIT_FAILURE);
			}
			ft_strcpy(path_copy, current->value);
			return (path_copy);
		}
		current = current->next;
	}
	return (NULL);
}

char	*find_executable(char *command, t_Environment *env)
{
	char	*path_copy;
	char	*result;

	path_copy = get_path_copy(env);
	if (path_copy != NULL)
	{
		result = search_executable(command, path_copy);
		free(path_copy);
		path_copy = NULL;
		return (result);
	}
	return (NULL);
}

char	*search_executable(char *command, char *path_copy)
{
	char	*dir;
	char	*result;
	char	full_path[MAX_INPUT_LENGTH];

	dir = my_strtok(path_copy, ':');
	while (dir != NULL)
	{
		ft_strcpy(full_path, dir);
		my_strcat(full_path, "/");
		my_strcat(full_path, command);
		if (is_executable(full_path))
		{
			result = malloc(ft_strlen(full_path) + 1);
			if (result == NULL)
			{
				perror("malloc");
				_exit(EXIT_FAILURE);
			}
			ft_strcpy(result, full_path);
			return (result);
		}
		dir = my_strtok(NULL, ':');
	}
	free(dir);
	return (NULL);
}

int	is_executable(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == 0 && (st.st_mode & S_IXUSR))
		return (1);
	return (0);
}

void	print_the_error(t_data *cmds, t_Environment *env)
{
	struct stat	file_stat;

	write(1, "bash: ", 6);
	write(1, cmds->str[0], ft_strlen(cmds->str[0]));
	if (access(cmds->str[0], F_OK) == -1)
	{
		write(2, ":  No such file or directory\n", 29);
		set_env_var(env, "?", "127");
	}
	else if (access(cmds->str[0], X_OK) == -1)
	{
		write(2, ": Permission denied\n", 20);
		set_env_var(env, "?", "127");
	}
	else if (access(cmds->str[0], F_OK) != -1
		&& access(cmds->str[0], X_OK) != -1)
	{
		if (stat(cmds->str[0], &file_stat) == 0 && S_ISDIR(file_stat.st_mode))
		{
			write(2, ": is a directory\n", 17);
			set_env_var(env, "?", "126");
		}
	}
}
