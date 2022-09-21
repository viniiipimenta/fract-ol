NAME = fractol


SRCS = fractol.c draw_fractal.c mandelbrot.c julia.c atod.c error.c handle.c move.c


OBJS = ${SRCS:.c=.o}


CC		= cc


RM		= rm -f


CFLAGS = -Wall -Wextra -Werror


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ./minilib


$(NAME): ${OBJS}
		make -C ./minilib
		$(CC) $(OBJS) -L ./minilib -lmlx -framework OpenGL -framework AppKit -o $(NAME)


all:	${NAME}


clean:
		${RM} ${OBJS}
		make clean -C ./minilib


fclean:	clean
		${RM} ${NAME}


re:		fclean all



.PHONY: all clean fclean re
