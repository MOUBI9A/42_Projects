/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 05:03:43 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 05:03:43 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	free2d(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return ;
}

void	herdoc_input_free(char **herdoc_input)
{
	int	i;

	i = 0;
	if (!herdoc_input)
		return ;
	while (herdoc_input[i])
	{
		free(herdoc_input[i]);
		herdoc_input[i] = NULL;
		i++;
	}
	free(herdoc_input);
	herdoc_input = NULL;
	return ;
}

void	free_data(t_data *cmds)
{
	t_data			*tmp;
	t_redirection	*tmp2;

	while (cmds != NULL)
	{
		tmp = cmds->next;
		while (cmds->redirections != NULL)
		{
			tmp2 = cmds->redirections->next;
			free(cmds->redirections->word);
			free(cmds->redirections);
			cmds->redirections = tmp2;
		}
		free2d(cmds->str);
		free(cmds);
		cmds = tmp;
	}
}

void	free_all(char **allcommands, t_data *cmds)
{
	free2d(allcommands);
	free_data(cmds);
}
