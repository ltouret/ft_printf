# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 13:00:20 by ltouret           #+#    #+#              #
#    Updated: 2020/02/26 18:00:23 by ltouret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/ft_printf.c

OBJS = ${SRCS:.c=.o}

CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -C libft/ bonus
		cp libft/libft.a ./${NAME}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}
		make -C libft/ clean

fclean:	clean
		${RM} ${NAME}
		${RM} libft/libft.a

re:		fclean all

test:	${OBJS}
		make -C libft/ bonus 
		cp libft/libft.a ./${NAME}
		ar rcs ${NAME} ${OBJS}
		${CC} ${CFLAGS} test.c libftprintf.a
		#diff -c dif.txt dif2.txt
		@echo "\n--------- OUTPUT : ---------"
		@./a.out

.PHONY: all clean fclean re
