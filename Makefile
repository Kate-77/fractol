# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 18:21:07 by kmoutaou          #+#    #+#              #
#    Updated: 2022/04/02 03:12:50 by kmoutaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

CC			= cc

FLAGS		= -Wall -Wextra -Werror -lmlx -framework OpenGL -framework appKit

SRCS		= sets/mandelbrot.c sets/julia.c tools/shutdown.c \
			  tools/coloring.c tools/drawing.c tools/ft_putstr.c main.c \
			  tools/move.c tools/initialize.c tools/zooming.c tools/strcmp.c

OBJS		= $(SRCS:.c=.o)

HEADERS		= .

all: 		$(NAME)

$(NAME):	$(OBJS) 
			ar rcs $(NAME) $(OBJS)

%.o: %.c
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I $(HEADERS)
			ar rcs $(NAME) ${<:.c=.o}

bonus: 		$(BOBJS)

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	all re clean fclean 