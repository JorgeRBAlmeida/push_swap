NAME		= push_swap

SRCS		= push_swap.c list.c utils.c utils2.c swaps.c \
				pushes.c rotations.c reverse_rotations.c \
				args.c sorts.c small_sorts.c sort_to_a.c \
				sort_to_b.c

OBJS		= ${SRCS:.c=.o}

LIBFT		= libft.a

LIBFT_PATH	= ./libft

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):	$(LIBFT)
			${CC} ${OBJS} ${LIBFT} -o ${NAME}

$(LIBFT):	$(OBJS)
			make -C $(LIBFT_PATH)
			cp $(LIBFT_PATH)/$(LIBFT) .

clean:
		$(RM) $(OBJS)
		$(RM) $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re