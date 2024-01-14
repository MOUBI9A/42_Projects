/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:34:36 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 00:53:01 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_tow(t_stacks *stacks)
{
	if (stacks->a->arr[0] < stacks->a->arr[1])
		sa(stacks);
}

void	sort_three(t_stacks *stacks)
{
	if (stacks->a->arr[0] < stacks->a->arr[1] \
		&& stacks->a->arr[2] < stacks->a->arr[0] \
			&& stacks->a->arr[2] < stacks->a->arr[1])
	{
		rra(stacks);
		sa(stacks);
	}
	else if (stacks->a->arr[2] > stacks->a->arr[1] \
		&& stacks->a->arr[1] < stacks->a->arr[0] \
			&& stacks->a->arr[2] < stacks->a->arr[0])
		sa(stacks);
	else if (stacks->a->arr[2] < stacks->a->arr[1] \
		&& stacks->a->arr[1] > stacks->a->arr[0] \
			&& stacks->a->arr[2] > stacks->a->arr[0])
		rra(stacks);
	else if (stacks->a->arr[2] > stacks->a->arr[1] \
		&& stacks->a->arr[1] < stacks->a->arr[0] \
			&& stacks->a->arr[2] > stacks->a->arr[0])
		ra(stacks);
	else
	{
		ra(stacks);
		sa(stacks);
	}
}

void	sort_3(t_stacks *stacks)
{
	if (stacks->a->arr[2] < stacks->a->arr[1] \
		&& stacks->a->arr[0] < stacks->a->arr[2] \
			&& stacks->a->arr[0] < stacks->a->arr[1])
	{
		rra(stacks);
		sa(stacks);
	}
	else if (stacks->a->arr[0] > stacks->a->arr[1] \
		&& stacks->a->arr[1] < stacks->a->arr[2] \
			&& stacks->a->arr[0] < stacks->a->arr[2])
		sa(stacks);
	else if (stacks->a->arr[0] < stacks->a->arr[1] \
		&& stacks->a->arr[1] > stacks->a->arr[2] \
			&& stacks->a->arr[0] > stacks->a->arr[2])
		rra(stacks);
	else if (stacks->a->arr[0] > stacks->a->arr[1] \
		&& stacks->a->arr[1] < stacks->a->arr[2] \
			&& stacks->a->arr[0] > stacks->a->arr[2])
		ra(stacks);
	else
	{
		ra(stacks);
		sa(stacks);
	}
}

void	move_elem_to_top_a(t_stacks *stacks, int k)
{
	if (is_in_upper_stack(stacks->a, k))
	{
		while (stacks->a->arr[stacks->a->size - 1] != k)
			ra(stacks);
	}
	else
	{
		while (stacks->a->arr[stacks->a->size - 1] != k)
			rra(stacks);
	}
}

void	sort_five(t_stacks *stacks)
{
	int	i;

	i = 0;
	move_elem_to_top_a(stacks, get_min(stacks->a));
	pb(stacks);
	move_elem_to_top_a(stacks, get_min(stacks->a));
	pb(stacks);
	if (is_stack_sorted(stacks->a) == false)
		sort_three(stacks);
	pa(stacks);
	pa(stacks);
}
