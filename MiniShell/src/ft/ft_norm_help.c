/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 02:59:06 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 05:07:52 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	nonorm(int *i, char *str)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'))
		(*i)++;
}

void	ft_some(char **result, size_t *resultIndex, size_t plus)
{
	char	*newresult;

	newresult = realloc(*result, *resultIndex + plus);
	if (newresult == NULL)
		exit(EXIT_FAILURE);
	*result = newresult;
}

int	rr(char *input, size_t i)
{
	if (input[i + 1] != ' ' && input[i + 1] != '\t' 
		&& input[i + 1] != '\n' && input[i + 1] != '\"')
		return (1);
	return (0);
}

int	ft_con(char *input, size_t i)
{
	if ((quotes_checker_for_pipe(input, i) == 0 
			|| (quotes_checker_for_pipe(input, i) == 1
				&& quotes_open(input, i) == '\"')))
		return (1);
	return (0);
}

void	init_for_replace_env_var(size_t *inputLength, char **result,
	size_t *resultIndex, char *input)
{
	*inputLength = ft_strlen_helmoue(input);
	*result = malloc(*inputLength + 1);
	*resultIndex = 0;
	if (*result == NULL && printf("Error: Memory allocation failed\n"))
		exit(EXIT_FAILURE);
}
