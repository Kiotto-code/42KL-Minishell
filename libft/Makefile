NAME	= libft.a
CC		= gcc
AR		= ar
CFLAGS	= -Wall -Werror -Wextra
CFLAGS	+= #-fsanitize=address -g3
ARFLAGS	= rcs
RM		= rm -rf
DEBUG	= $(ARGS)

INCLUDES	= ./includes
SRC_PATH	= ./src
OBJ_PATH	= ./obj

# SRCS	= ${shell find ./src/libft/ -name "*.c"}
# OBJS	= $(addprefix $(OBJ_PATH)/,$(patsubst %.c,%.o,$(notdir $(SRCS))))
# SRCS    = $(wildcard ./*.c)
# OBJS    = ${SRCS:./src/libft/%.c=${OBJ_PATH}/%.o}

# SRCS	= ${shell find ./src/libft/ -name "*.c"}
# OBJS	= $(addprefix $(OBJ_PATH)/,$(patsubst %.c,%.o,$(notdir $(SRCS))))

SRCS	= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*/*,.c*)))
OBJS	= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRCS)))))

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(ARFLAGS) $@ $^

$(OBJ_PATH)/%.o:	$(SRC_PATH)/*/%.c* ./Makefile | $(OBJ_PATH)
					$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJ_PATH):
				mkdir -p $(OBJ_PATH)

clean:
			$(RM) $(OBJ_PATH)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		$(OBJS)
			$(CC) $(CFLAGS) $(CSAN) test.c $^ -I$(INCLUDES) -o ./a.out
# gcc -fsanitize=address -g3 ./libft.a $(ARGS)
# make $(NAME) $(ARGS)

# debug:		make $(NAME) main.c

.PHONY:		all clean fclean re debug