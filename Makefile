# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mail <ykulkarn@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 11:55:06 by ykulkarn          #+#    #+#              #
#    Updated: 2022/05/27 05:25:15 by ykulkarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS 	=	chunks.c small_actions.c small_sort.c actions_a.c actions_b.c	\
			large_sort.c errors.c ft_split.c list_utils1.c list_utils2.c	\
			list_utils3.c main.c											\

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -g3

$(NAME):	$(OBJS)
			 $(CC) $(SRCS) $(CFLAGS) -o $(NAME)  

all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re