# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 15:17:02 by mskerba           #+#    #+#              #
#    Updated: 2022/06/18 11:10:07 by mskerba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = philosophers_bonus.c ft_atoi_bonus.c  philo_man_bonus.c time_bonus.c creat_philo_bonus.c  utiles_bonus.c
 
CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo.a

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(BONUS) $(MFLAGS) -o philo_bonus
	ar -rcs $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME) philo_bonus

re: fclean all