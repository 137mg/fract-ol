# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mgoedkoo <mgoedkoo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/09 17:38:57 by mgoedkoo      #+#    #+#                  #
#    Updated: 2023/06/04 16:47:38 by mgoedkoo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		fractol
SRCS =		cpx.c\
			draw.c\
			hooks.c\
			init.c\
			main.c
OBJS =		$(SRCS:%.c=build/%.o)
LIBFT =		libft/
MLX =		mlx/
CFLAGS +=	-Wall -Wextra -Werror

all: $(NAME)

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)
	rm -df build
	@echo "$(NAME) cleaned up nicely"

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)
	@echo "$(NAME) fcleaned up nicely"

re: fclean all

$(NAME): $(OBJS)
	@echo "the $(NAME) o-files are ready"
	@make all -C $(LIBFT)
	@make all -C $(MLX)
	cc $(C-FlAGS) -o $(NAME) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -L libft/ -lft
	@echo "$(NAME) is ready"

$(OBJS): build/%.o : %.c
	@mkdir -p build
	cc $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re