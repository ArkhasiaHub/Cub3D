NAME = cub3D

CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -MP -g

LIBFT = ./libft/libft.a

SRCS = ./srcs/cub3d_mlx.c \
./srcs/error.c \
./srcs/free.c \
./srcs/get_next_line_utils.c \
./srcs/get_next_line.c \
./srcs/main.c \
./srcs/map_to_int.c \
./srcs/pars_color.c \
./srcs/pars_line.c \
./srcs/pars_textures.c \
./srcs/parsing.c \
./srcs/protect.c \
./srcs/utilities.c \
./srcs/verif_map.c \
./srcs/draw_rays.c \
./srcs/move_player.c \
./srcs/setup_ray.c \
./srcs/draw_pixel.c \
./srcs/move_rotate_view.c \
./srcs/move_coord.c \
./srcs/pars_floor.c \
./srcs/check_begin_map.c \
./srcs/pars_ceilling.c

DIR_MLX = minilibx-linux/

MLX_FLAGS = -lXext -lX11 -lm

MAKE_MLX = $(MAKE) -C $(DIR_MLX)

all:
	$(MAKE_MLX)
	$(MAKE) ${NAME}

OBJ = ${SRCS:.c=.o}

OBJ_D = ${OBJ:.o=.d}

%.o : %.c
		$(CC) $(FLAGS) -I $(DIR_MLX) -c $< -o $@

-include ${OBJ_D}

${NAME} : ${OBJ} ${LIBFT}
		${CC} ${FLAGS} ${OBJ} -o ${NAME} ${LIBFT} -I $(DIR_MLX) -L $(DIR_MLX) -lmlx ${MLX_FLAGS}

clean:
		$(MAKE_MLX) clean
		make clean -C ./libft
		rm -f ${OBJ} ${OBJ_D}

fclean: clean
		make fclean -C ./libft
		rm -f ${NAME}

re: fclean all

${LIBFT} : FORCE
		make -C ./libft

FORCE:


mlx : FORCE
	make -C $(DIR_MLX)

.PHONY: clean fclean re all FORCE mlx