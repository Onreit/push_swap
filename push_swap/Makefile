# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 15:00:02 by tjalo             #+#    #+#              #
#    Updated: 2022/04/25 09:44:10 by tjalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc 

CFLAGS = -g3 -Wall -Wextra -Werror -I ./include

HEADER = -I ./include

LIBFTSRC =	lib/ft_split.c \
		lib/ft_atoi.c \
		lib/ft_strlen.c \
		lib/ft_isdigit.c \
		lib/ft_create_elem.c \
		lib/ft_bzero.c \
		lib/ft_lstsize.c

SRC =	srcs/swap.c \
		srcs/utils.c \
		srcs/utils_bis.c \
		srcs/medium_sort.c \
		srcs/little_sort.c \
		srcs/quick_sort.c \
		srcs/parse.c \
		srcs/big_sort.c \
		srcs/main.c \
		${LIBFTSRC}

OBJ = ${SRC:.c=.o}

all:	${NAME}

$(NAME):	${OBJ}
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o%.c:
	${CC} -c ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJ}
	
fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re