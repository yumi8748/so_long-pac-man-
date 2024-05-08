# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 15:44:10 by yu-chen           #+#    #+#              #
#    Updated: 2024/05/03 16:03:52 by yu-chen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/bash

LEAKS =  valgrind --leak-check=full --show-leak-kinds=all

GAME = game_linux.c
RENDER = render_linux.c
GAME_RATE = 130

ESC = KEY_ESC=65307
W = KEY_W=119
A = KEY_A=97
S = KEY_S=115
D = KEY_D=100
UP = KEY_UP=65362
DOWN = KEY_DOWN=65364
LEFT = KEY_LEFT=65361
RIGHT = KEY_RIGHT=65363
R = KEY_R=114
Q = KEY_Q=113

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lX11 -lXext
RM = rm -f
AR = ar rcs
SRC_DIR = src
OBJ_DIR = obj
PRINTF = printf
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
LIBFT_SRC = $(shell find libft -type f -name '*.c')
MLX = ./minilibx-linux/libmlx.a

KEYCODES =  -D $(ESC) -D $(Q) -D $(R) -D $(W) -D $(A) -D $(S) -D $(D) -D $(UP) -D \
				$(DOWN) -D $(LEFT) -D $(RIGHT) -D GAME_RATE=$(GAME_RATE)

SRC = animation.c chase.c game_linux.c legal.c main.c pacman.c \
		playerlist.c score.c anim_dir.c check.c ghosts.c \
		load_dir.c map.c player.c render_linux.c spirits.c utils.c utils2.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(LIBFT):
	@make all -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(KEYCODES) -c $< -o $@
	@echo $(CC) $(CFLAGS) $(KEYCODES) -c $< -o $@
	
$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

bonus: all

test: all
	@$(PRINTF) "Command:./$(NAME) $(MAP)\n\n"
	@$(LEAKS) ./$(NAME) $(MAP)

clean:
	@make clean -C libft
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(LIBFT) $(NAME)

re: fclean
	@make all

.PHONY: all bonus clean fclean play re