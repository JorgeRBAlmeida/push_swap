NAME		= push_swap

SRCS		= push_swap.c

OBJS		= ${SRCS:.c=.o}

LIBFT		= libft.a

LIBFT_PATH	= ./libft

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

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