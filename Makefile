NAME			=	get_next_line
NAME_B			=	$(NAME)_bonus
NAME_D			=	${NAME}_debug
HEADER			=	${addprefix includes/,get_next_line.h}
HEADER_B		=	${addprefix includes/,get_next_line_bonus.h}
CC 				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra -DBUFFER_SIZE=42
CC_FLAGS_D		=	-g
SRCS			=	${shell find srcs/ -name "get_next_line*.c" -not -name "*bonus.c" -o -name "main.c"}
SRCS_B			=	${shell find srcs/ -name "*bonus.c" -o -name "main.c"}
OBJS			=	${SRCS:%.c=%.o}
OBJS_B			=	${SRCS:%.c=%_bonus.o}
OBJS_D			=	${SRCS:%.c=%_debug.o}
INCLUDES		=	-Iincludes
RM				=	rm -rf

%.o				:	%.c $(HEADER)
					$(CC) ${CC_FLAGS} ${INCLUDES} -c $< -o $@

%_bonus.o		:	%.c $(HEADER_B)
					$(CC) ${CC_FLAGS} ${INCLUDES} -c $< -o $@

%_debug.o		:	%.c $(HEADER)
					$(CC) ${CC_FLAGS_D} ${CC_FLAGS} ${INCLUDES} -c $< -o $@

all				:	${NAME}

${NAME}			:	$(OBJS)
					$(CC) $(INCLUDES) $^ -o $(NAME)

bonus			:	$(NAME_B)

$(NAME_B)		:	$(OBJS_B)
					$(CC) $(INCLUDES) $^ -o $(NAME_B)

debug			:	${NAME_D}

${NAME_D}		:	$(OBJS_D)
					$(CC) $(INCLUDES) $^ -o ${NAME_D}

clean			:
					$(RM) ${OBJS} $(OBJS_B) $(OBJS_D)

fclean			:	clean 
					$(RM) $(NAME) $(NAME_B) ${NAME_D}

re				:	fclean all

.PHONY			:	all bonus debug clean fclean re