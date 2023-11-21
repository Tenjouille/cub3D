NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_strlcat.c ft_striteri.c ft_strmapi.c ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
			ft_lstnew.c ft_lstsize.c

SRC_PATH = ./sources/

PRINTF_PATH = ft_printf/

PRINTF_FILE	= libftprintf.a

PRINTF_LIB	= $(addprefix $(PRINTF_PATH), $(PRINTF_FILE))

GNL_PATH = get_next_line/

GNL_FILE = get_next_line.a

GNL_LIB	= $(addprefix $(GNL_PATH), $(GNL_FILE))

MY_SOURCES = $(addprefix $(SRC_PATH),$(SRC))

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror \

RM = rm -f

CC = cc

all: printf gnl $(NAME)

$(NAME): $(MY_OBJECTS)
		ar -rcs $(NAME) $(MY_OBJECTS)

printf: 
		@make -sC $(PRINTF_PATH) all 

gnl:
		@make -sC $(GNL_PATH) all

clean:
		@make -C $(PRINTF_PATH) clean
		@make -C $(GNL_PATH) clean
		$(RM) $(MY_OBJECTS)

fclean: clean
		$(RM) $(PRINTF_PATH)libftprintf.a
		$(RM) $(GNL_PATH)get_next_line.a
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY : all clean fclean re