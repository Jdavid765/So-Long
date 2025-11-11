CC = gcc
NAME = so_long
DIR = gnl

SRC = so_long.c\
$(DIR)/get_next_line.c\
$(DIR)/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)
fclean :
	$(MAKE) clean
	$(RM) $(NAME)
re :
	$(MAKE) fclean
	$(MAKE) $(all)