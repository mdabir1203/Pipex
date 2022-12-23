# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabbas <mabbas@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 01:03:33 by mabbas            #+#    #+#              #
#    Updated: 2022/12/23 03:05:17 by mabbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



PROG	= pipex
PROG_B  = pipex_bonus

SRCS 	= srcs/pipex.c srcs/utils.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

SRCS_B	= srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c
OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= srcs/pipex_bonus.c

HEADER	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling libft---"
					@make re -C ./lib/libft
					@$(CC) ${OBJS} -Llib/libft -lft -o ${PROG}
					@echo "\033[32mPipex Compiled! (\033[31m\033[32m_\033[31m\033[32m)\n"


bonus:		${PROG_B}

${PROG_B}:	${OBJS_B}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./lib/libft
					@$(CC) ${OBJS_B} -Llib/libft -lft -o pipex
					@echo "\033[32mPipex Bonus Compiled!(\033[31m\033[32m_\033[31m\033[32m)\n"

clean:
					@make clean -C ./lib/libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./lib/libft
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re re_bonus bonus