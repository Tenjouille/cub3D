NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -MMD
HEADERS = -I ./include
LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC = main.c \
	tools/ft_strnchr.c
SRC_PATH = sources/
MY_SOURCES := $(addprefix $(SRC_PATH),$(SRC))
OBJ = $(MY_SOURCES:.c=.o)
MY_OBJECTS := $(addprefix build/, $(OBJ))
RM = rm -rf
DEPS := $(MY_OBJECTS:.o=.d)
LIBFT_PATH = libft/
LIBFT_FILE = libft.a
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
FTPRINTF_PATH = libft/ft_printf/
FTPRINTF_FILE = libftprintf.a
FTPRINTF_LIB = $(addprefix $(FTPRINTF_PATH), $(FTPRINTF_FILE))
GNL_PATH = libft/get_next_line/
GNL_FILE = get_next_line.a
GNL_LIB	= $(addprefix $(GNL_PATH), $(GNL_FILE))
MLX_PATH = mlx_linux/
MLX_LIB = $(MLX_PATH)libmlx.a

$(NAME): $(addprefix $(LIBFT_PATH), $(LIBFT_FILE)) $(MY_OBJECTS)
		@make -C $(MLX_PATH) all
		@$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT_LIB) $(FTPRINTF_LIB) $(GNL_LIB) $(LFLAGS)  -o $(NAME)

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
		@$(RM) $(FTPRINTF_LIB)
		@$(RM) $(GNL_LIB)
		@$(RM) $(NAME)

re: fclean $(NAME)

build:
	mkdir build
	mkdir build/sources
	mkdir build/sources/tools

build/%.o: %.c | build
	@$(CC) $(CFLAGS) $(HEADERS) -I/usr/include -Imlx_linux -c $< -o $@

.PHONY : all clean fclean re libft

-include $(DEPS)
