/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:56:58 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 01:18:55 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stacks	*create_stacks(int argc, char *argv[])
{
	t_stacks	*stacks;
	int			i;
	int			j;

	stacks = malloc(sizeof(t_stacks));
	stacks->a = malloc(sizeof(t_stack));
	stacks->b = malloc(sizeof(t_stack));
	stacks->a->size = argc;
	stacks->b->size = 0;
	stacks->a->arr = malloc(sizeof(int) * argc - 1);
	stacks->b->arr = malloc(sizeof(int) * argc - 1);
	ft_memset(stacks->b->arr, 0, sizeof(int) * argc - 1);
	j = 0;
	i = argc - 1;
	while (i >= 0)
	{
		stacks->a->arr[i] = ft_atoi(argv[j]);
		i--;
		j++;
	}
	return (stacks);
}

bool	is_stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->arr[i] < stack->arr[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	is_in_upper_stack(t_stack *stack, int k)
{
	if (get_index_of(stack->arr, stack->size, k) > stack->size / 2)
		return (true);
	return (false);
}

void	free_stacks(t_stacks *stacks)
{
	free(stacks->a->arr);
	free(stacks->b->arr);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}
