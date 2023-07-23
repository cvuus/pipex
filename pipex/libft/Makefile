SRCS	= ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_atoi.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memcmp.c\
	ft_memset.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_bzero.c\
	ft_memchr.c\
	ft_split.c\
	ft_strjoin.c\
	ft_itoa.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_striteri.c\
	ft_strmapi.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_strchrint.c\
	
BONUSSRCS = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstiter.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstmap.c\
	

NAME	= libft.a

NAME2	= test

OBJS = ${SRCS:.c=.o}

BONUSOBJS = ${BONUSSRCS:.c=.o}

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

ifdef ADD_BONUS
ALLFILES =${OBJS} ${BONUSOBJS}
else 
ALLFILES = ${OBJS}
endif

.c.o: 
	@${CC} -c ${FLAGS} $< -o ${<:.c=.o} 

${NAME}:	${ALLFILES}
	@ar rcs ${NAME} ${ALLFILES}

all: ${NAME}

bonus:
	${MAKE} ADD_BONUS=1

clean:
	${RM} ${OBJS} ${BONUSOBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all