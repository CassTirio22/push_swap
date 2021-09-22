# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 12:48:35 by ctirions          #+#    #+#              #
#    Updated: 2021/09/22 18:30:13 by ctirions         ###   ########.fr        #
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
				utils2.c				\
				find_biggest_smallest.c	\
				chunks.c				\
				hold_first_last.c		\
				
SRCS_BONUS	=	checker.c				\
				command1.c				\
				command2.c				\
				init.c					\
				top_stack.c				\
				utils.c					\
				utils2.c				\

OBJS		=	$(addprefix srcs/push_swap/, ${SRCS:.c=.o})
OBJS_BONUS	=	$(addprefix srcs/checker/, ${SRCS_BONUS:.c=.o})

NAME		=	push_swap.a
EXEC		=	push_swap

NAME_BONUS	=	checker.a
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

bonus:			${OBJS_BONUS}
				@make -C ${LIBFT} full
				@cp ${LIBFT}/libft.a ${NAME_BONUS}
				@ar -rcs ${NAME_BONUS} ${OBJS_BONUS}
				@ranlib ${NAME_BONUS}
				@${CC} ${CFLAGS} ${NAME_BONUS} -o ${EXEC_BONUS}
				
clean:			
				@rm -f ${OBJS} ${OBJS_BONUS}
				@make -C ${LIBFT} clean
				@echo "${RED}Clean done !${RESET}"

fclean:			clean
				@rm -f ${NAME} ${NAME_BONUS} ${EXEC} ${EXEC_BONUS}
				@make -C ${LIBFT} fclean
				@echo "${RED}Fclean done !${RESET}"

re:				fclean all

.PHONY:			all clean fclean re