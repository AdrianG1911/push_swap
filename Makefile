# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 17:14:22 by adrgutie          #+#    #+#              #
#    Updated: 2024/08/31 17:20:57 by adrgutie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
BONUS_NAME = checker
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f
SRCS 	= src/push_swap.c src/swap.c src/push.c \
src/rotate.c src/reverse_rotate.c src/sortbinradix.c \
src/sort1to5.c src/sortrotate.c src/sortrotate_utils.c \
src/sortrotate_moves.c src/sortanderror.c \
src/stackmaker.c 

BONUS_SRCS	= src/checker.c src/get_next_line.c \
src/get_next_line_utils.c src/swap.c src/push.c \
src/rotate.c src/reverse_rotate.c \
src/stackmaker.c src/sortanderror.c


OBJS 	= $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) -Llibft -lft -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	make -C libft
	$(CC) $(BONUS_OBJS) -Llibft -lft -o $(BONUS_NAME)

all: $(NAME)
bonus: $(NAME) $(BONUS_NAME)
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make fclean -C libft
fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
re: fclean all

.PHONY : all clean fclean re bonus
