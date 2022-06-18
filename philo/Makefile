# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 15:17:02 by mskerba           #+#    #+#              #
#    Updated: 2022/06/18 13:30:41 by mskerba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philosophers.c ft_atoi.c  philo_man.c time.c check_life.c 
 
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo.a

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(BONUS) $(MFLAGS) -o philo
	ar -rcs $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME) philo

re: fclean all
