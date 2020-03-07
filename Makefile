##
## EPITECH PROJECT, 2020
## PSU_navy_2019
## File description:
## Makefile
##

NAME	= navy

CC	= gcc

RM	= rm -f

SRCS	= ./navy_help.c \
	  ./lib/my/my_putchar.c \
	  ./lib/my/my_putstr.c \
	  ./lib/my/my_put_nbr.c \
	  ./lib/my/my_putstr_error.c \
	  ./lib/my/my_strlen.c \
	  ./lib/my/get_next_line.c \
	  ./lib/my/my_strcmp.c \
	  ./lib/my/my_str_tab.c \
	  ./lib/my/my_memset.c \
	  ./lib/my/my_getnbr.c \
	  ./navy_makemap.c \
	  ./navy_open_pose.c \
	  ./navy_map_error.c \
	  ./navy_boat.c \
	  ./navy_connection.c \
	  ./navy_game_loop.c \
	  ./navy_player1.c \
	  ./navy_player2.c \
	  ./navy_hit_or_miss.c \
	  ./lib/my/my_binary_to_decimal.c \
	  ./lib/my/my_decimal_to_binary.c \
	  ./defense2.c \
	  ./navy_main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
