# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelaizi <obelaizi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 16:53:56 by obelaizi          #+#    #+#              #
#    Updated: 2023/03/23 18:08:30 by obelaizi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Werror -Wall -Wextra

SRCS = $(wildcard ./Bonus/*.c ./gnl/*.c)
OBJS= $(SRCS:.c=.o)


all : $(NAME)

%.o: %.c ./Bonus/pipex.h ./gnl/get_next_line.h
	cc -c -g $(FLAGS) $< -o $@

	
$(NAME): $(OBJS)
	@cc -g $(OBJS) -o $(NAME) 

clean:
	@rm -f $(OBJS) 

fclean:clean
	@rm -f $(NAME)
	
re: fclean all