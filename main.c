/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:14:19 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/31 13:23:45 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	string_arg(char **av, t_list **stack_a)
{
	int		j;
	int		i;
	char	**str;

	str = ft_split(av[1], ' ');
	free_null(str);
	j = 0;
	while (str[j] != NULL)
	{
		parse_str(str[j], str);
		i = ft_atoi(str[j]);
		insert_node(stack_a, i);
		j++;
	}
	free_str(str);
}

static void	indi_args(char **av, t_list **stack_a)
{
	int	j;
	int	i;

	j = 1;
	while (av[j] != NULL)
	{
		parse(av[j]);
		i = ft_atoi(av[j]);
		insert_node(stack_a, i);
		j++;
	}
}

static void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if (list_len(*stack_a) <= 5)
		sort_5_or_less(stack_a, stack_b);
	else if (list_len(*stack_a) > 5 && list_len(*stack_a) <= 100)
	{
		push_chunks_small(stack_a, stack_b);
		sort_large(stack_a, stack_b);
	}
	else
	{
		push_chunks_large(stack_a, stack_b);
		sort_large(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		sorted;

	stack_a = NULL;
	stack_b = NULL;
	empty_args(ac);
	if (ac == 2)
		string_arg(av, &stack_a);
	else if (ac > 2)
		indi_args(av, &stack_a);
	duplicate(stack_a);
	sorted = sort_verif(stack_a);
	if (ac > 1 && sorted == 0)
	{
		push_swap(&stack_a, &stack_b);
	}
	delete(&stack_a);
	delete(&stack_b);
	return (0);
}
