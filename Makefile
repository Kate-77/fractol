# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 18:21:07 by kmoutaou          #+#    #+#              #
#    Updated: 2022/04/03 22:48:53 by kmoutaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

BNAME		= fractol_bonus

CC			= cc

FLAGS		= -Wall -Wextra -Werror 

SRCS		= mandatory/sets/mandelbrot.c mandatory/sets/julia.c \
			mandatory/tools/shutdown.c mandatory/tools/coloring.c \
			mandatory/tools/drawing.c mandatory/tools/ft_putstr.c \
			mandatory/main.c mandatory/tools/move.c mandatory/tools/initialize.c \
			mandatory/tools/zooming.c mandatory/tools/ft_strcmp.c

BSRCS		= bonus/sets/mandelbrot_bonus.c bonus/sets/julia_bonus.c \
			bonus/sets/burningship.c bonus/tools/shutdown_bonus.c \
			bonus/tools/coloring_bonus.c bonus/tools/drawing_bonus.c \
			bonus/tools/ft_putstr_bonus.c bonus/main_bonus.c \
			bonus/tools/move_bonus.c bonus/tools/initialize_bonus.c \
			bonus/tools/zooming_bonus.c bonus/tools/ft_strcmp_bonus.c
			  
MLX			= -lmlx -framework OpenGL -framework appKit

HEADERS		= fractol/includes/fractol.h bonus/includes/fractol_bonus.h

all: 		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(FLAGS) $(SRCS) $(MLX) -o $(NAME)

bonus:		$(BNAME)

$(BNAME):	$(BSRCS)
			$(CC) $(FLAGS) $(BSRCS) $(MLX) -o $(BNAME)

clean:
			rm -f $(NAME) $(BNAME)

fclean: 	clean
			rm -f $(NAME) $(BNAME)

re: 		fclean all

.PHONY: 	all re clean fclean
