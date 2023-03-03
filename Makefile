CC= gcc
FLAGS= -Wall -Werror -Wextra
NAME= libftprintf.a
SRCS= ft_strlen.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_intlength.c \
	ft_putnbr.c \
	ft_unsigned_intlength.c \
	ft_put_unsigned_int.c \
	ft_hexlength.c \
	ft_puthex_low.c \
	ft_puthex_upper.c \
	ft_putptr.c \
	ft_printf.c \

OBJS= ${SRCS:%.c=%.o}

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< 

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re