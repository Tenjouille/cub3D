NAME = libftprintf.a

SRC = ft_printf.c ft_putadress.c ft_putchar.c ft_puthexa.c ft_putnbr.c \
		ft_putstr.c ft_strchr.c

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