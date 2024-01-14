/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:49:28 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 03:49:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*convert_herdoc(char **herdoc_data)
{
	int		i;
	char	*herdoc_input;
	char	*tmp;

	if (!herdoc_data || !herdoc_data[0])
		return (NULL);
	herdoc_input = NULL;
	i = 0;
	herdoc_input = ft_strdup("");
	if (!herdoc_input)
		return (NULL);
	while (herdoc_data[i])
	{
		tmp = herdoc_input;
		herdoc_input = ft_strjoin(herdoc_input, herdoc_data[i]);
		free(tmp);
		tmp = herdoc_input;
		herdoc_input = ft_strjoin(herdoc_input, "\n");
		free(tmp);
		i++;
	}
	herdoc_input[ft_strlen_helmoue(herdoc_input) - 1] = '\0';
	return (herdoc_input);
}

t_redirection	*hel_redirection(char **str,
	t_redirection *prev, t_Environment *env)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], ">") == 0)
			return (norm2(str, &i, &prev, env));
		else if (ft_strcmp(str[i], ">>") == 0)
			return (norm3(str, &i, &prev, env));
		else if (ft_strcmp(str[i], "<") == 0)
			return (norm1(str, &i, &prev, env));
		else if (ft_strcmp(str[i], "<<") == 0)
			return (norm4(str, &i, &prev, env));
		i++;
	}
	return (NULL);
}

int	is_redirection(char *str)
{
	return (ft_strcmp(str, ">") == 0 
		|| ft_strcmp(str, ">>") == 0
		|| ft_strcmp(str, "<") == 0
		|| ft_strcmp(str, "<<") == 0);
}

void	norminet(char **str, int *i, int *j)
{
	while (str[*i] != NULL)
	{
		if (is_redirection(str[*i]))
			*i += 2;
		else
		{
			*j = *j + 1;
			*i = *i + 1;
		}
	}
}

char	**remove_redirection(char **str)
{
	int		i;
	int		j;
	char	**new_str;

	i = 0;
	j = 0;
	norminet(str, &i, &j);
	new_str = (char **)malloc(sizeof(char *) * (j + 1));
	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		if (is_redirection(str[i]))
			i += 2;
		else
		{
			new_str[j] = ft_strdup(str[i]);
			j++;
			i++;
		}
	}
	new_str[j] = NULL;
	free2d(str);
	return (new_str);
}
