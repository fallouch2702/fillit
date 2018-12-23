# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallouch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 18:59:48 by fallouch          #+#    #+#              #
#    Updated: 2018/11/15 18:52:50 by fallouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = $(wildcard srcs/*.c)
HEADER = $(wildcard includes/*.h)

all: $(NAME)

$(NAME):
		gcc	 -c -Wall -Werror -Wextra $(SRC) -I $(HEADER)
		ar rc $(NAME) *.o
		ranlib $(NAME)

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
