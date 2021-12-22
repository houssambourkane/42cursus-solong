# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 10:52:04 by hbourkan          #+#    #+#              #
#    Updated: 2021/12/21 15:13:20 by hbourkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mandatory/so_long

NAME_BONUS = bonus/so_long

FRAME = -lmlx -framework OpenGl -framework AppKit

FLAGS = -Wall -Werror -Wextra -g

CFILES = mandatory/so_long.c mandatory/utils.c mandatory/check.c mandatory/draw_map.c \
			mandatory/get_next_line.c mandatory/get_next_line2.c mandatory/get_next_line_utils.c \
			mandatory/linechecks.c mandatory/window_draw.c mandatory/key_press.c mandatory/player.c \

BFILES = bonus/so_long_bonus.c bonus/utils_bonus.c bonus/check_bonus.c bonus/draw_map_bonus.c \
			bonus/get_next_line_bonus.c bonus/get_next_line2_bonus.c \
			bonus/get_next_line_utils_bonus.c bonus/linechecks_bonus.c \
			bonus/window_draw_bonus.c bonus/key_press_bonus.c bonus/player_bonus.c \
			bonus/ft_itoa_bonus.c bonus/sprite_bonus.c bonus/result_bonus.c \

all: $(NAME)

$(NAME): $(CFILES)
	cc $(FLAGS) $(CFILES) $(FRAME) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BFILES)
	cc $(FLAGS) $(BFILES) $(FRAME) -o $(NAME_BONUS)

clean:
	
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all