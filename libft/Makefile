# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diana <diana@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 14:01:29 by dkolarov          #+#    #+#              #
#    Updated: 2025/07/07 14:43:19 by diana            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
ALL_SRC = 	ft_bzero.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_strncmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_strmapi.c \
		ft_striteri.c  \
		ft_strtrim.c \
		ft_split.c \
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		get_next_line.c \
		ft_extra.c \
        ft_print_char.c \
        ft_print_hex.c \
        ft_print_int.c \
        ft_print_nbr.c \
        ft_print_ptr.c \
        ft_print_str.c \
        ft_printf.c

		
SRC        = $(filter-out %_bonus.c, $(ALL_SRC))
BONUS_SRC  = $(filter %_bonus.c, $(ALL_SRC))

OBJ        = $(SRC:.c=.o)
BONUS_OBJ  = $(BONUS_SRC:.c=.o)

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

AR         = ar rcs
RM         = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
	
clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
