/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:05:37 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 22:39:10 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "stack.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*arr;
	int	size ;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

t_stacks	*create_stacks(int argc, char *argv[]);
void		sort_stack(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);

void		sort_three(t_stacks *stacks);
void		sort_tow(t_stacks *stacks);
void		sort_five(t_stacks *stacks);

int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			get_range(t_stack *stack);
int			get_index_of(int *arr, int size, int k);
void		free_stacks(t_stacks *stacks);
bool		is_stack_sorted(t_stack *stack);
bool		is_in_upper_stack(t_stack *stack, int k);
void		ft_set(void *src, unsigned char val, int size);

void		ft_err(void);
void		ft_first_check(char *all);
void		ft_second_check(char **args);
char		**ft_split_arg(char **argv);

int			calc_size(char **arr);
void		norm_fix1(t_stacks *stacks, int *start, int *end);
void		norm_fix2(t_stacks *stacks, int *start, int *end);
#endif