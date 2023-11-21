NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror

AR = ar -rcs

RM = rm -f

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)