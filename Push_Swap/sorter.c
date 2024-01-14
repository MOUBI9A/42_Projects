/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:35:18 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 22:37:40 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	*copy_array(int *array, int size)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		copy[i] = array[i];
		i++;
	}
	return (copy);
}

int	*sortcpy(int *array, int size)
{
	int	*copy;
	int	i;
	int	j;
	int	elem_cpy;

	i = 0;
	j = 0;
	elem_cpy = 0;
	copy = copy_array(array, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j + 1 < size && copy[j] > copy[j + 1])
			{
				elem_cpy = copy[j];
				copy[j] = copy[j + 1];
				copy[j + 1] = elem_cpy;
			}
			j++;
		}
		i++;
	}
	return (copy);
}

void	move_elem_to_top(t_stacks *stacks, int k)
{
	if (is_in_upper_stack(stacks->b, k))
	{
		while (stacks->b->arr[stacks->b->size - 1] != k)
			rb(stacks);
	}
	else
	{
		while (stacks->b->arr[stacks->b->size - 1] != k)
			rrb(stacks);
	}
}

void	move_elems_to_b(t_stacks *stacks)
{
	while (stacks->b->size)
	{
		move_elem_to_top(stacks, get_max(stacks->b));
		pa(stacks);
	}
}

void	sort_stack(t_stacks *stacks)
{
	static int	start;
	int			end;
	int			*copy;
	int			size;

	end = ((start = 0), get_range(stacks->a));
	copy = ((size = stacks->a->size), sortcpy(stacks->a->arr, stacks->a->size));
	while (stacks->a->size)
	{
		if (get_index_of(copy, size, stacks->a->arr[stacks->a->size - 1]) \
		>= start \
		&& get_index_of(copy, size, stacks->a->arr[stacks->a->size - 1]) <= end)
			norm_fix1(stacks, &start, &end);
		else if (get_index_of(copy, size, stacks->a->arr[stacks->a->size - 1])
			< start)
			norm_fix2(stacks, &start, &end);
		else
			ra(stacks);
	}
	free(copy);
	move_elems_to_b(stacks);
}
