# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 13:49:04 by ialousse          #+#    #+#              #
#    Updated: 2023/11/13 13:49:05 by ialousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	$(shell tput -Txterm setaf 1)
GREEN	=	$(shell tput -Txterm setaf 2)
PURPLE	=	$(shell tput -Txterm setaf 5)
BLUE	=	$(shell tput -Txterm setaf 6)
RESET	=	$(shell tput -Txterm sgr0)

SRCSDIR = 	srcs/
OBJSDIR = 	objs/

RPATH	=	/Users/$(USER)/.brew/opt/readline/

RLFLAGS	=	-L $(RPATH)lib -I $(RPATH)include -Wno-unused-command-line-argument

FILES =		minishell.c					\
			commands/aff_env.c			\
			commands/cd.c				\
			commands/echo.c				\
			commands/exit.c				\
			commands/export.c			\
			commands/pwd.c				\
			commands/unset.c			\
			exec/big_exec.c				\
			exec/exec.c					\
			exec/pipe.c					\
			exec/redirections.c			\
			init/init_env.c				\
			init/init.c					\
			init/shlvl.c				\
			parser/env.c				\
			parser/init_cmd.c			\
			parser/init_heredoc.c		\
			parser/init_inoutfd.c		\
			parser/parse.c				\
			parser/quotes.c				\
			signals/sig_call.c			\
			signals/signals.c			\
			signals/signals_defaults.c	\
			signals/signals_in.c		\
			signals/signals_out.c		\
			utils/free.c				\
			utils/utils.c				\
			utils/utils2.c

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(patsubst srcs%.c, objs%.o, $(SRCS))

NAME	=	minishell
RM		=	rm -f
CC		=	gcc -Wall -Wextra -Werror -g

all:		$(NAME)

$(NAME):	$(OBJS)
			@make full -C ./libft
			@$(CC) $(RLFLAGS) -lreadline -o $(NAME) $(OBJS) libft/libft.a
			@echo "\r[$(GREEN)✓$(RESET)] minishell created              "
			
objs/%.o:	srcs/%.c
			@printf "\r[$(PURPLE)✓$(RESET)] compilation of $<           "
			@$(CC) $(RLFLAGS) -I ./includes -c $^ -o $@

clean:
			@make clean -C ./libft
			@$(RM) $(OBJS)
			@echo "[$(BLUE)✓$(RESET)] objects erased"

fclean:
			@make fclean -C ./libft		
			@$(RM) $(OBJS)
			@echo "[$(BLUE)✓$(RESET)] objects erased"
			@$(RM) $(NAME)
			@echo "[$(RED)✓$(RESET)] minishell erased"

re:			fclean $(NAME)

.PHONY:		all clean fclean re minishell
