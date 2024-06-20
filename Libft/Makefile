# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 20:30:21 by seantoni          #+#    #+#              #
#    Updated: 2024/02/12 23:03:37 by seantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_strlen.c 
BON			= 

OBJS			= ${SRC:.c=.o}
BON_OBJS		= ${BON:.c=.o}

MAKEFILE		= Makefile
NAME			= libft.a
INCLUDE			= libft.h
LIBC			= ar rcs
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: ${NAME}

${OBJS}: %.o: %.c ${INCLUDE} ${MAKEFILE}
	${CC} ${CFLAGS} -c $< -o $@
${BON_OBJS}: %.o: %.c ${INCLUDE} ${MAKEFILE}
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS}
	${LIBC} ${NAME} ${OBJS}
bonus: ${NAME} ${BON_OBJS}
	${LIBC} ${NAME} ${BON_OBJS}
	@touch bonus

clean:
	${RM} ${OBJS} ${BON_OBJS}

fclean: clean
	${RM} ${NAME} bonus

re: fclean all
