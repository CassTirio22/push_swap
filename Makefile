# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 12:48:35 by ctirions          #+#    #+#              #
#    Updated: 2021/09/21 15:48:53 by ctirions         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		=	$(shell tput -Txterm setaf 0)
RED			=	$(shell tput -Txterm setaf 1)
GREEN		=	$(shell tput -Txterm setaf 2)
YELLOW		=	$(shell tput -Txterm setaf 3)
LIGHTPURPLE	=	$(shell tput -Txterm setaf 4)
PURPLE		=	$(shell tput -Txterm setaf 5)
BLUE		=	$(shell tput -Txterm setaf 6)
WHITE		=	$(shell tput -Txterm setaf 7)
RESET		=	$(shell tput -Txterm sgr0)

SRCS		=	push_swap.c				\
				command1.c				\
				command2.c				\
				init.c					\
				top_stack.c				\
				solve_max_5.c			\
				utils.c					\
				find_biggest_smallest.c	\
				chunks.c				\
				hold_first_last.c		\
				
SRCS_BONUS	=	checker.c

OBJS		=	$(addprefix srcs/, ${SRCS:.c=.o})
OBJS_BONUS	=	$(addprefix srcs/, ${SRCS_BONUS:.c=.o})

NAME		=	push_swap.a
EXEC		=	push_swap

EXEC_BONUS	=	checker

LIBFT		=	./libft

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

.c.o:
				@${CC} ${CFLAGS} -c -I ./includes $< -o ${<:.c=.o}
				@echo "${LIGHTPURPLE}Compilation : $< --> .o${RESET}"

$(NAME):		${OBJS}
				@make -C ${LIBFT} full
				@cp ${LIBFT}/libft.a ${NAME}
				@ar -rcs ${NAME} ${OBJS}
				@ranlib ${NAME}
				@${CC} ${CFLAGS} ${NAME} -o ${EXEC}
				
all:			${NAME}

bonus:			${NAME} ${OBJS_BONUS}
				@ar -rcs ${NAME} ${OBJS_BONUS}
				@ranlib ${NAME}
				@${CC} ${CFLAGS} ${NAME} -o ${EXEC_BONUS}
clean:			
				@rm -f ${OBJS}
				@make -C ${LIBFT} clean
				@echo "${RED}Clean done !${RESET}"

fclean:			clean
				@rm -f ${NAME} ${EXEC}
				@make -C ${LIBFT} fclean
				@echo "${RED}Fclean done !${RESET}"

re:				fclean all

.PHONY:			all clean fclean re