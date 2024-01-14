/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:07:04 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:08:06 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	dless_is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	dless_check_quote(char *line, int *i)
{
	char	sing;

	if (line[*i] == '\0')
		return (1);
	sing = line[(*i)];
	(*i)++;
	while (line[*i] && line[*i] != sing)
		(*i)++;
	return (line[*i] != sing);
}

int	dless_check_redirect(char *line, int *i, int double_redirect)
{
	if (double_redirect)
		return (ft_loop_cherker(line, i, 1));
	else
		return (ft_loop_cherker(line, i, 0));
}

int	dless_process_redirect(char *line, int *i)
{
	if (line[*i] == '>' && line[*i + 1] == '>')
		return (dless_check_redirect(line, i, 1));
	else if (line[*i] == '>' && line[*i + 1] != '>')
		return (dless_check_redirect(line, i, 0));
	else if (line[*i] == '<' && line[*i + 1] == '<')
		return (dless_check_redirect(line, i, 1));
	else if (line[*i] == '<' && line[*i + 1] != '<')
		return (dless_check_redirect(line, i, 0));
	return (0);
}

int	great_less_cheker(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (dless_process_redirect(line, &i))
			return (1);
		i++;
	}
	return (0);
}
