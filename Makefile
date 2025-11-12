CC = gcc
NAME = solong
DIRGNL = gnl
DIRSRC = sources
DIRLIBFT = libft

SRC = $(DIRSRC)/so_long.c \
	$(DIRGNL)/get_next_line.c \
	$(DIRGNL)/get_next_line_utils.c \
	$(DIRLIBFT)/ft_tolower.c \
	$(DIRLIBFT)/ft_toupper.c \
	$(DIRLIBFT)/ft_isprint.c \
	$(DIRLIBFT)/ft_isascii.c \
	$(DIRLIBFT)/ft_isalnum.c \
	$(DIRLIBFT)/ft_isdigit.c \
	$(DIRLIBFT)/ft_isalpha.c \
	$(DIRLIBFT)/ft_atoi.c \
	$(DIRLIBFT)/ft_strlen.c \
	$(DIRLIBFT)/ft_strlcat.c \
	$(DIRLIBFT)/ft_strncmp.c \
	$(DIRLIBFT)/ft_strdup.c \
	$(DIRLIBFT)/ft_calloc.c \
	$(DIRLIBFT)/ft_memcpy.c \
	$(DIRLIBFT)/ft_strchr.c \
	$(DIRLIBFT)/ft_strrchr.c \
	$(DIRLIBFT)/ft_strnstr.c \
	$(DIRLIBFT)/ft_bzero.c \
	$(DIRLIBFT)/ft_memchr.c \
	$(DIRLIBFT)/ft_memcmp.c \
	$(DIRLIBFT)/ft_memset.c \
	$(DIRLIBFT)/ft_memmove.c \
	$(DIRLIBFT)/ft_strlcpy.c \
	$(DIRLIBFT)/ft_itoa.c \
	$(DIRLIBFT)/ft_strjoin.c \
	$(DIRLIBFT)/ft_split.c \
	$(DIRLIBFT)/ft_striteri.c \
	$(DIRLIBFT)/ft_strmapi.c \
	$(DIRLIBFT)/ft_substr.c \
	$(DIRLIBFT)/ft_strtrim.c \
	$(DIRLIBFT)/ft_putchar_fd.c \
	$(DIRLIBFT)/ft_putstr_fd.c \
	$(DIRLIBFT)/ft_putendl_fd.c \
	$(DIRLIBFT)/ft_putnbr_fd.c \
	$(DIRLIBFT)/ft_lstnew_bonus.c \
	$(DIRLIBFT)/ft_lstadd_front_bonus.c \
	$(DIRLIBFT)/ft_lstadd_back_bonus.c \
	$(DIRLIBFT)/ft_lstdelone_bonus.c \
	$(DIRLIBFT)/ft_lstclear_bonus.c \
	$(DIRLIBFT)/ft_lstiter_bonus.c \
	$(DIRLIBFT)/ft_lstsize_bonus.c \
	$(DIRLIBFT)/ft_lstlast_bonus.c \
	$(DIRLIBFT)/ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
