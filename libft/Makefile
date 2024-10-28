# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliobreg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 17:15:55 by aliobreg          #+#    #+#              #
#    Updated: 2024/04/10 15:44:34 by aliobreg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC = ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
		ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c\
		ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memchr.c\
		ft_putstr_fd.c	ft_strlen.c	ft_toupper.c ft_calloc.c ft_memcmp.c\
		ft_split.c ft_strmapi.c ft_isalnum.c ft_memcpy.c ft_strchr.c\
		ft_strncmp.c ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c\
		ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re
