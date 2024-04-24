/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:19:17 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/23 19:24:23 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(t_list *stack_a)
{
	int	min;

	min = stack_a->data;
	while (stack_a != NULL)
	{
		if (stack_a->data < min)
			min = stack_a->data;
		stack_a = stack_a->next;
	}
	return (min);
}

int	largest(t_list *stack)
{
	int	max;

	max = -32767;
	while (stack != NULL)
	{
		if (max < stack->data)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	pos(t_list *stack_a, int num)
{
	t_list	*temp;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 1;
	len = list_len(stack_a);
	temp = stack_a;
	while (temp != NULL)
	{
		i = 0;
		while (temp->data != num && i < len)
		{
			i++;
		}
		if (temp->data == num)
			break ;
		temp = temp->next;
		j++;
	}
	return (j);
}
