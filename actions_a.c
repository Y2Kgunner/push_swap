/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:22:19 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/27 05:45:37 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	swap(&temp->data, &temp->next->data);
	temp = temp->next->next;
	write(1, "sa\n", 3);
}

void	ra(t_list **stack)
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
	write(1, "ra\n", 3);
}

void	rra(t_list **stack)
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
	write(1, "rra\n", 4);
}

void	pa(t_list **stack_f, t_list **stack_t)
{
	t_list	*temp;

	temp = *stack_f;
	if (*stack_f == NULL)
		return ;
	*stack_f = (*stack_f)->next;
	temp->next = *stack_t;
	*stack_t = temp;
	write(1, "pa\n", 3);
}
