/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:15:15 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 00:46:28 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	calc_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	get_range(t_stack *stack)
{
	if (stack->size > 100)
		return (30);
	return (15);
}

int	get_index_of(int *arr, int size, int k)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == k)
			return (i);
		i++;
	}
	return (-1);
}

int	get_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->arr[0];
	while (i < stack->size)
	{
		if (stack->arr[i] < min)
			min = stack->arr[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	max = stack->arr[0];
	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}
