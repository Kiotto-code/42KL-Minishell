NAME	= libft.a
CC		= gcc
AR		= ar
CFLAGS	= -Wall -Werror -Wextra
CFLAGS	+= -fsanitize=address -g3
ARFLAGS	= rcs
RM		= rm -rf

INCLUDES	= ./includes
SRC_PATH	= ./src
OBJ_PATH	= ./obj

# SRCS	= ${shell find ./src/libft/ -name "*.c"}
# OBJS	= $(addprefix $(OBJ_PATH)/,$(patsubst %.c,%.o,$(notdir $(SRCS))))
# SRCS    = $(wildcard ./*.c)
# OBJS    = ${SRCS:./src/libft/%.c=${OBJ_PATH}/%.o}

# SRCS	= ${shell find ./src/libft/ -name "*.c"}
# OBJS	= $(addprefix $(OBJ_PATH)/,$(patsubst %.c,%.o,$(notdir $(SRCS))))

# SRCS	= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*/*,.c*)))
# OBJS	= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRCS)))))

SRCS	= $(wildcard $(SRC_PATH)/*/*.c)
OBJS	= $(addprefix $(OBJ_PATH)/,$(patsubst %.c,%.o,$(notdir $(SRCS))))

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/*/%.c* ./includes/*.h | $(OBJ_PATH)
					$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@

$(OBJ_PATH):
				mkdir -p $(OBJ_PATH)

clean:
			$(RM) $(OBJ_PATH)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re