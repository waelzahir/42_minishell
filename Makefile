RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
BLUE := \033[0;34m

# Code
## directories
INCLUDES_DIR := includes
SRC_DIR = src
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror -g 

## Sub-directories
HEADERS_DIR = $(INCLUDES_DIR)/headers
LIBFT_DIR = $(INCLUDES_DIR)/libft
READ=  -L /goinfre/$(USER)/homebrew/opt/readline/lib -lreadline \
	-L /goinfre/$(USER)/homebrew/opt/readline/lib -lhistory \
	-I /goinfre/$(USER)/homebrew/opt/readline/include
src= lexer.c lexer_extend.c lexer_utils.c parser.c parser_utils.c shell.c t_stack.c
SRC= $(addprefix $(SRC_DIR)/,$(src))
OBJ := $(SRC:.c=.o)
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS)  -c $< -o $@

MAIN := main.c

NAME := minishell

LIBFT := $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME) 
	@echo "$(BLUE)\n        :::   :::   ::::::::::: ::::    ::: ::::::::::: ::::::::  :::    ::: :::::::::: :::        :::  \n      :+:+: :+:+:      :+:     :+:+:   :+:     :+:    :+:    :+: :+:    :+: :+:        :+:        :+:   \n    +:+ +:+:+ +:+     +:+     :+:+:+  +:+     +:+    +:+        +:+    +:+ +:+        +:+        +:+    \n   +#+  +:+  +#+     +#+     +#+ +:+ +#+     +#+    +#++:++#++ +#++:++#++ +#++:++#   +#+        +#+     \n  +#+       +#+     +#+     +#+  +#+#+#     +#+           +#+ +#+    +#+ +#+        +#+        +#+      \n #+#       #+#     #+#     #+#   #+#+#     #+#    #+#    #+# #+#    #+# #+#        #+#        #+#       \n###       ### ########### ###    #### ########### ########  ###    ### ########## ########## ##########$(WHITE)\n\n\t\t$(RED)By$(WHITE):\n\t\t\t$(GREEN)Soufiane El-khamlich $(WHITE)($(RED)MGS$(WHITE)) : $(BLUE)https://github.com/MGS15$(WHITE)\n\t\t\t$(GREEN)Ouail Zahir\t\t   $(WHITE): $(BLUE)https://github.com/weazah$(WHITE)\n"

$(NAME): $(LIBFT) $(OBJ) $(MAIN)
	$(CC) $(CFLAGS) $(READ) $(MAIN) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ)

fclean: clean 
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)
re: fclean all