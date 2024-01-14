/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:49:44 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 03:49:44 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	check_w_acc(char *file)
{
	if (access(file, W_OK) != 0)
	{
		if (errno != ENOENT)
		{
			perror(file);
			return (0);
		}
	}
	return (1);
}

int	overwrite_append(t_redirection *redirections)
{
	int	fd;

	fd = -1;
	if (redirections == NULL)
		return (1);
	if (redirections && redirections->word == NULL)
		return (0);
	if (!check_w_acc(redirections->word))
		return (0);
	if (redirections->token == GREAT)
		fd = open(redirections->word, O_CREAT | O_TRUNC | O_WRONLY,
				S_IRUSR | S_IWUSR);
	else if (redirections->token == DGREAT)
		fd = open(redirections->word, O_CREAT | O_APPEND | O_WRONLY,
				S_IRUSR | S_IWUSR);
	if (fd <= 2)
		return (0);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

int	stdin_redirections(t_redirection *redirections, t_Environment *env)
{
	int	fd;

	fd = -1;
	(void)env;
	if (redirections == NULL || (redirections && redirections->word == NULL))
		return (0);
	if (access(redirections->word, F_OK | R_OK) != 0)
	{
		perror(redirections->word);
		return (0);
	}
	if (redirections->token == LESS)
		fd = open(redirections->word, O_RDONLY);
	if (fd <= 2)
		return (0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}
