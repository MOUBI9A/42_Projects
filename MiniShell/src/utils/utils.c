/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:08:32 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:09:39 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	count_non_empty_pairs(t_Environment *env)
{
	t_EnvironmentVariable	*current;
	int						count;

	count = 0;
	current = env->head;
	while (current != NULL)
	{
		if (ft_strcmp(current->value, "\0") != 0)
			count++;
		current = current->next;
	}
	return (count);
}

void	ctrlchandler(int sig)
{
	if (sig == SIGINT)
	{
		if (g_signo[1] == 0 && g_signo[2] != 0)
		{
			g_signo[1] = 1;
			close(g_signo[0]);
			rl_replace_line("", 0);
			write(1, "\n", 1);
			rl_on_new_line();
			if (g_signo[2] == 0 && g_signo[3] != 1)
				rl_redisplay();
			rl_replace_line("", 0); 
		}
		else
		{
			rl_replace_line("", 0);
			write(1, "\n", 1);
			print_prompt();
			rl_on_new_line();
			if (g_signo[2] == 0 && g_signo[3] != 1)
				rl_redisplay();
			rl_replace_line("", 0);
		}
		g_signo[9] = 69;
	}
}
/*void	ctrlchandler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_replace_line("", 0);
		write(1, "\n", 1);
		print_prompt();
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
	}
}*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
