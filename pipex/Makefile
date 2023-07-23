SRCS	= command.c\
	pipex.c\
	pipex_utils.c\
	pipex_free_utils.c\

NAME = pipex

LIBFT = ./libft/libft.a

PRINTF = ./libftprintf/libftprintf.a

HEADER = -I./pipex.h

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

.c.o:
	@${CC} -c $< -o ${<:.c=.o} -I ${LIBFT}

all: ${LIBFT} ${PRINTF} ${NAME}
	
${LIBFT}:
	@echo "\033[33mCreating libft.a ..."
	@make -C ./libft
	@echo "\033[32mCONGRATULATIONS libft has been created\n"

${PRINTF}:
	@echo "\033[33mCreating libftprintf.a ..."
	@make -C ./libftprintf
	@echo "\033[32mCONGRATULATIONS libftprintf has been created\n"	

${NAME}: ${OBJS} ${LIBFT}
	@echo "\033[33mCompiling pipex..."
	${CC} ${FLAGS} ${HEADER} ${LIBFT} ${PRINTF} ${OBJS} -o ${NAME}
	@echo "\033[32m\nCompiling pipex done \n ** Now you can use ./pipex to start the program **\033[0m"

clean:
	${RM} ${OBJS}

fclean: clean
	make fclean -C ./libft
	make fclean -C ./libftprintf
	${RM} ${NAME}

re: fclean all