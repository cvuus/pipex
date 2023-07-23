SRCS	= src/ft_csconversion.c\
	src/ft_idconversion.c\
	src/ft_pconversion.c\
	src/ft_xxconversion.c\
	src/ft_converter.c\
	src/ft_uiconversion.c\
	ft_printf.c\
	ft_printf_utils.c\

NAME	= libftprintf.a
LIBFT	= ../libft/libft.a

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

.c.o: 
	@${CC} -c ${FLAGS} $< -o ${<:.c=.o} -I ${LIBFT}

all: ${LIBFT} ${NAME}

${NAME}: ${OBJS}
	@cp ${LIBFT} ${NAME}
	@ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

# bonus:
# 	${MAKE} ADD_BONUS=1
# BONUSSRCS = LIST ALL BONUSSRC FILES

# BONUSOBJS = ${BONUSSRCS:.c=.o}

# ifdef ADD_BONUS
# ALLFILES =${OBJS} ${BONUSOBJS}
# else 
# ALLFILES = ${OBJS}
# endif