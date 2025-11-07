CC = gcc
NAME = **
SRC = **
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)
fclean :
	$(MAKE) clean
	$(RM) $(NAME)
re :
	$(MAKE) fclean
	$(MAKE) $(all)

.PHONY: all clean fclean re bonus