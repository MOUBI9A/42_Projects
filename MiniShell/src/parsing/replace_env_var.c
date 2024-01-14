/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 04:39:08 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 07:47:35 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	norma(char *buf, t_redirection *redirections, int _pipe_fd[2])
{
	pipe(_pipe_fd);
	write(_pipe_fd[1], redirections->herdoc_input,
		ft_strlen(redirections->herdoc_input));
	read(_pipe_fd[0], buf, 100);
	write(2, buf, ft_strlen(buf));
	dup2(_pipe_fd[0], STDIN_FILENO);
	close(_pipe_fd[0]);
	close(_pipe_fd[1]);
}

int	handel_specialcase(t_tools *k, char **result,
	size_t *resultindex, t_Environment *env)
{
	char	*value;

	if (ft_con(k->input, k->i) == 1
		&& k->input[k->i + 1] == '-')
	{
		ft_some(result, resultindex,
			ft_strlen_helmoue("👾Le minifuuuuuck DYAAALNA👾") + 1);
		ft_strcpy(*result + *resultindex, "Le minifuuuuuck DYAAALNA👾");
		*resultindex = *resultindex
			+ ft_strlen_helmoue("Le minifuuuuuck DYAAALNA👾");
		k->i++;
		return (1);
	}
	if (ft_con(k->input, k->i) == 1
		&& k->input[k->i + 1] == '?')
	{
		value = get_exit_status(env);
		ft_some(result, resultindex, ft_strlen_helmoue(value) + 1);
		ft_strcpy(*result + *resultindex, value);
		*resultindex = *resultindex + ft_strlen_helmoue(value);
		k->i++;
		return (1);
	}
	return (0);
}

int	check_redirections(t_redirection *redirections, t_Environment *env)
{
	int		_pipe_fd[2];
	int		ret;
	char	buf[100];

	ret = 1;
	if (!redirections)
		return (1);
	while (redirections != NULL && ret == 1)
	{
		if (redirections->token == GREAT || redirections->token == DGREAT)
			ret = overwrite_append(redirections);
		else if (redirections->token == LESS)
			ret = stdin_redirections(redirections, env);
		else if (redirections->token == DLESS)
		{
			norma(buf, redirections, _pipe_fd);
		}
		redirections = redirections->next;
	}
	return (ret);
}
