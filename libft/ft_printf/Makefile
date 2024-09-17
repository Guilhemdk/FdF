# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilhem <guilhem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:35:55 by tfriedri          #+#    #+#              #
#    Updated: 2024/09/14 14:20:42 by guilhem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= libftprintf.a
CC 		 	= cc
CFLAGS  	= -Wall -Werror -Wextra 
AR 			= ar rcs
RM 			= rm -rf
RANLIB 		= ranlib

SRCS = 	ft_printf.c \
		ft_printf_utils/ft_putadress.c \
		ft_printf_utils/ft_puthexa.c \
		ft_printf_utils/ft_putunsigned.c \
		ft_printf_utils/ft_putchar.c \
		ft_printf_utils/ft_putstr.c \
		ft_printf_utils/ft_putnbr.c \
		ft_printf_utils/ft_strchr.c \
		ft_printf_utils/ft_strlen.c  \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

clean:
	@$(RM) $(OBJS)
	
fclean: clean
	@$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re