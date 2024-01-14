/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:31:32 by hel-moue          #+#    #+#             */
/*   Updated: 2023/04/08 20:58:23 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	ft_loop_cherker(char *line, int *i, int k)
{
	if (k)
		*i = *i + 2;
	else
		*i = *i + 1;
	while (line[*i] == ' ')
		*i = *i + 1;
	if (line[*i] == '\0')
		return (1);
	return (0);
}

int	great_great_less_less_cheker(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '>' && line[i + 1] == '>' && line[i + 2] == '>')
			return (1);
		if (line[i] == '<' && line[i + 1] == '<' && line[i + 2] == '<')
			return (1);
		if (line[i] == '>' && line[i + 1] == '>' && line[i + 2] == '<')
			return (1);
		if (line[i] == '<' && line[i + 1] == '<' && line[i + 2] == '>')
			return (1);
		if (line[i] == '>' && line[i + 1] == '<')
			return (1);
		if (line[i] == '<' && line[i + 1] == '>')
			return (1);
		i++;
	}
	return (0);
}

int	ft_loop2_cherker(char *line, int *i, int k)
{
	if (k)
		*i = *i + 2;
	else
		*i = *i + 1;
	while (line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
		*i = *i + 1;
	if (line[*i] == '\0' || line[*i] == '>' || line[*i] == '<')
		return (1);
	return (0);
}

int	check_the_word_after_quotes(char *line)
{
	int	i;

	i = -1;
	while (line && line[++i] != '\0')
	{
		if (line[i] == '>' && line[i + 1] == '>')
			ft_loop2_cherker(line, &i, 1);
		if (line[i] == '>' && line[i + 1] != '>')
			ft_loop2_cherker(line, &i, 0);
		if (line[i] == '<' && line[i + 1] == '<')
			ft_loop2_cherker(line, &i, 1);
		if (line[i] == '<' && line[i + 1] != '<')
			ft_loop2_cherker(line, &i, 0);
	}
	return (0);
}
