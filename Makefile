SOURCES			=	map.c main.c hero.c system.c mlx_init.c so_long_exit.c mlx_utils.c
LIBFT_PATH		=	./ft_printf/libft/
PRINTF_PATH		=	./ft_printf/
PRINTF			=	$(PRINTF_PATH)/libftprintf.a
HEADERS_LIBFT	=	$(addprefix $(LIBFT_PATH),libft.h)
HEADERS_PRINTF	=	$(addprefix $(PRINTF_PATH),ft_printf.h)
HEADERS			=	so_long.h so_long_mlx.h so_long_utils.h \
					$(HEADERS_LIB) $(HEADERS_PRINTF)
NAME			=	so_long
OBJECTS			=	$(SOURCES:.c=.o)
CFLAGS			=	-g -Wall -Wextra -Werror -fsanitize=address
LFLAGS			=	-lmlx -lX11 -lXext
.PHONY:			all clean fclean re norm

$(NAME):	$(OBJECTS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF) $(LFLAGS) -o $(NAME)

all:		$(NAME)

$(PRINTF):
	make -C $(PRINTF_PATH)

%.o:		%.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(LIBFT_PATH) -I$(PRINTF_PATH)

clean:
	make -C $(PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean:		clean
	make -C $(PRINTF_PATH) fclean
	rm -f $(NAME)

re:			fclean all

norm:
	norminette $(SOURCES) $(HEADERS)