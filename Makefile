# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 18:28:44 by ozahir            #+#    #+#              #
#    Updated: 2022/07/24 15:14:00 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minishell
CC= gcc
MAIN= main.c
FLAGS= -Wall -Wextra -Werror
READLINE= -L /goinfre/$(USER)/homebrew/opt/readline/lib -lreadline \
	-L /goinfre/$(USER)/homebrew/opt/readline/lib -lhistory \
	-I /goinfre/$(USER)/homebrew/opt/readline/include
LIBFT= libft/libft.a
INC= includes/minishell.h

srcs= lexer.c parser.c tokenizer.c env.c shell.c
SRC_D = srcs
OBJ_D = obj
SRC = $(addprefix $(SRC_D)/, $(srcs))
OBJ = $(addprefix $(OBJ_D)/, $(srcs:.c=.o))

$(OBJ_D)/%.o: $(SRC_D)/%.c    $(INC)
	${CC} ${FLAGS}  -c $< -o $@

all: $(NAME)

$(MAIN): $(INC)

$(NAME): $(LIBFT) $(OBJ) $(SRC) $(MAIN)
	@$(CC) $(FLAGS) $(READLINE) $(MAIN) $(OBJ) $(LIBFT) -o $(NAME)
$(LIBFT):
	make -C libft/
clean:
	rm -rf $(OBJ);
	make clean -C libft/
fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

	