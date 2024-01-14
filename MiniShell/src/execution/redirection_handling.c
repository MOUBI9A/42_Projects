/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:34:04 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 04:34:04 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	build_redirections(t_data *cmds, int *pipe_fd,
	int *save, t_Environment *env)
{
	int	ret;

	ret = 1;
	if (!cmds->prev && cmds->next)
		dup2(pipe_fd[1], STDOUT_FILENO);
	else if (cmds->prev && cmds->next)
	{
		dup2(*save, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
	}
	else if (!cmds->next)
		dup2(*save, STDIN_FILENO);
	ret = check_redirections(cmds->redirections, env) || g_signo[1];
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (*save > 0)
		close(*save);
	return (ret);
}

void	put_strerror(t_data *cmds, int __errno, t_Environment *env)
{
	ft_putstr_fd(cmds->str[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(__errno), STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	if (__errno == ENOENT)
		set_env_var(env, "?", "127");
	else if (__errno == EACCES)
		set_env_var(env, "?", "126"); 
	else
		set_env_var(env, "?", "1");
}

void	put_cmd_error(char *cmd_str, char *error_str, t_Environment *env)
{
	ft_putstr_fd(cmd_str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error_str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	set_env_var(env, "?", "1");
}

void	get_bin_and_exec(char **env_copy, t_data *cmds, t_Environment *env)
{
	char	**bin_paths;
	char	*tmp;
	int		i;

	if (!cmds->str || (cmds->str && !cmds->str[0]))
		return ;
	env_copy = convert_to_double_pointer(env);
	if (cmds->str[0][0] == '.' || cmds->str[0][0] == '/')
	{
		if (access(cmds->str[0], F_OK | X_OK) != -1)
			execve(cmds->str[0], cmds->str, env_copy);
		put_strerror(cmds, errno, env);
		return ;
	}
	i = ((bin_paths = get_bin_paths(env)), -1);
	while (bin_paths[++i])
	{
		tmp = ft_strjoin(bin_paths[i], cmds->str[0]);
		if (access(tmp, F_OK | X_OK) != -1)
			execve(tmp, cmds->str, env_copy);
		tmp = NULL;
	}
	put_cmd_error(cmds->str[0], "command not found", env);
	set_env_var(env, "?", "126");
	(free(bin_paths), free(env_copy));
}
