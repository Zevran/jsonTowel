# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaelreyrol <gaelreyrol@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 01:09:17 by gaelreyrol        #+#    #+#              #
#    Updated: 2014/02/07 01:28:34 by gaelreyrol       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libjson
LIB_EXT		= a
LIB_NAME	= $(NAME).$(LIB_EXT)

LIBFT_NAME = libft
LIBFT_TARGET = $(LIBFT_NAME).$(LIB_EXT)
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT_TARGET)

INC_DIR = inc -I -I $(LIBFT_DIR)/inc
SRC_DIR = ./src
OBJ_DIR = ./obj

UNITS = main.c

UNITS_O = $(UNITS:.c=.o)
SRCS = $(patsubst %,$(SRC_DIR)/%,$(UNITS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(UNITS_O))
FLAGS = -Wall -Wextra -Werror -std=c89 -ansi -pedantic -Qunused-arguments
CFLAGS = $(FLAGS) -ggdb
LDFLAGS = $(LIBFT_LIB)
CC = clang $(CFLAGS)
LD = ar rcs -o $(NAME)
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(LD) $^  $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c -I$(INC_DIR) -o $@ $<

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
