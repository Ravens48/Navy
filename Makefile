##
## EPITECH PROJECT, 2020
## PSU_navy_2019
## File description:
## Makefile
##

NAME	= navy

CC	= gcc

RM	= rm -f

SRCS	= ./help.c \
	  ./lib/my/my_putchar.c \
	  ./lib/my/my_putstr.c \
	  ./lib/my/my_put_nbr.c \
	  ./lib/my/my_putstr_error.c \
	  ./lib/my/my_strlen.c \
	  ./lib/my/get_next_line.c \
	  ./lib/my/my_strcmp.c \
	  ./lib/my/my_str_tab.c \
	  ./lib/my/my_memset.c \
	  ./NAVY_makemap.c \
	  ./NAVY_open_pose.c \
	  ./NAVY_map_error.c \
	  ./NAVY_boat.c \
	  ./main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
