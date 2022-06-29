# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 16:59:09 by sel-kham          #+#    #+#              #
#    Updated: 2022/06/29 20:12:05 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##makefiles vars
CC := gcc
FLAGS := -Wall -Wextra -Werror -g
READLINE_FLAGS := -L /goinfre/ozahir/homebrew/opt/readline/lib -lreadline \
	-L /goinfre/ozahir/homebrew/opt/readline/lib -lhistory \
	-I /goinfre/ozahir/homebrew/opt/readline/include

# Colors
RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
BLUE := \033[0;34m

# Code
## directories
INCLUDES_DIR := includes
SRC_DIR := src
OBJ_DIR := obj

## Sub-directories
HEADERS_DIR := $(INCLUDES_DIR)/headers
LIBFT_DIR := $(INCLUDES_DIR)/libft

##objects declaraton
HEADER :=  $(HEADERS_DIR)/minishell.h 
src := lexer.c token.c

SRC:= $(addprefix $(SRC_DIR)/, $(src))

OBJ:= $(addprefix $(OBJ_DIR)/, $(src:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c    $(HEADERS)
	${CC} ${FLAGS}  -c $< -o $@



LIBFT := $(LIBFT_DIR)/libft.a


MAIN := $(SRC_DIR)/main.c  

NAME := minishell

## compiling actions

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(READLINE_FLAGS) $(MAIN)  $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)/



	


##general makefile rules

.PHONY: all clean fclean re

all: $(NAME)
	@echo "$(BLUE)\n        :::   :::   ::::::::::: ::::    ::: ::::::::::: ::::::::  :::    ::: :::::::::: :::        :::  \n      :+:+: :+:+:      :+:     :+:+:   :+:     :+:    :+:    :+: :+:    :+: :+:        :+:        :+:   \n    +:+ +:+:+ +:+     +:+     :+:+:+  +:+     +:+    +:+        +:+    +:+ +:+        +:+        +:+    \n   +#+  +:+  +#+     +#+     +#+ +:+ +#+     +#+    +#++:++#++ +#++:++#++ +#++:++#   +#+        +#+     \n  +#+       +#+     +#+     +#+  +#+#+#     +#+           +#+ +#+    +#+ +#+        +#+        +#+      \n #+#       #+#     #+#     #+#   #+#+#     #+#    #+#    #+# #+#    #+# #+#        #+#        #+#       \n###       ### ########### ###    #### ########### ########  ###    ### ########## ########## ##########$(WHITE)\n\n\t\t$(RED)By$(WHITE):\n\t\t\t$(GREEN)Soufiane El-khamlich $(WHITE)($(RED)MGS$(WHITE)) : $(BLUE)https://github.com/MGS15$(WHITE)\n\t\t\t$(GREEN)Ouail Zahir\t\t   $(WHITE): $(BLUE)https://github.com/weazah$(WHITE)\n"

clean:
	rm -rf $(OBJ) 
	make clean -C $(LIBFT_DIR)/
fclean: clean 
	make fclean -C $(LIBFT_DIR)/
	rm -rf $(NAME)
re: fclean all