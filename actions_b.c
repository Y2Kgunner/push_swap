/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:24:28 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/27 07:11:39 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	swap(&temp->data, &temp->next->data);
	temp = temp->next->next;
	write(1, "sb\n", 3);
}

void	rb(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rrb(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		temp = last;
		last = last->next;
	}
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, "rrb\n", 4);
}

void	pb(t_list **stack_f, t_list **stack_t)
{
	t_list	*temp;

	temp = *stack_f;
	if (*stack_f == NULL)
		return ;
	*stack_f = (*stack_f)->next;
	temp->next = *stack_t;
	*stack_t = temp;
	write(1, "pb\n", 3);
}
