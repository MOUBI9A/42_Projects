/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:01:56 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:01:57 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*expand_path(char *path, t_Environment *env)
{
	char	*ret;
	char	*tmp;

	ret = NULL;
	if (path[0] == '~')
	{
		if (path[1] == '/')
		{
			tmp = get_get_env_var(env, "HOME");
			ret = ft_strjoin(tmp, path + 1);
		}
		else if (path[1] == '\0')
			ret = ft_strdup(get_get_env_var(env, "HOME"));
	}
	return (ret);
}

char	*parse_path(char **cmd, t_Environment *env)
{
	int		i;
	char	*tmp;
	char	*ret;

	i = 0;
	ret = NULL;
	i = count(cmd);
	if (i > 2)
	{
		tmp = ft_strjoin("cd: string not in pwd: ", cmd[1]);
		ft_putstr(tmp);
		ft_putchar('\n');
		tmp = NULL;
		return (NULL);
	}
	else if (i == 2)
	{
		if (ft_strncmp(cmd[1], "~", 1) == 0)
			ret = expand_path(cmd[1], env);
		else
			ret = ft_strdup(cmd[1]);
	}
	else if (i == 1)
		ret = ft_strdup(get_get_env_var(env, "HOME"));
	return (ret);
}

void	update_pwd_env(char	*old_path, t_Environment *env)
{
	char	path[PATH_MAX];

	if (old_path == NULL || env == NULL)
		return ;
	set_env_var(env, "OLDPWD", old_path);
	if (getcwd(path, sizeof(path)))
		set_env_var(env, "PWD", path);
	else
		perror("cd: getcwd()");
}

int	change_directory(char *path_to, t_Environment *env)
{
	char	old_path[PATH_MAX];
	int		result;

	getcwd(old_path, sizeof(old_path));
	result = chdir(path_to);
	if (result == 0)
	{
		update_pwd_env(old_path, env);
		free(path_to);
		path_to = NULL;
	}
	else
	{
		free(path_to);
		path_to = NULL;
		perror("cd");
		set_env_var(env, "?", "1");
	}
	return (result);
}

int	handling_cd(char **args, t_Environment *env)
{
	char	*path_to;
	int		arg_count;

	if (ft_strcmp(args[0], "cd") == 0)
	{
		arg_count = count(args);
		if (arg_count > 2)
			return (0);
		if (get_get_env_var(env, "HOME") == NULL && arg_count < 2)
		{
			printf("cd: HOME not set\n");
			return (0);
		}
		path_to = parse_path(args, env);
		set_env_var(env, "?", "0");
		return (change_directory(path_to, env));
	}
	return (1);
}
