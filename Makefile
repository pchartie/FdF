NAME = fdf

SRC = ./fdf.c \
	./matrices.c \
	./list.c \
	./parse_and_copy.c \
	./color.c \
	./draw_lines.c \
	./error.c \
	./key_function.c \
	./key_function2.c \

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

INC = -I./libft/

CC = gcc -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/ -j 8
	make -C minilibx_macos/ -j 8
	$(CC) -o $(NAME) $(OBJS) $(LIB)

%.o: %.c
	$(CC) -Wall -Wextra -c $< $(INC)

clean:
	$(RM) $(OBJS)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all
