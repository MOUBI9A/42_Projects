/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:04:42 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 00:38:25 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	pa(t_stacks *stacks)
{
	int	top_b;

	if (!stacks->b->size)
		return ;
	top_b = stacks->b->arr[stacks->b->size - 1];
	stacks->a->arr[stacks->a->size] = top_b;
	stacks->a->size++;
	if (stacks->b->size > 0)
		stacks->b->size--;
	write(1, "pa\n", 3);
}

void	ra(t_stacks *stacks)
{
	int	top_a;
	int	i;

	i = stacks->a->size - 1;
	top_a = stacks->a->arr[stacks->a->size - 1];
	while (i >= 0)
	{
		if (i - 1 >= 0)
		{
			stacks->a->arr[i] = stacks->a->arr[i - 1];
		}
		i--;
	}
	stacks->a->arr[0] = top_a;
	write(1, "ra\n", 3);
}

void	rra(t_stacks *stacks)
{
	int	bot_a;
	int	i;

	i = 0;
	bot_a = stacks->a->arr[0];
	while (i < stacks->a->size)
	{
		if (i + 1 < stacks->a->size)
		{
			stacks->a->arr[i] = stacks->a->arr[i + 1];
		}
		i++;
	}
	stacks->a->arr[stacks->a->size - 1] = bot_a;
	write(1, "rra\n", 4);
}

void	sa(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->a->arr[stacks->a->size - 1];
	stacks->a->arr[stacks->a->size - 1] = stacks->a->arr[stacks->a->size - 2];
	stacks->a->arr[stacks->a->size - 2] = tmp;
	write(1, "sa\n", 3);
}
