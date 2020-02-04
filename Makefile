# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 13:00:20 by ltouret           #+#    #+#              #
#    Updated: 2020/02/04 19:17:05 by ltouret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/ft_printf.c

OBJS = ${SRCS:.c=.o}

CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		@make -C libft/ bonus
		@cp libft/libft.a ./${NAME}
		@ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}
		make -C libft/ clean

fclean:	clean
		${RM} ${NAME}
		${RM} libft/libft.a

re:		fclean all

test:	all
		@cc test.c libftprintf.a && ./a.out
.PHONY: all clean fclean re
