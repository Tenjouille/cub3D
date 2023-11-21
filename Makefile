# NAME = minishell
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g3
# LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# HEAD = includes/
# HEADER = includes/cub.h
# SRCS = main.c
# OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
# OBJ_DIR = obj

# all: $(NAME)

# $(NAME): $(OBJS) $(HEADER)
# 	$(CC) $(CFLAGS) -I $(HEAD) $(OBJS) $(LFLAGS) -o $(NAME)

# $(OBJ_DIR)/%.o: %.c
# 	mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) -I $(HEAD) -I/usr/include -Imlx_linux -c $< -o $@


# clean: 
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	rm $(NAME)

# re: clean all

# .PHONY: all clean fclean re

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
HEADERS = -I ./include
# MLX_DIR=./mlx_linux
LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC = main.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	tools/ft_putstr_fd.c \
	tools/ft_strcmp.c
OBJ = $(SRC:.c=.o)
RM = rm -rf

all: ${NAME}
 
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)
	
debug: clean
	$(CC) $(SRC) $(LIBS) $(HEADERS) $(LFLAGS)  -g3 -O3 -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -I/usr/include -Imlx_linux -c $< -o $@

clean:
	$(RM) ${OBJ}

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: debug clean fclean re

# NAME = cub3D
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g3
# INCLUDES = -I./includes
# MLX_INCLUDE =
# MLX_DIR=./mlx_linux
# MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# #source
# SRCS_DIR = sources/
# SRCS = main.c

# SRCS_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))

# #objsm
# OBJS = $(SRCS_PREFIXED:.c=.o)

# all : $(NAME)

# %.o: %.c ./includes/cub3d.h
# 	@$(CC) $(CFLAGS) -I $(MLX_DIR) -c $< -o $@

# $(NAME): $(OBJS)
# 	@$(MAKE) -C $(MLX_DIR)
# 	@$(CC) $(CFLAGS) $(OBJS) -lm $(MLX_FLAGS) -o $(NAME)
# 	@echo $(NAME) is built

# clean :
# 	@$(MAKE) clean -C $(MLX_DIR)
# 	@rm -rf $(OBJS)
# 	@echo cleaning

# fclean : clean
# 	@rm -rf $(NAME)
# 	@rm -rf libmlx.dylib
# 	@echo "full clean"

# re : fclean all

# .PHONY	: all clean fclean re help