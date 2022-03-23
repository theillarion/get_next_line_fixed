NAME			=	get_next_line
NAME_D			=	${NAME}_debug
CC 				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra
CC_FLAGS_D		=	-g -DBUFFER_SIZE=5
HEADER			=	includes/get_next_line.h
SRCS			=	${wildcard srcs/*.c}
OBJS			=	${SRCS:%.c=%.o}
OBJS_D			=	${SRCS:%.c=%_debug.o}
INCLUDES		=	-Iincludes
RM				=	rm -rf

%.o				:	%.c
					$(CC) ${CC_FLAGS} ${INCLUDES} -c $< -o $@

%_debug.o		:	%.c
					$(CC) ${CC_FLAGS_D} ${CC_FLAGS} ${INCLUDES} -c $< -o $@

all				:	${NAME}

${NAME}			:	${LIB} $(OBJS)
					$(CC) $(INCLUDES) $(OBJS) -o $(NAME)

debug			:	${NAME_D}

${NAME_D}		:	${LIB_D} $(OBJS_D)
					$(CC) $(INCLUDES) $(OBJS_D) -o ${NAME_D}

clean			:
					$(RM) ${OBJS} $(OBJS_D)

fclean			:	clean 
					$(RM) $(NAME) ${NAME_D}

re				:	fclean all

.PHONY			:	all debug clean fclean re