# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 16:53:56 by obelaizi          #+#    #+#              #
#    Updated: 2023/03/09 17:23:48 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)
OBJS= $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c pipex.h
	cc -c $(FLAGS) $<

	
$(NAME): $(OBJS)
	@cc $(OBJS) -o $(NAME)

clean: 
	@rm -f $(OBJS) $(OBJS_BONUS) 

fclean:clean
	@rm -f $(NAME) $(NAME_BONUS)
	
re: fclean all