/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:05:28 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:05:29 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	quotes_cheker(char *str)
{
	int		i;
	char	sing;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			sing = str[i];
			i++;
			while (str[i] && str[i] != sing)
				i++;
			if (str[i] != sing)
				return (1);
		}
		i++;
	}
	return (0);
}

int	cheker(char *line)
{
	if (quotes_cheker(line) == 1)
		return (printf("\' or \" problem\n"), free(line), 1);
	if (pipe_cheker(line) == 1)
		return (printf("pipes error\n"), free(line), 1);
	if (great_less_cheker(line) == 1)
		return (printf("> >> << < problem\n"), free(line), 1);
	if (great_great_less_less_cheker(line) == 1)
		return (printf("more than << or >> problem\n"), free(line), 1);
	if (check_the_word_after_quotes(line) == 1)
		return (printf("problem with the word after quotes\n"), free(line), 1);
	return (0);
}

void	norm_for_this_file(char *new_str, char *str, int *i, int *j)
{
	new_str[*j] = str[*i];
	*j = *j + 1;
	*i = *i + 1;
	if (str[*i] != ' ')
	{
		new_str[*j] = ' ';
		*j = *j + 1;
	}
}

int	quotes_checker_for_pipe(const char *str, int j)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < j)
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			count++;
		}
		i++;
	}
	return (count % 2);
}

int	quotes_cheker_for_pipe(const char *str, int j)
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
			while (str[i] && str[i] != sing && i < j)
				i++;
			if (str[i] != sing)
				return (1);
		}
		i++;
	}
	return (0);
}
