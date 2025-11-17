CC = gcc
NAME = libft.a
SRC = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c \
	ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_atoi.c \
	ft_strlen.c ft_strlcat.c ft_strncmp.c ft_strdup.c \
	ft_calloc.c ft_memcpy.c ft_strchr.c ft_strrchr.c \
	ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c \
	ft_memset.c ft_memmove.c ft_strlcpy.c ft_itoa.c \
	ft_strjoin.c ft_split.c ft_striteri.c ft_strmapi.c \
	ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c ft_lstclear_bonus.c\
	ft_lstiter_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
fclean :
	$(MAKE) clean
	$(RM) $(NAME)
re :
	$(MAKE) fclean
	$(MAKE) $(all)
bonus:	$(OBJ) $(OBJ_BONUS)
		ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)
	
.PHONY: all clean fclean re bonus
