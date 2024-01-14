/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:05:37 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:05:38 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

t_data	*initialize_data(char **command, int i)
{
	t_data	*cmds;

	if (command[i] == NULL)
	{
		cmds = NULL;
		return (cmds);
	}
	cmds = (t_data *)malloc(sizeof(t_data));
	cmds->str = ft_split_cmd(command[i]);
	if (cmds->str[0] != NULL)
		cmds->builtins = is_builtin(cmds->str);
	cmds->str[0] = removeand(cmds->str[0]);
	return (cmds);
}

void	to_data_var(t_data *cmds, t_Environment *env)
{
	int		j;
	char	*tmp;

	j = -1;
	while (cmds->str[++j] != NULL)
	{
		if (ll(cmds) == 1 || (cmds->str[j][0] == '$' && cmds->str[j][1] == '?'))
		{
			tmp = replace_env_var(cmds->str[j], env);
			free(cmds->str[j]);
			cmds->str[j] = tmp;
		}
	}
}

void	handle_norm_to_data(t_data *cmds, t_Environment *env)
{
	int	j;

	j = -1;
	while (cmds->str[++j] != NULL)
	{
		if (norm_to_data(cmds->str, j) == 1)
		{
			set_env_var(env, "?", "258");
			free_data(cmds);
			return ;
		}
	}
}

t_data	*to_data(char **command, int i, t_data *prev, t_Environment *env)
{
	t_data	*cmds;
	int		j;

	cmds = initialize_data(command, i);
	if (cmds == NULL)
		return (cmds);
	to_data_var(cmds, env);
	handle_norm_to_data(cmds, env);
	cmds->redirections = hel_redirection(cmds->str, NULL, env);
	j = -1;
	while (cmds->str[++j] != NULL)
		cmds->str[j] = remove_quotes(cmds->str[j]);
	cmds->str = remove_redirection(cmds->str);
	cmds->next = to_data(command, i + 1, cmds, env);
	cmds->prev = prev;
	return (cmds);
}
