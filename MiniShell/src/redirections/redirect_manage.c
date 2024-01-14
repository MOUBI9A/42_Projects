/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_manage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:05:55 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:05:56 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

t_redirection	*norm1(char **str, int *i,
	t_redirection **prev, t_Environment *env)
{
	t_redirection	*node;

	node = NULL;
	if (prev[0] != NULL)
		close(prev[0]->fd_in);
	node = (t_redirection *)malloc(sizeof(t_redirection));
	node->word = ft_strdup(str[*i + 1]);
	node->fd_in = open(node->word, O_RDONLY);
	node->fd_out = -1;
	node->token = LESS;
	node->next = hel_redirection(str + *i + 2, node, env);
	node->prev = prev[0];
	return (node);
}

t_redirection	*norm2(char **str, int *i,
	t_redirection **prev, t_Environment *env)
{
	t_redirection	*node;

	node = NULL;
	if (prev[0] != NULL)
		close(prev[0]->fd_out);
	node = (t_redirection *)malloc(sizeof(t_redirection));
	node->word = ft_strdup(str[*i + 1]);
	node->fd_in = -1;
	node->fd_out = open(node->word, O_CREAT | O_RDWR | O_TRUNC, 0644);
	node->token = GREAT;
	node->next = hel_redirection(str + *i + 2, node, env);
	node->prev = prev[0];
	return (node);
}

t_redirection	*norm3(char **str, int *i,
	t_redirection **prev, t_Environment *env)
{
	t_redirection	*node;

	node = NULL;
	if (prev[0] != NULL)
		close(prev[0]->fd_out);
	node = (t_redirection *)malloc(sizeof(t_redirection));
	node->word = ft_strdup(str[*i + 1]);
	node->fd_in = -1;
	node->fd_out = open(node->word, O_CREAT | O_RDWR | O_APPEND, 0644);
	node->token = DGREAT;
	node->next = hel_redirection(str + *i + 2, node, env);
	node->prev = prev[0];
	return (node);
}

t_redirection	*norm4(char **str, int *i,
	t_redirection **prev, t_Environment *env)
{
	t_redirection	*node;

	node = NULL;
	*i = *i + 1;
	if (prev[0] != NULL)
		close(prev[0]->fd_in);
	node = (t_redirection *)malloc(sizeof(t_redirection));
	node->word = ft_strdup(str[*i]);
	node->fd_in = -1;
	node->fd_out = -1;
	node->token = DLESS;
	node->herdoc_data = open_herdoc(node->word, env);
	node->herdoc_input = convert_herdoc(node->herdoc_data);
	free2d(node->herdoc_data);
	node->herdoc_data = NULL;
	node->next = hel_redirection(str + *i, node, env);
	node->prev = prev[0];
	return (node);
}

t_redirection	get_the_last_redirection(t_redirection *redirections)
{
	t_redirection	*tmp;

	tmp = redirections;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (*tmp);
}
