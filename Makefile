# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seantoni <seantoni@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 01:44:37 by seantoni          #+#    #+#              #
#    Updated: 2024/02/12 23:05:56 by seantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_printf.c ft_putchar.c ft_putstr.c ft_puthexa.c ft_putnbr.c ft_putnbr_unsig.c ft_puthexa_min.c ft_puthexa_may.c

OBJS		= ${SRC:.c=.o}

NAME		= libftprintf.a
INCLUDE		= ft_printf.h
MAKEFILE	= Makefile
LIBFT_DIR	= Libft
LIBFT		= ${LIBFT_DIR}/libft.a
LIBFT_INCL	= ${LIBFT_DIR}/libft.h
LIBFT_MAKE	= ${LIBFT_DIR}/Makefile
LIBFT_FUENTE	= ${wildcard ${LIBFT_DIR}/*.c}

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBC		= ar rcs
RM			= rm -f

all: ${NAME}

$(LIBFT): ${INCLUDE} ${MAKEFILE} ${LIBFT_MAKE} ${LIBFT_INCL} ${LIBFT_FUENTE}
	@$(MAKE) -C $(LIBFT_DIR)

${OBJS}: %.o: %.c ${INCLUDE} ${MAKEFILE} ${LIBFT_INCL} ${LIBFT_MAKE} ${LIBFT_FUENTE}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${LIBFT} ${OBJS}
	@cp ${LIBFT} ${NAME}
	${LIBC} ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}
	@${MAKE} -C ${LIBFT_DIR} clean

fclean: clean
	@${RM} ${NAME}
	@${RM} ${LIBFT}
	@${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re
