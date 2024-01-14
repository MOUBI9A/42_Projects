/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:03:33 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:03:34 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	nb_of_pipe(char *s)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (s[i])
	{
		if ((s[i] == '|' && (int)quotes_cheker_for_pipe(s, i) == 0))
			f++;
		i++;
	}
	return (f);
}

int	pipe_cheker(char *line)
{
	int		i;
	char	sing;

	i = 0;
	if (line[i] == '|' || line[ft_strlen(line) - 1] == '|')
		return (1);
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			sing = line[i];
			i++;
			while (line[i] && line[i] != sing)
				i++;
			if (line[i] != sing)
				return (1);
		}
		if (line[i] == '|' && line[i + 1] == '|')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_pipe_split(char *s)
{
	int		i;
	int		j;
	int		indx;
	char	**split;

	if (!s)
		return (NULL);
	i = (int)nb_of_pipe(s) + 2;
	split = (char **)ft_calloc(i, sizeof(char *));
	i = -1;
	j = 0;
	indx = -1;
	while (++i <= (int)ft_strlen(s))
	{
		if (s[i] != '|' && indx < 0)
			indx = i;
		if (((s[i] == '|' || !s[i]) && (int)quotes_cheker_for_pipe(s, i) == 0)
			&& indx > -1)
		{
			split[j++] = (char *)ft_substr(s, indx, i - indx);
			indx = -1;
		}
	}
	return (split);
}

char	**get_bin_paths(t_Environment *env)
{
	int		i;
	char	**ret;
	char	*tmp;
	char	*env_p;

	if (!env)
		return (NULL);
	env_p = get_get_env_var(env, "PATH");
	if (!env_p)
		return (NULL);
	ret = ft_split(env_p, ':');
	i = -1;
	while (ret[++i])
	{
		if (ret[i][ft_strlen(ret[i]) - 1] != '/')
		{
			tmp = ft_strjoin(ret[i], "/");
			free(ret[i]);
			ret[i] = ft_strdup(tmp);
			free(tmp);
			tmp = NULL;
		}
	}
	return (ret);
}
