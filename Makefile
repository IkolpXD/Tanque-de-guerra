# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 17:35:32 by made-jes          #+#    #+#              #
#    Updated: 2025/12/11 23:07:58 by made-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# PATHS

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

INC = ./includes

SRC_DIR = ./sources

OBJ_DIR = ./obj

# Source files

SOURCES = main.c lexer/lexer.c lexer/utils.c utils.c prompt.c parser/parser.c \
		parser/utils.c expander/expander.c expander/utils.c signals.c freeing.c \
		expander/expander_tokens.c expander/expander_2.c

SRCS = $(addprefix $(SRC_DIR)/, $(SOURCES))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler flags
CC = cc -g 

CFLAGS = -Wall -Wextra -Werror -I $(INC)

# Rules
all: $(NAME)

$(LIBFT):
	@echo "Libft is compiling..."
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "Libft is compiled!"
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME) > /dev/null
	@echo "minishell is compiled!"

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@echo "Objects cleaned!"

fclean: clean
	@echo "Cleaning project..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@echo "All cleaned!"

re: fclean all

.PHONY: all clean fclean re