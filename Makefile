SOURCES_MAIN	=	main.c init_so_long.c so_long_exit.c system.c
SOURCES_MAP		=	map.c init_map.c map_lines.c draw_map.c check_map.c
SOURCES_HERO	=	hero.c init_hero.c
SOURCES_MLX		=	mlx_init.c mlx_utils.c mlx_images.c mlx_clear.c mlx_pixels.c
SOURCES_FN		=	$(addprefix main/,$(SOURCES_MAIN)) \
					$(addprefix maps/,$(SOURCES_MAP)) \
					$(addprefix hero/,$(SOURCES_HERO)) \
					$(addprefix mlx/,$(SOURCES_MLX))
SOURCES			=	$(addprefix srcs/,$(SOURCES_FN))
LIBFT_PATH		=	./ft_printf/libft/
PRINTF_PATH		=	./ft_printf/
MLX_PATH		=	./mlx/
PRINTF			=	$(PRINTF_PATH)/libftprintf.a
MLX				=	$(MLX_PATH)/libmlx.a
INCLUDES		=	./includes/
HEADERS_LIBFT	=	$(addprefix $(LIBFT_PATH),libft.h)
HEADERS_PRINTF	=	$(addprefix $(PRINTF_PATH),ft_printf.h)
HEADERS_MLX		=	$(addprefix $(MLX_PATH),mlx.h)
HEADERS_SO_LONG	=	so_long.h so_long_map.h so_long_hero.h \
					so_long_mlx.h so_long_utils.h
HEADERS			=	$(addprefix $(INCLUDES),$(HEADERS_SO_LONG)) \
					$(HEADERS_LIB) $(HEADERS_PRINTF) $(HEADERS_MLX)
NAME			=	so_long
OBJECTS			=	$(SOURCES:.c=.o)
X11_PATH		=	/usr/lib/X11/
IFLAGS			=	$(addprefix -I,$(LIBFT_PATH) $(PRINTF_PATH) $(INCLUDES) $(MLX_PATH))
CFLAGS			=	-g -Wall -Wextra -Werror# -fsanitize=address
LFLAGS			=	-Lmlx -lmlx -framework OpenGL -framework AppKit
.PHONY:			all clean fclean re norm

$(NAME):	$(OBJECTS) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF) $(MLX) $(LFLAGS) -o $(NAME) $(IFLAGS)

all:		$(NAME)

$(PRINTF):
	make -C $(PRINTF_PATH)

$(MLX):
	make -C $(MLX_PATH)

%.o:		%.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $< $(IFLAGS)

clean:
	make -C $(PRINTF_PATH) clean
	make -C $(MLX_PATH) clean
	rm -f $(OBJECTS)

fclean:		clean
	make -C $(PRINTF_PATH) fclean
	rm -f $(NAME)

re:			fclean all

norm:
	norminette $(SOURCES) $(HEADERS)