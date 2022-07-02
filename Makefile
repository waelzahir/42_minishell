# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 16:59:09 by sel-kham          #+#    #+#              #
#    Updated: 2022/07/02 19:10:09 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

## Includes Sub-directories
HEADERS_DIR := $(INCLUDES_DIR)/headers
LIBFT_DIR := $(INCLUDES_DIR)/libft

## SRC Sub-directories
INIT_DIR := $(SRC_DIR)/ini
APP_DIR := $(SRC_DIR)/app
HELPERS_DIR := $(SRC_DIR)/helpers

## Compounents
LIBFT := $(LIBFT_DIR)/libft.a
HEADERS := minishell.h types.h
HEADERS := $(addprefix $(HEADERS_DIR)/, $(HEADERS))

MAIN := $(SRC_DIR)/main.c

READLINE := $(shell brew --prefix readline)
CFLAGS := -Wall -Wextra -Werror
IFLAGS := -I $(READLINE)/include
LFLAGS := -L $(READLINE)/lib -lreadline \
        -L $(READLINE)/lib -lhistory

REMOVE := rm -rf

NAME := minishell

SRC := test.c

.PHONY: all clean fclean re

all: $(NAME)
	@echo "$(BLUE)\n        :::   :::   ::::::::::: ::::    ::: ::::::::::: ::::::::  :::    ::: :::::::::: :::        :::  \n      :+:+: :+:+:      :+:     :+:+:   :+:     :+:    :+:    :+: :+:    :+: :+:        :+:        :+:   \n    +:+ +:+:+ +:+     +:+     :+:+:+  +:+     +:+    +:+        +:+    +:+ +:+        +:+        +:+    \n   +#+  +:+  +#+     +#+     +#+ +:+ +#+     +#+    +#++:++#++ +#++:++#++ +#++:++#   +#+        +#+     \n  +#+       +#+     +#+     +#+  +#+#+#     +#+           +#+ +#+    +#+ +#+        +#+        +#+      \n #+#       #+#     #+#     #+#   #+#+#     #+#    #+#    #+# #+#    #+# #+#        #+#        #+#       \n###       ### ########### ###    #### ########### ########  ###    ### ########## ########## ##########$(WHITE)\n\n\t\t$(RED)By$(WHITE):\n\t\t\t$(GREEN)Soufiane El-khamlich $(WHITE)($(RED)MGS$(WHITE)) : $(BLUE)https://github.com/MGS15$(WHITE)\n\t\t\t$(GREEN)Ouail Zahir\t\t   $(WHITE): $(BLUE)https://github.com/weazah$(WHITE)\n"

$(NAME): $(MAIN) $(LIBFT)
	@$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) $(MAIN) $(LIBFT) -o $@
	
$(LIBFT): $(shell find $(LIBFT_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)libft files..."
	@$(MAKE) -C $(LIBFT_DIR)/

clean:
	@echo "$(RED)Removing $(WHITE)Mini-Shell object files..."
	@$(REMOVE) $(OBJ_DIR)
	@echo "$(RED)Removing $(WHITE)libft object files..."
	@$(MAKE) -C $(LIBFT_DIR)/ clean

fclean: clean
	@echo "$(RED)Removing $(WHITE)Mini-Shell executable file..."
	@$(REMOVE) $(NAME)
	@echo "$(RED)Removing $(WHITE)libft static library file..."
	@$(MAKE) -C $(LIBFT_DIR)/ fclean

re: fclean all
 