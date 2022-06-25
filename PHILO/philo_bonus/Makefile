# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 16:06:52 by mbaazzy           #+#    #+#              #
#    Updated: 2022/06/18 19:46:25 by mbaazzy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC = philo_b.c data_init_b.c locks_b.c print_b.c time_b.c ft_atoi.c utils.c
OBJ = $(SRC:.c=.o)
NAME = philo_bonus
HEADER = philosophers_bonus.h

CC = gcc

FLAGS = -Wall -Wextra -Werror


all : $(NAME)


$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS) 

re: fclean all