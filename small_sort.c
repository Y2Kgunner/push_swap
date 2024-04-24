/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_or_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:42:27 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/23 17:31:24 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_5_or_less(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = list_len(*stack_a);
	if (len == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(*stack_a);
	}
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else if (len == 5)
		sort_5(stack_a, stack_b);
	return (0);
}
