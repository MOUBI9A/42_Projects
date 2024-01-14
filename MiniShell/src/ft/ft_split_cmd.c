/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 05:01:55 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 05:01:57 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char	*ft_strrcpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

void	alloc_check_quote(char *str, int *i, char *quote)
{
	if (str[*i] == '\'' || str[*i] == '"')
	{
		*quote = str[*i];
		(*i)++;
		while (str[*i] != *quote)
			(*i)++;
	}
}

int	lenalloc(char *str)
{
	int		wc;
	int		i;
	char	quote;

	wc = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			alloc_check_quote(str, &i, &quote);
			i++;
		}
	}
	return (wc);
}

void	init_for_split_cmd(int *i, int *k, char *quote, int *j)
{
	*i = 0;
	*k = 0;
	*quote = 0;
	*j = 0;
}

char	**ft_split_cmd(char *str)
	{
	int		i;
	int		k;
	char	quote;
	int		j;
	char	**out;

	init_for_split_cmd(&i, &k, &quote, &j);
	out = (char **)malloc(sizeof(char *) * (lenalloc(str) + 1));
	while (str[i])
	{
		nonorm(&i, str);
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			alloc_check_quote(str, &i, &quote);
			i++;
		}
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strrcpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}
