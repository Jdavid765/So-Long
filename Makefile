CC = gcc
NAME = so_long
DIRGNL = gnl
DIRSRC = sources
DIRLIBFT = libft
LIBFT_LIB = $(DIRLIBFT)/libft.a
DIRMLX = mlx
MLX_LIB = $(DIRMLX)/libmlx.a
DIRPRINTF = printf
PRINTF_LIB = $(DIRPRINTF)/libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g

SRC = $(DIRSRC)/so_long.c \
	$(DIRSRC)/start_game.c\
	$(DIRSRC)/floodfil.c\
	$(DIRSRC)/initialiser.c\
	$(DIRSRC)/parsing.c\
	$(DIRSRC)/print_map.c\
	$(DIRGNL)/get_next_line.c \
	$(DIRGNL)/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)
LDFLAGS = -L$(DIRMLX) -lmlx -lXext -lX11
RM = rm -rf

# --------------------------------------------------------
#        BARRE DE PROGRESSION (ROSE) POUR COMPILATION
# --------------------------------------------------------

NB := $(words $(SRC))
BARLEN = 30

%.o: %.c
	@$(eval CNT := $(shell ls $(DIRSRC)/*.o $(DIRGNL)/*.o $(DIRLIBFT)/*.o $(DIRPRINTF)/*.o 2>/dev/null | wc -l))
	@$(eval PROG := $(shell echo $$(($(CNT) * 100 / $(NB))) ))
	@$(eval FILLED := $(shell echo $$(($(PROG) * $(BARLEN) / 100)) ))
	@$(eval EMPTY := $(shell echo $$(($(BARLEN) - $(FILLED))) ))

	@printf "\r\033[35m[%s%s] %3s%%\033[0m  \033[90m(%s)\033[0m" \
		$$(printf '#%.0s' $$(seq 1 $(FILLED))) \
		$$(printf '.%.0s' $$(seq 1 $(EMPTY))) \
		"$(PROG)" "$<"

	@$(CC) $(CFLAGS) -c $< -o $@

# --------------------------------------------------------

all: $(LIBFT_LIB) $(PRINTF_LIB) $(MLX_LIB) $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(DIRMLX) --no-print-directory > /dev/null

$(PRINTF_LIB):
	$(MAKE) -C $(DIRPRINTF)

$(LIBFT_LIB):
	$(MAKE) -C $(DIRLIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(LDFLAGS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(DIRMLX) clean --no-print-directory > /dev/null
	$(MAKE) -C $(DIRPRINTF) clean --no-print-directory > /dev/null

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIRMLX) clean --no-print-directory > /dev/null
	$(MAKE) -C $(DIRPRINTF) clean --no-print-directory > /dev/null

re: fclean all

.PHONY: all clean fclean re
