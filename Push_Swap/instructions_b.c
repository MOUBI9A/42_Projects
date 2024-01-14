/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:35:39 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/03 01:42:33 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	pb(t_stacks *stacks)
{
	int	top_a;

	if (!stacks->a->size)
		return ;
	top_a = stacks->a->arr[stacks->a->size - 1];
	stacks->b->arr[stacks->b->size] = top_a;
	stacks->b->size++;
	stacks->a->size--;
	write(1, "pb\n", 3);
}

void	rb(t_stacks *stacks)
{
	int	top_b;
	int	i;

	i = stacks->b->size - 1;
	top_b = stacks->b->arr[stacks->b->size - 1];
	while (i >= 0)
	{
		if (i - 1 >= 0)
		{
			stacks->b->arr[i] = stacks->b->arr[i - 1];
		}
		i--;
	}
	stacks->b->arr[0] = top_b;
	write(1, "rb\n", 3);
}

void	rrb(t_stacks *stacks)
{
	int	bot_b;
	int	i;

	i = 0;
	bot_b = stacks->b->arr[0];
	while (i < stacks->b->size)
	{
		if (i + 1 < stacks->b->size)
		{
			stacks->b->arr[i] = stacks->b->arr[i + 1];
		}
		i++;
	}
	stacks->b->arr[stacks->b->size - 1] = bot_b;
	write(1, "rrb\n", 4);
}

void	sb(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->b->arr[2];
	stacks->b->arr[2] = stacks->b->arr[1];
	stacks->b->arr[1] = tmp;
	write(1, "sb\n", 3);
}
