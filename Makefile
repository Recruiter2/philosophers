NAME	= philo
CC		= cc
CFLAGS	= -Werror -Wextra -Wall -fsanitize=address -g -fno-omit-frame-pointer -lpthread #-pthread -fsanitize=thread -g

#-fsanitize=address -g -fno-omit-frame-pointer -lpthread
SRCS	= main.c parsing.c utils.c atoi.c init.c monitor.c philo_routine.c philo_helper.c
OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re