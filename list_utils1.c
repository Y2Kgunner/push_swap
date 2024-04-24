/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:50:27 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/31 11:36:45 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(t_list **node, int n)
{
	t_list	*temp;
	t_list	*ptr;

	temp = (t_list *)malloc(sizeof(t_list));
	temp->data = n;
	temp->next = NULL;
	if (*node == NULL)
		*node = temp;
	else
	{
		ptr = *node;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

void	delete(t_list **stack)
{
	t_list	*t1;
	t_list	*t2;

	t1 = *stack;
	t2 = NULL;
	while (t1 != NULL)
	{
		t2 = t1->next;
		free(t1);
		t1 = t2;
	}
	*stack = NULL;
}

t_list	*copy_list(t_list *stack_a)
{
	t_list	*copy;

	if (stack_a == NULL)
		return (NULL);
	else
	{
		copy = (t_list *)malloc(sizeof(t_list));
		copy->data = stack_a->data;
		copy->next = copy_list(stack_a->next);
		return (copy);
	}
	delete(&copy);
}

void	free_str(char **str)
{
	int	j;

	j = 0;
	while (str[j])
		free (str[j++]);
	free (str);
}

void	free_null(char **str)
{
	if (*str == NULL)
	{
		free_str(str);
		exit (0);
	}
}
