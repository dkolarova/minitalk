# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diana <diana@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 10:01:43 by diana             #+#    #+#              #
#    Updated: 2025/08/13 11:59:52 by diana            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT   = client
NAME_SERVER   = server

# Source files
SRCS_CLIENT   = client.c
SRCS_SERVER   = server.c

# Object files
OBJS_CLIENT   = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER   = $(SRCS_SERVER:.c=.o)

# Libft
LIBFT_DIR     = libft
LIBFT         = $(LIBFT_DIR)/libft.a

# Compiler and flags
CC            = cc
CFLAGS        = -Wall -Wextra -Werror -Ilibft

# Rules
all: $(NAME_CLIENT) $(NAME_SERVER)

# Build client
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

# Build server
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

# Libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean objects
clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

# Full clean
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
