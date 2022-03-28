# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoutaou <kmoutaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 18:21:07 by kmoutaou          #+#    #+#              #
#    Updated: 2022/03/28 18:52:04 by kmoutaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRCS		= sets/mandelbrot.c sets/burningship.c tools/shutdown.c \
			  tools/coloring.c main.c

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