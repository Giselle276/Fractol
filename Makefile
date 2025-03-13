NAME = fractol
SRC = fractol.c \
      math_utils.c \
	  render.c\
	  init.c\
	  events.c\
	  utils.c\
	  tricorn.c\

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
INCLUDES = fractol.h

$(NAME) : $(OBJ)
	@cd $(MLX_DIR) && $(MAKE) > /dev/null 2>/dev/null
	@$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Compilation Completed"
all: $(NAME)
%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)
clean:
	rm -f $(OBJ) $(BON_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all bonus
.PHONY: clean fclean all re bonus
