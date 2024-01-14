/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:05:32 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/17 09:51:56 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	parsing(char ***allcommands, char *line, t_Environment *env)
{
	line = NULL;
	line = readline("<># ");
	if (line == NULL)
		exit(1);
	if (line == NULL || (line)[0] == '\0' || ft_strcmp(line, "\n") == 0)
	{
		free(line);
		return (-25);
	}
	line = ft_strtrim(line);
	add_history(line);
	if (line == NULL || (line)[0] == '\0')
	{
		free(line);
		return (-25);
	}
	line = ft_strtrim(line);
	if (cheker(line) == 1)
	{
		set_env_var(env, "?", "258");
		return (-25);
	}
	*allcommands = split_main1(*allcommands, line);
	return (0);
}

char	quotes_open(const char *str, int j)
{
	int		i;
	char	sing;

	i = 0;
	while (str[i] != '\0' && i < j)
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			sing = str[i];
			i++;
			while (str[i] != '\0' && str[i] != sing && i < j)
				i++;
			if (str[i] != sing)
				return (sing);
		}
		i++;
	}
	return (0);
}

char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	char	*new_str;
	char	sing;

	i = -1;
	j = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[++i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			sing = str[i];
			i++;
			while (str[i] != '\0' && str[i] != sing)
				new_str[j++] = str[i++];
			if (str[i] != sing)
				return (NULL);
		}
		else
			new_str[j++] = str[i];
	}
	new_str[j] = '\0';
	return (free(str), new_str);
}

char	**split_main1(char **allcommands, char *line)
{
	int	i;

	i = 0;
	allcommands = ft_pipe_split(line);
	free(line);
	while (allcommands[i])
	{
		allcommands[i] = add_space_after_redirection(allcommands[i]);
		allcommands[i] = add_space_befor_redirection(allcommands[i]);
		allcommands[i] = ft_strtrim(allcommands[i]);
		i++;
	}
	return (allcommands);
}
