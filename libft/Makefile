SRCS	= ft_strchr.c ft_bzero.c ft_strnstr.c \
		ft_isprint.c ft_atoi.c ft_toupper.c ft_tolower.c \
		ft_strlcpy.c ft_memset.c ft_calloc.c ft_strlen.c \
		ft_isascii.c ft_strlcat.c ft_memcmp.c ft_isdigit.c \
		ft_strrchr.c ft_isalpha.c ft_strncmp.c ft_isalnum.c \
		ft_memcpy.c ft_memmove.c ft_strdup.c ft_memchr.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCB	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJB	= ${SRCB:.c=.o}

NAME	= libft.a

RM		= rm -f

CC		= cc

AR		= ar rcs

ARB		= ar qs

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${OBJB}
			${AR} ${NAME} ${OBJS} ${OBJB}

all:		$(NAME)

clean:
			${RM} ${OBJS} ${OBJB}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJB}
			${ARB} ${NAME} ${OBJB}


.PHONY:		all clean fclean re bonus