NAME = push_swap
#Name2 = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
SOURCE = check.c check2.c ft_split.c lst.c moves.c parsing.c push_swap.c utils_for_split.c sort.c \
			sort3_4_5.c
#SOURCEB = 
OBJ = ${SOURCE:.c=.o}
#BOBJ = ${SOURCEB:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
		${CC} ${CFLAGS} ${OBJ} -o ${NAME}

#bonus: ${Name2} 


clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all 