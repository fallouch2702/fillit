# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallouch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 18:59:48 by fallouch          #+#    #+#              #
#    Updated: 2018/12/03 18:52:46 by fallouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = aux.c aux2.c check.c main.c map.c reader.c
HEADER = fillit.h
LIBFT = libft/

all: $(NAME)

$(NAME): clean
		make -C $(LIBFT)
		gcc	 -c -Wall -Werror -Wextra $(SRC) -I $(HEADER)
		gcc -o $(NAME) *.o -I $(HEADER) -L $(LIBFT) -lft

clean:
		rm -rf *.o
		make -C $(LIBFT) clean

fclean: clean
		make -C $(LIBFT) fclean
		/bin/rm -f $(NAME)

re: fclean all
