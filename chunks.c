/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:01:51 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/29 21:53:32 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_chunk_small(t_list *stack)
{
	int		i;
	t_list	*temp;

	temp = stack;
	i = 0;
	while (i < (list_len(temp) / 7) && temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (temp->data);
}

int	push_chunks_small(t_list **stack_a, t_list **stack_b)
{
	int		list_size;
	int		chunk;
	t_list	*temp;

	list_size = list_len(*stack_a);
	temp = copy_list(*stack_a);
	bubble_sort(&temp, list_len(temp), 0, 0);
	while (list_size > 1)
	{
		chunk = find_chunk_small(temp);
		list_size = list_len(*stack_a);
		if ((*stack_a)->data <= chunk)
		{	
			pb(stack_a, stack_b);
			delete(&temp);
			temp = copy_list(*stack_a);
			bubble_sort(&temp, list_len(temp), 0, 0);
		}
		else
			ra(stack_a);
	}
	return (0);
}

int	find_chunk_large(t_list *stack)
{
	int		i;
	t_list	*temp;

	temp = stack;
	i = 0;
	while (i < (list_len(temp) / 14) && temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (temp->data);
}

int	push_chunks_large(t_list **stack_a, t_list **stack_b)
{
	int		list_size;
	int		chunk;
	t_list	*temp;

	list_size = list_len(*stack_a);
	temp = copy_list(*stack_a);
	bubble_sort(&temp, list_len(temp), 0, 0);
	while (list_size > 1)
	{
		chunk = find_chunk_large(temp);
		list_size = list_len(*stack_a);
		if ((*stack_a)->data <= chunk)
		{	
			pb(stack_a, stack_b);
			delete(&temp);
			temp = copy_list(*stack_a);
			bubble_sort(&temp, list_len(temp), 0, 0);
		}
		else
			ra(stack_a);
	}
	delete(&temp);
	return (0);
}
