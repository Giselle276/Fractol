NAME = fractol
SRC = fractol.c \
      math_utils.c \
	  render.c\
	  init.c\
	  events.c\
	  ft_strncmp.c\
	  ft_atodbl.c\

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
INCLUDES = fractol.h
all: $(NAME)
	@echo "OK"
$(NAME) : $(OBJ)
	@cd $(MLX_DIR) && $(MAKE) > /dev/null 2>/dev/null
	@$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Compilation Completed"
%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean fclean all re
