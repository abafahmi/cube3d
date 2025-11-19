CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

AR = ar crs

RM = rm -f

SRCS = ft_atoi.c ft_isdigit.c ft_memset.c ft_strlcpy.c ft_substr.c \
        ft_bzero.c ft_isprint.c ft_split.c ft_strlen.c ft_tolower.c \
        ft_calloc.c ft_memchr.c ft_strchr.c ft_strncmp.c ft_toupper.c \
        ft_isalnum.c ft_memcmp.c ft_strdup.c ft_strnstr.c ft_itoa.c \
        ft_isalpha.c ft_memcpy.c ft_strjoin.c ft_strrchr.c ft_strmapi.c \
        ft_isascii.c ft_memmove.c ft_strlcat.c ft_strtrim.c ft_putstr_fd.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c

SRCSB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c	

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

all: $(NAME)

.o: .c
	$(CC) $(CFLAGS) -c $@ -o $<

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJSB)
	$(AR) $(NAME) $(OBJSB)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
