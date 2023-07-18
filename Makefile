# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhristi <ikhristi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 20:56:14 by ikhristi          #+#    #+#              #
#    Updated: 2023/06/27 15:58:37 by ikhristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c				\
	map_check.c				\
	map_parse_utils.c		\
	map_path.c				\
	map_read.c				\
	map_utils.c				\
	render.c				\
	pictures_parsing.c		\
	game_exit.c				\
	input_handling.c

NAME = so_long

LIBFT = inc/libft/
PRINTF = inc/printf/
MLX = mlx/

SRCS_DIR = src/
OBJS_DIR = obj/

OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c inc/so_long.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@make -C $(MLX)
	@$(CC) -O3 -L$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) inc/libft/libft.a inc/printf/libftprintf.a $(MLX)libmlx.a

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C $(LIBFT)
	@make clean -C $(PRINTF)
	@make clean -C $(MLX)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)

re: fclean all