# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 18:29:34 by yichan            #+#    #+#              #
#    Updated: 2023/04/25 17:53:42 by yichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC      =   gcc
RM      =   rm -rf
CFLAGS  =   -Wall -Werror -Wextra
CFLAGS	+=	-I/usr/local/opt/readline/include
CSAN  =  -fsanitize=address -g3
READLINE	= -lreadline
READLINE	+= -lreadline -lncurses -L/usr/local/opt/readline/lib
INCLUDES    = ./includes
SRC_PATH    = ./srcs/**
OBJ_PATH    = ./obj
LIBFT_PATH	= ./libft

SRCS	= $(wildcard srcs/*/*.c)
# SRCS    = $(wildcard ./srcs/*/*.c)
# OBJS    = ${SRCS:./srcs/%.c=${OBJ_PATH}/%.o}
# SRCS	= ${shell find ./src/libft/ -name "*.c"}
OBJS	= $(addprefix $(OBJ_PATH)/,$(patsubst %.c,%.o,$(notdir $(SRCS))))
# SRCS	= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*/*,.c*)))
# OBJS	= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRCS)))))


all				:	$(NAME)

$(NAME)			:	$(OBJS)
					make -C libft
					$(CC) $(CFLAGS) $(CSAN) $^ $(READLINE) -I$(INCLUDES) -lft -L$(LIBFT_PATH) -o $@

# $(NAME)			:	$(OBJS)
# 					make -C libft
# 					$(CC) $(CFLAGS) $^ -lreadline -lncurses -L$(LIBFT_PATH) -lft -o $@


$(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c* ./includes/*.h ./Makefile | $(OBJ_PATH) 
					$(CC) $(CFLAGS) $(CSAN) -c -I$(INCLUDES) $< -o $@

# $(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c* ./includes/*.h ./Makefile | $(OBJ_PATH) 
# 					$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $@


$(OBJ_PATH)		:
					mkdir -p $(OBJ_PATH)


clean			:
					$(MAKE) -C $(LIBFT_PATH) $@
					rm -rf $(OBJ_PATH)


fclean			:	clean
					$(MAKE) -C $(LIBFT_PATH) $@
					rm -rf $(NAME)


re				:   fclean all


.PHONY			:	all clean fclean re