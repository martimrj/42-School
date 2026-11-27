NAME 		= libftprintf.a
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -I.
AR 			= ar rcs
RM 			= rm -f
LIBFT_DIR 	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS 		= ft_printf.c \
		      ft_printf_char.c \
		  	  ft_printf_str.c \
		  	  ft_printf_base.c \
		  	  ft_printf_nbr.c \
		  	  ft_printf_ptr.c \
		  	  ft_printf_unsigned.c

OBJS 		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
