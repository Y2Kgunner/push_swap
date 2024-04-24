/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:18:32 by ykulkarn          #+#    #+#             */
/*   Updated: 2022/05/31 13:23:22 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

//----------STRUCTS-------------//

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

//----------LIST_UTILS----------//

int		ft_atoi(char *str);
int		smallest(t_list *stack_a);
int		largest(t_list *stack);
int		pos(t_list *stack_a, int num);
int		list_len(t_list *stack_a);
void	swap(int *a, int *b);
void	insert_node(t_list **node, int n);
void	print_list(t_list *list);
char	**ft_split(char const *s, char c);
t_list	*swap_list(t_list *a, t_list *b);
t_list	*copy_list(t_list *stack_a);
void	delete(t_list **stack);
void	free_str(char **str);
void	free_null(char **str);

//----------ACTIONS-------------//

void	sa(t_list *stack);
void	ra(t_list **stack);
void	rra(t_list **stack);
void	pa(t_list **stack_f, t_list **stack_t);
void	sb(t_list *stack);
void	rb(t_list **stack);
void	rrb(t_list **stack);
void	pb(t_list **stack_f, t_list **stack_t);

//----------SORT_UTILS----------//

int		sort_3(t_list **stack_a);
int		sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
int		sort_5_or_less(t_list **stack_a, t_list **stack_b);
void	bubble_sort(t_list **head, int count, int i, int j);
void	sort_large(t_list **stack_a, t_list **stack_b);

//----------CHUNKS--------------//

int		push_chunks_large(t_list **stack_b, t_list **stack_a);
int		find_chunk_large(t_list *stack);
int		push_chunks_small(t_list **stack_b, t_list **stack_a);
int		find_chunk_small(t_list *stack);

//----------ERRORS--------------//

void	empty_args(int ac);
int		sort_verif(t_list *head);
void	parse(char *str);
void	parse_str(char *str, char **str2);
void	duplicate(t_list *head);

#endif