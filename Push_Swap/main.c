/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:32:51 by hel-moue          #+#    #+#             */
/*   Updated: 2023/06/04 01:28:42 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char	**ft_split_arg(char **argv)
{
	char	*all;
	char	**args;
	int		i;

	i = 1;
	all = ft_strdup("");
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
		{
			free(all);
			ft_err();
		}
		all = ft_strjoin(all, " ");
		all = ft_strjoin(all, argv[i]);
		i++;
	}
	ft_first_check(all);
	args = ft_split(all, ' ');
	ft_second_check(args);
	free(all);
	return (args);
}

int	check_duplicates(t_stack *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stacks->size)
	{
		j = i + 1;
		while (j < stacks->size)
		{
			if (stacks->arr[j] == stacks->arr[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_arg(char **argv)
{
	int	i;
	int	j;
	int	s;

	i = 1;
	while (argv[i])
	{
		s = 0;
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				s++;
			j++;
		}
		i++;
		if (s == j)
		{
			ft_err();
		}
	}
}

void	ft_check_stack(t_stacks *stacks)
{
	if (check_duplicates(stacks->a))
	{
		free_stacks(stacks);
		ft_err();
	}
	if (is_stack_sorted(stacks->a) == true)
	{
		free_stacks(stacks);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	char		**str;

	if (argc < 2)
		exit(0);
	ft_check_arg(argv);
	str = ft_split_arg(argv);
	stacks = create_stacks(calc_size(str), str);
	ft_check_stack(stacks);
	if (stacks->a->size == 2)
		sort_tow(stacks);
	else if (stacks->a->size == 3)
		sort_three(stacks);
	else if (stacks->a->size == 5)
		sort_five(stacks);
	if (stacks->a->size > 5)
		sort_stack(stacks);
	free_stacks(stacks);
	return (0);
}
