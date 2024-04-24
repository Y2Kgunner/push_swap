/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:34:43 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/31 12:01:17 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_verif(t_list *head)
{
	t_list	*i;

	i = head;
	while (i->next != NULL)
	{
		if (i->data < i->next->data)
			i = i->next;
		else
			return (0);
	}
	return (1);
}

void	duplicate(t_list *head)
{	
	t_list	*temp;
	t_list	*temp2;

	temp2 = head;
	while (head->next != NULL)
	{
		temp = head->next;
		while (temp != NULL)
		{
			if (head->data == temp->data)
			{
				write(2, "Error\n", 6);
				delete(&temp2);
				exit (0);
			}
			temp = temp->next;
		}
		head = head->next;
	}
}

void	empty_args(int ac)
{
	if (ac == 1)
		exit (0);
}

void	parse_str(char *str, char **str2)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 58 || str[i] <= 42 || str[i] == 44
			|| str[i] == 46 || str[i] == 47
			|| (str[i] == '-' && str[i + 1] == '+')
			|| (str[i] == '+' && str[i + 1] == '-')
			|| (str[i] == '+' && str[i + 1] == '+')
			|| (str[i] == '-' && str[i + 1] == '-')
			|| (str[i] == '+' && str[i + 1] == '\0')
			|| (str[i] == '-' && str[i + 1] == '\0')
			|| (str[i] == '+' && str[i + 1] == '0')
			|| (str[i] == '-' && str[i + 1] == '0'))
		{
			write(2, "Error\n", 6);
			free_str(str2);
			exit (0);
		}
		i++;
	}
}

void	parse(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 58 || str[i] <= 42 || str[i] == 44
			|| str[i] == 46 || str[i] == 47
			|| (str[i] == '-' && str[i + 1] == '+')
			|| (str[i] == '+' && str[i + 1] == '-')
			|| (str[i] == '+' && str[i + 1] == '+')
			|| (str[i] == '-' && str[i + 1] == '-')
			|| (str[i] == '+' && str[i + 1] == '\0')
			|| (str[i] == '-' && str[i + 1] == '\0')
			|| (str[i] == '+' && str[i + 1] == '0')
			|| (str[i] == '-' && str[i + 1] == '0'))
		{
			write(2, "Error\n", 6);
			exit (0);
		}
		i++;
	}
}
