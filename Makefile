# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 16:53:56 by obelaizi          #+#    #+#              #
#    Updated: 2023/03/15 17:21:34 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = 

SRCS = $(wildcard ./Bonus/*.c ./gnl/*.c)
OBJS= $(SRCS:.c=.o)


all : $(NAME)

%.o: %.c ./Bonus/pipex.h ./gnl/get_next_line.h
	cc -c -g $(FLAGS) $< -o $@

	
$(NAME): $(OBJS)
	@cc -g $(OBJS) -o $(NAME) 

clean: 
	@rm -f $(OBJS) $(OBJS_BONUS) 

fclean:clean
	@rm -f $(NAME) $(NAME_BONUS)
	
re: fclean all