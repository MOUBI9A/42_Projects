/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:02:37 by wbousfir          #+#    #+#             */
/*   Updated: 2023/12/13 22:02:38 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	wtermsig_wbousfir(int status)
{
	return ((*(int *)&(status)) & 0x7F);
}

int	wifsignaled_wbousfir(int status)
{
	return (((*(int *)&(status)) & 0x00FF) != 0);
}

int	wexitstatus_wbousfir(int status, t_Environment *env)
{
	save_environment_variable(env, "?", int_to_string(status));
	return (status);
}
