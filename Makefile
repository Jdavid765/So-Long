CC = gcc
NAME = so_long
DIRGNL = gnl
DIRSRC = sources
DIRLIBFT = libft
DIRMLX = mlx
MLX_LIB = $(DIRMLX)/libmlx.a

SRC = $(DIRSRC)/so_long.c \
	$(DIRSRC)/floodfil.c\
	$(DIRSRC)/initialiser.c\
	$(DIRSRC)/parsing.c\
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
	$(DIRLIBFT)/ft_lstmap_bonus.c\

OBJ = $(SRC:.c=.o)
LDFLAGS = -L$(DIRMLX) -lmlx -lXext -lX11
RM = rm -rf

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(DIRMLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(DIRMLX) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIRMLX) clean

re: fclean all

.PHONY: all clean fclean re