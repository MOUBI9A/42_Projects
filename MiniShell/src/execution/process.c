/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:59:55 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/17 03:59:55 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	ft_exit(t_Environment *env, int return_status,
	int fork_status, bool *in_fork)
{
	char	*tmp;

	if (*in_fork == true)
	{
		if (WIFSIGNALED(fork_status))
			fork_status = WTERMSIG(fork_status) + 128;
		else if (WIFEXITED(fork_status))
			fork_status = WEXITSTATUS(fork_status);
		if (WIFSIGNALED(fork_status) || WIFEXITED(fork_status))
			set_env_var(env, "?", ft_itoa(fork_status));
	}
	tmp = get_get_env_var(env, "?");
	tmp = ft_itoa(return_status);
	free(tmp);
}
