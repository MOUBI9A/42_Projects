/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free_redirect_and_space_handling.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:05:50 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:05:52 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	join_and_free(t_redirection *redirections, char *str)
{
	char	*tmp;

	if (!redirections->herdoc_input)
		redirections->herdoc_input = ft_strdup(str);
	else
	{
		tmp = ft_strdup(redirections->herdoc_input);
		free(redirections->herdoc_input);
		redirections->herdoc_input = ft_strjoin(tmp, str);
		free(tmp);
	}
}

int	condition_addspaceredirection(char *str, int i)
{
	if (((str[i] == '>' && str[i + 1] != '>')
			|| (str[i] == '<' && str[i + 1] != '<'))
		&& quotes_checker_for_pipe (str, i) == 0)
		return (1);
	return (0);
}

char	*add_space_after_redirection(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 5));
	while (str[i] != '\0')
	{
		if (((str[i] == '>' && str[i + 1] == '>')
				|| (str[i] == '<' && str[i + 1] == '<')) 
			&& quotes_checker_for_pipe (str, i) == 0)
		{
			new_str[j++] = str[i++];
			norm_for_this_file(new_str, str, &i, &j);
		}
		else if (condition_addspaceredirection(str, i) == 1)
			norm_for_this_file(new_str, str, &i, &j);
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	return (free(str), ft_strtrim(new_str));
}

char	*add_space_befor_redirection(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 5));
	while (str[i] != '\0')
	{
		if (((str[i] == '>' && str[i + 1] == '>')
				|| (str[i] == '<' && str[i + 1] == '<'))
			&& quotes_checker_for_pipe (str, i) == 0)
		{
			if (i - 1 > 0 && str[i - 1] != ' ')
				new_str[j++] = ' ';
			new_str[j++] = str[i++];
		}
		else if (condition_addspaceredirection(str, i) == 1)
			if (i - 1 >= 0 && str[i - 1] != ' ')
				new_str[j++] = ' ';
		new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	return (free(str), ft_strtrim(new_str));
}
