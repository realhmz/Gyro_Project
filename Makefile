NAME = gyro
MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -lreadline
CFLAGS = -Wall 
SRC =	main.c\
		parce.c\
		libft_utils.c\
		render.c\
		get_next_line.c\
		read_map.c\
		atoi_base.c\
		utils.c\
		draw.c\

		

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(MLX)

re : fclean all
fclean : clean
	rm -rf $(NAME)
clean :
	rm -rf $(OBJ)
debug :
	cc *.c -fsanitize=address -g3 -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -lreadline -o gyro