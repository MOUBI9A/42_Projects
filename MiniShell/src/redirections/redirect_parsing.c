/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:05:59 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:06:25 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*prepare_exit_string(char *str)
{
	char	*exit;

	exit = ft_strdup(str);
	exit = remove_quotes(exit);
	return (exit);
}

char	*read_heredoc_utils(char *line, char *exit, t_Environment *env)
{
	char	*tmp;

	line = readline("HEREDOC> ");
	if (line == NULL)
		return (NULL);
	if (exit[0] != '\'' && exit[0] != '\"')
	{
		tmp = replace_env_var(line, env);
		free(line);
		return (tmp);
	}
	else
		tmp = ft_strdup(line);
	free(line);
	return (tmp);
}

char	**open_herdoc_loop(char *exit, t_Environment *env, char *line)
{
	char	**herdoc;
	int		i;

	herdoc = (char **)ft_calloc(sizeof(char *), 100);
	i = 0;
	while (1)
	{
		if (g_signo[1] == 1)
			break ;
		line = read_heredoc_utils(line, exit, env);
		if (line == NULL)
		{
			free(line);
			continue ;
		}
		if (ft_strncmp(line, exit, ft_strlen(exit) + 1) == 0)
		{
			herdoc[i] = NULL;
			free(line);
			return (herdoc);
		}
		herdoc[i++] = ft_strdup(line);
		free(line);
	}
	return (herdoc);
}

char	**open_herdoc(char *str, t_Environment *env)
{
	char	*exit;
	char	*line;
	char	**herdoc;

	line = NULL;
	signal(SIGINT, ctrlchandler);
	exit = prepare_exit_string(str);
	g_signo[0] = dup(0);
	g_signo[2] = 1;
	herdoc = open_herdoc_loop(exit, env, line);
	free(exit);
	return (herdoc);
}
