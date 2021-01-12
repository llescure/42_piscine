# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llescure <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 20:28:19 by llescure          #+#    #+#              #
#    Updated: 2020/08/26 17:46:19 by llescure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
			

OBJS 	= ${SRCS:.c=.o}

HEADER	= includes

NAME	= libft.a

CC 		= gcc
RM 		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

all: 		${NAME}

${NAME}:	${OBJS}	
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
