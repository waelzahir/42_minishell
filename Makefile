# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <ozahir@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 23:13:31 by sel-kham          #+#    #+#              #
#    Updated: 2022/08/30 15:48:48 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
BLUE := \033[0;34m

# DIRECTORIES
INCLUDES_DIR := includes
SRC_DIR := src
OBJ_DIR := obj
GNL_DIR := gnl
READLINE_DIR := /goinfre/$(USER)/homebrew/opt/readline

## SUB-DIRECTORIES
HEADERS_DIR := $(INCLUDES_DIR)/headers
LIBFT_DIR := $(INCLUDES_DIR)/libft
BUILTINS_DIR := $(SRC_DIR)/builtins
GNL_DIR := $(INCLUDES_DIR)/gnl

# FLAGS
CFLAGS :=  -g
RFLAGS := -lreadline
LFLAGS := -L $(READLINE_DIR)/lib
IFLAGS := -I $(READLINE_DIR)/include

# HEADERS
HEADERS := builtins.h datatypes.h expander.h lexer.h minishell.h parser.h stack.h tree.h
HEADERS := $(addprefix $(HEADERS_DIR)/, $(HEADERS)) $(GNL_DIR)/get_next_line.h

# SOURCES
BUILTINS := cd.c echo.c env.c export.c pwd.c unset.c
BUILTINS := $(addprefix $(BUILTINS_DIR)/, $(BUILTINS))

GNL := get_next_line.c get_next_line_utils.c
GNL := $(addprefix $(GNL_DIR)/, $(GNL))

SRC := binary_tree.c execution.c lexer_advance.c lexer_init.c path.c shell.c token_join.c env_f.c expander.c lexer_end.c parser.c redirection.c stack.c \
		str_handler.c helpers.c signals_handler.c $(BUILTINS) $(GNL) her_doc.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

LIBFT := $(LIBFT_DIR)/libft.a

MAIN := main.c

# Base code for the Makefile
.PHONY: all clean fclean re

NAME := minishell

all: $(NAME)
	@echo "$(BLUE)\n        :::   :::   ::::::::::: ::::    ::: ::::::::::: ::::::::  :::    ::: :::::::::: :::        :::  \n      :+:+: :+:+:      :+:     :+:+:   :+:     :+:    :+:    :+: :+:    :+: :+:        :+:        :+:   \n    +:+ +:+:+ +:+     +:+     :+:+:+  +:+     +:+    +:+        +:+    +:+ +:+        +:+        +:+    \n   +#+  +:+  +#+     +#+     +#+ +:+ +#+     +#+    +#++:++#++ +#++:++#++ +#++:++#   +#+        +#+     \n  +#+       +#+     +#+     +#+  +#+#+#     +#+           +#+ +#+    +#+ +#+        +#+        +#+      \n #+#       #+#     #+#     #+#   #+#+#     #+#    #+#    #+# #+#    #+# #+#        #+#        #+#       \n###       ### ########### ###    #### ########### ########  ###    ### ########## ########## ##########$(WHITE)\n\n\t\t$(RED)By$(WHITE):\n\t\t\t$(GREEN)Soufiane El-khamlich $(WHITE)($(RED)MGS$(WHITE)) : $(BLUE)https://github.com/MGS15$(WHITE)\n\t\t\t$(GREEN)Ouail Zahir\t\t   $(WHITE): $(BLUE)https://github.com/weazah$(WHITE)\n"

$(NAME): $(MAIN) $(HEADERS) $(OBJ) $(LIBFT) $(GNL)
	@$(CC) $(RFLAGS) $(CFLAGS) $(LFLAGS) $(IFLAGS) $(MAIN) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BUILTINS_DIR)/%.c $(HEADERS) $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c $(HEADERS) $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT): $(shell find $(LIBFT_DIR) -name "*.c" -type f)
	@make -C $(LIBFT_DIR)
	@make clean -C  $(LIBFT_DIR)

clean:
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all