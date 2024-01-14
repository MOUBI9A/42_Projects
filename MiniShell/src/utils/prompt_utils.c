/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:08:23 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:08:24 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	execute_hostname_command(void)
{
	char	*hostname_cmd[2];

	hostname_cmd[0] = "hostname";
	hostname_cmd[1] = NULL;
	execve("/bin/hostname", hostname_cmd, NULL);
	printf("[DEBUG] Failed to execute hostname command\n");
	exit(1);
}

void	read_hostname_output(int fd_hostname[2],
	char str_hostname[MAX_INPUT_LENGTH])
{
	close(fd_hostname[1]);
	read(fd_hostname[0], str_hostname, MAX_INPUT_LENGTH);
	close(fd_hostname[0]);
	str_hostname[ft_strcspn_helmoue(str_hostname, "\n")] = '\0';
}

void	get_hostname_local(char str_hostname[MAX_INPUT_LENGTH])
{
	int		fd_hostname[2];
	pid_t	pid_hostname;

	pipe(fd_hostname);
	pid_hostname = fork();
	if (pid_hostname == -1)
	{
		printf("[DEBUG] Failed to fork hostname process\n");
		exit(1);
	}
	else if (pid_hostname == 0)
	{
		close(fd_hostname[0]);
		dup2(fd_hostname[1], STDOUT_FILENO);
		close(fd_hostname[1]);
		execute_hostname_command();
	}
	else
	{
		read_hostname_output(fd_hostname, str_hostname);
		waitpid(pid_hostname, NULL, 0);
	}
}
