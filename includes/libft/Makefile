FLAGS := -Wall -Wextra -Werror -g
NAME := libft.a
SRC_M := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_toupper.c ft_tolower.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_bzero.c ft_atoi.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_strnstr.c ft_strlcat.c ft_strlcpy.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c



OBJ_M := $(SRC_M:.c=.o)


.PHONY: all clean fclean re 

all: $(NAME)

$(NAME): $(OBJ_M) libft.h
	@ar -rcs ${NAME} ${OBJ_M}

%.o: %.c
	@$(CC) $(FLAGS) -c $^

clean:
	@rm -rf $(OBJ_M) 

fclean: clean
	@rm -rf $(NAME)

re: fclean all
