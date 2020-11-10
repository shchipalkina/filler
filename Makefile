NAME = cmilda.filler

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./sources
INC_DIR = ./includes
OBJ_DIR = ./obj

LIBFT_INC_DIR = ./filler/libft/includes/

LIBFT = libft/libft.a

SRC				=	main.c \
					play.c \
					make_move.c \
					free_array.c \
					get_map_and_piece.c \
					set_players.c

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ				=	$(SRC:.c=.o)
OBJS			=	$(addprefix $(OBJ_DIR)/, $(OBJ))

INCS = $(INC_DIR)/filler.h

all: libs $(NAME)

$(NAME): $(INCS) $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "Cmilda is ready."

libs:
	make -C libft/

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(FLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -o $@ -c $<

clean:
	$(MAKE) -C libft/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
