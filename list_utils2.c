/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:01:56 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/31 13:23:11 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

t_list	*swap_list(t_list *a, t_list *b)
{
	t_list	*t;

	t = b->next;
	b->next = a;
	a->next = t;
	return (b);
}

int	list_len(t_list *stack_a)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = stack_a;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	long long	i;
	long long	j;
	long long	x;

	i = 0;
	x = 0;
	j = 1;
	while (str[i] == '+' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-')
	{
		j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (str[i] - 48) + (x * 10);
		i++;
	}
	if ((x * j) > 2147483647 || (x * j) < -2147483648)
	{	
		write (2, "Error\n", 6);
		exit (0);
	}
	return (x * j);
}
