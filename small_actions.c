/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:50:29 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/27 06:15:13 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_list **stack_a)
{
	int	j;
	int	k;

	j = (*stack_a)->next->data;
	k = (*stack_a)->next->next->data;
	if ((*stack_a)->data > j && j < k && k > (*stack_a)->data)
		sa(*stack_a);
	else if ((*stack_a)->data > j && j < k && k < (*stack_a)->data)
		ra(stack_a);
	else if ((*stack_a)->data > j && j > k && k < (*stack_a)->data)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->data < j && j > k && k > (*stack_a)->data)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->data < j && j < k)
		return (0);
	else
		rra(stack_a);
	return (0);
}

int	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		i;

	temp = copy_list(*stack_a);
	i = smallest(*stack_a);
	while ((temp->data != i))
	{
		ra(stack_a);
		temp = temp->next;
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	delete(&temp);
	return (0);
}

static void	fourth_elem(t_list **stack_a, t_list **stack_b, int j, int k)
{
	if ((*stack_b)->data < j && (*stack_b)->data > (*stack_a)->data)
	{
		pa(stack_b, stack_a);
		sa(*stack_a);
	}
	else if ((*stack_b)->data > j && (*stack_b)->data < k)
	{
		ra(stack_a);
		pa(stack_b, stack_a);
		sa(*stack_a);
		rra(stack_a);
	}
	else if ((*stack_b)->data > k)
	{
		rra(stack_a);
		pa(stack_b, stack_a);
		ra(stack_a);
		ra(stack_a);
	}
	else
		pa(stack_b, stack_a);
}

static void	last_elem(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b)->data > (*stack_a)->data)
	{	
		pa(stack_b, stack_a);
		sa(*stack_a);
	}
	else
		pa(stack_b, stack_a);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	j;
	int	k;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	j = (*stack_a)->next->data;
	k = (*stack_a)->next->next->data;
	if ((*stack_b)->data < (*stack_b)->next->data)
		sb(*stack_b);
	if ((*stack_b)->data > k)
	{
		pa(stack_b, stack_a);
		ra(stack_a);
	}
	else if ((*stack_b)->data < k && (*stack_b)->data > j)
	{
		rra(stack_a);
		pa(stack_b, stack_a);
		ra(stack_a);
		ra(stack_a);
	}
	fourth_elem(stack_a, stack_b, j, k);
	if (list_len(*stack_b) == 1)
		last_elem(stack_a, stack_b);
}
