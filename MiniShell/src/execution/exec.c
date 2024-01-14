/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:02:51 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:03:04 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	ft_help_init(char ***env_copy, int *child, int (*pipe_fd)[2])
{
	pipe(*pipe_fd);
	*child = fork();
	*env_copy = NULL;
}

void	nnormi(int **save, int pipe_fd[2])
{
	if (**save > 2)
		close(**save);
	**save = pipe_fd[0];
	close(pipe_fd[1]);
}

int	execute_cmd(t_data *cmds, t_Environment *env, int *save, bool *in_fork)
{
	int			child;
	int			pipe_fd[2];
	char		**env_copy;

	ft_help_init(&env_copy, &child, &pipe_fd);
	if (child == 0)
	{
		if (build_redirections(cmds, pipe_fd, save, env))
		{
			if (cmds->builtins == 1)
			{
				check_all_built_ins(cmds, env);
				*in_fork = false;
			}
			else
			{
				get_bin_and_exec(env_copy, cmds, env);
				*in_fork = true;
			}
		}
		exit(errno);
	}
	else
		nnormi(&save, pipe_fd);
	return (child);
}

void	ft_wait(int *status, int child)
{
	waitpid(child, status, 0);
	while (wait(NULL) > 0)
		;
}

void	execute_multiple_pipe_commands(t_Environment *env, t_data *cmds)
{
	int		child;
	int		state;
	int		save;
	int		status;
	bool	in_fork;

	save = ((child = -1), (state = 0), (g_signo[3] = 1), -1);
	while (cmds)
	{
		if (ft_strlen_helmoue(cmds->str[0]) == 0
			&& ft_strlen_helmoue(cmds->str[1]) != 0)
		{
			cmds->str = remove_empty_str(cmds->str);
			continue ;
		}
		if (cmds->builtins == 2
			&& (!cmds->next && !cmds->prev && !cmds->redirections))
			state = execute_builtin_special_or_assign(cmds, env, &in_fork);
		else
			child = execute_cmd(cmds, env, &save, &in_fork);
		cmds = cmds->next;
	}
	ft_wait(&status, child);
	g_signo[1] = (ft_exit(env, state, status, &in_fork), 0);
	g_signo[3] = 0;
}
