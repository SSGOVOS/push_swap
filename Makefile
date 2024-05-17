NAME = push_swap
NAME2 = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
SOURCE = check.c check2.c ft_split.c lst.c moves.c parsing.c push_swap.c utils_for_split.c sort.c \
			sort3_4_5.c get_next_line_utils.c
SOURCEB = check.c check2.c ft_split.c lst.c moves_bonus.c parsing.c checker_bonus.c utils_for_split.c sort.c \
			get_next_line.c get_next_line_utils.c utils_0.c
OBJ = ${SOURCE:.c=.o}
BOBJ = ${SOURCEB:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

bonus: ${NAME2} 

${NAME2}: ${BOBJ}
		${CC} ${CFLAGS} ${BOBJ} -o ${NAME2}

clean:
	rm -rf ${OBJ} ${BOBJ}

fclean: clean
	rm -rf ${NAME} ${NAME2}

re: fclean all