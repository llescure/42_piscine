# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaudot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/22 22:23:00 by abaudot           #+#    #+#              #
#    Updated: 2020/08/23 23:13:39 by abaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix ${SDIR}/, dictionary.c display.c ft_split.c main.c pre_display.c read.c utile.c utile_main.c utile_read.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(addprefix ${IDIR}/, dictionary.h main.h read.h utile.h)
BIN = ./rush-02 
IDIR = ./includes
SDIR = ./srcs
ODIR = ./obj

%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(IDIR) -c -o $@ $<

all: $(BIN)

$(BIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)
	mv $(SDIR)/*.o $(ODIR)
clean:
	rm -f $(ODIR)/*.o

fclean: clean
	rm -f $(BIN)
