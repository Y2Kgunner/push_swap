/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:49:32 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/27 05:46:25 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_list **head, int count, int i, int j)
{
	t_list	**h;
	t_list	*p1;
	t_list	*p2;
	int		swapped;

	i = 0;
	while (i <= count && swapped != 0)
	{
		h = head;
		swapped = 0;
		j = 0;
		while (j < count - i - 1)
		{
			p1 = *h;
			p2 = p1->next;
			if (p1->data > p2->data)
			{
				*h = swap_list(p1, p2);
				swapped = 1;
			}
			h = &(*h)->next;
			j++;
		}
		i++;
	}
}

static void	if_statements(t_list **stack_a, t_list **stack_b, int posi)
{
	if (posi == 1)
		pa(stack_b, stack_a);
	else if (posi == list_len(*stack_b))
	{
		rrb(stack_b);
		pa(stack_b, stack_a);
	}
	else if (posi > (list_len(*stack_b) / 2) && posi != list_len(*stack_b))
	{
		while (posi > (list_len(*stack_b) / 2) && posi != 1)
		{
			rrb(stack_b);
			posi = pos(*stack_b, largest(*stack_b));
		}
		pa(stack_b, stack_a);
	}
	else if (posi <= (list_len(*stack_b) / 2) && posi != 1)
	{
		while (posi <= (list_len(*stack_b) / 2) && posi != 1)
		{
			rb(stack_b);
			posi = pos(*stack_b, largest(*stack_b));
		}
		pa(stack_b, stack_a);
	}
}

void	sort_large(t_list **stack_a, t_list **stack_b)
{
	int	posi;
	int	i;
	int	list_size;

	i = 0;
	list_size = list_len(*stack_b);
	posi = pos(*stack_b, largest(*stack_b));
	while (i < list_size && stack_b != NULL)
	{
		posi = pos(*stack_b, largest(*stack_b));
		if_statements(stack_a, stack_b, posi);
		i++;
	}
}
