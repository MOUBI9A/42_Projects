/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:31:26 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 22:40:27 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	norm_fix1(t_stacks *stacks, int *start, int *end)
{
	pb(stacks);
	*start += 1;
	*end += 1;
}

void	norm_fix2(t_stacks *stacks, int *start, int *end)
{
	pb(stacks);
	rb(stacks);
	*end += 1;
	*start += 1;
}
