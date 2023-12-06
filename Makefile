NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD
HEADERS = -I ./include
LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC = main.c \
	errors/error_msg.c\
	init/init.c init/init_values.c init/init_images.c\
	exec/moves.c exec/draw.c exec/ray_casting.c exec/keyboard_mouse.c exec/mini_map.c exec/rotations.c exec/draw_tools.c\
	tools/ft_strnchr.c tools/get_next_line.c tools/get_next_line_utils.c tools/ft_empty_line.c tools/ft_is_char.c tools/ft_strcount.c \
	memory_manager/ft_free.c memory_manager/malloc_machine.c \
	parsing/parsing.c parsing/parsing_description.c parsing/parsing_map.c parsing/get_description.c
SRC_PATH = sources/
MY_SOURCES := $(addprefix $(SRC_PATH),$(SRC))
OBJ = $(MY_SOURCES:.c=.o)
MY_OBJECTS := $(addprefix build/, $(OBJ))
RM = rm -rf
DEPS := $(MY_OBJECTS:.o=.d)
LIBFT_PATH = libft/
LIBFT_FILE = libft.a
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_PATH = mlx_linux/
MLX_LIB = $(MLX_PATH)libmlx.a

all: $(NAME)

$(NAME): $(addprefix $(LIBFT_PATH), $(LIBFT_FILE)) $(MY_OBJECTS)
		@make -C $(MLX_PATH) all
		@$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT_LIB) $(LFLAGS) -o $(NAME)

all: $(NAME)

$(addprefix $(LIBFT_PATH), $(LIBFT_FILE)):
		@make -sC $(LIBFT_PATH)

libft: $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

clean:
		@make clean -sC $(LIBFT_PATH)
		@make -C $(MLX_PATH) clean
		rm -rf build/sources
		rm -rf build
		@$(RM) $(MY_OBJECTS)
		@$(RM) $(DEPS)

fclean: clean
		@$(RM) $(LIBFT_LIB)
		@$(RM) $(NAME)

re: fclean $(NAME)

build:
	mkdir build
	mkdir build/sources
	mkdir build/sources/tools	
	mkdir build/sources/errors
	mkdir build/sources/file_cub
	mkdir build/sources/parsing
	mkdir build/sources/memory_manager
	mkdir build/sources/exec
	mkdir build/sources/init

build/%.o: %.c | build
	@$(CC) $(CFLAGS) $(HEADERS) -I/usr/include -Imlx_linux -c $< -o $@

.PHONY : all clean fclean re libft

-include $(DEPS)
