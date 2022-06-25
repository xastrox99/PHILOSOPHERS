# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 16:06:52 by mbaazzy           #+#    #+#              #
#    Updated: 2022/06/18 14:02:34 by mbaazzy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC = main.c ft_atoi.c data_init.c locks.c time.c print.c utils.c
OBJ = $(SRC:.c=.o)
NAME = philo
HEADER = philosophers.h

CC = gcc

FLAGS = -Wall -Wextra -Werror


all : $(NAME)


$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $@ -lpthread

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS) 

re: fclean all