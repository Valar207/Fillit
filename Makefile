# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmousset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 15:36:07 by jmousset          #+#    #+#              #
#    Updated: 2019/06/04 16:57:11 by vrossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = main.c\
	   ft_check.c\
	   ft_board.c\
	   ft_store.c\
	   ft_solve.c

HDR = fillit.h

LIB_PATH = ./libft/

LIB = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	gcc $(FLAGS) -c $(SRCS) -I $(HDR)
	gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all

.PHONY: all clean fclean re
