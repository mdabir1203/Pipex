# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 02:39:41 by mabbas            #+#    #+#              #
#    Updated: 2022/12/19 04:15:44 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex
NAME_B  = pipex_bonus
#define compiler and flags for Debugger
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra -g
INC     = -I ./includes/

LIBFT  	= ./libs/libft/

SRCS = src/main.c \
	   src/pipex.c \
	   src/pipex_utils.c \
	   libs/gnl/get_next_line.c \
	   libs/gnl/get_next_line_utils.c

SRCS_B = src/pipex_bonus.c \
		 src/pipex_utils.c \
		 src/pipex_utils_bonus.c \
		 libs/gnl/get_next_line.c \
		 libs/gnl/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}


SUBM_STATE := $(shell find libs/libft -type f && libs/gnl -type f)

ifeq ($(SUBM_STATE),)
SUBM_FLAG	= submodule
else
SUBM_FLAG 	=
endif

NC		:= \033[m
B_RED	:= \033[1;31m
RED 	:= \033[0;31m
B_GREEN	:= \033[1;32m
GREEN 	:= \033[0;33m
B_BLUE 	:= \033[1;34m
BLUE 	:= \033[0;34m
PURPLE	:= \033[0;35m
WHCOLOR	:= \033[0;40m


UNAME = $(shell uname -s)

ifeq ($(UNAME),Linux)
	VALGRIND = valgrind -q --leak-check=full --track-origin=yes
else 
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo You are Mac stupid!_!')
endif

all: libft $(NAME)

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

submodule:
	git submodule init
	git submodule update

libft:
	@echo "____!!!$(BLUE)----- Compiling Libft------$(NC)"
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBFT) bonus
	@echo "Compiling Libft:	\033[1;32mOK\033[m"
	

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)libft.a -o $(NAME)
	@echo "Pipex:	\033[1;32mCOMPILED⛓️\033[m"

clean:
	@echo "$(PURPLE)🚿 Sweeping in progress $(B_RED)🚿"
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@sleep 0.5
	@echo "$(B_GREEN) Swept off 🧹🧹🧹$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN) I am gone forever🚿🚿🚿 $(B_RED)🚿🚿 $(NC)"

re: fclean all

.phony: all libft clean fclean
.silent: all libft clean fclean

	