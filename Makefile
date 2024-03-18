# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 15:17:46 by asargsya          #+#    #+#              #
#    Updated: 2024/02/14 15:17:48 by asargsya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIB_PATH = ./ft_printf.h
SRCS =  ft_printf.c ft_printf_int.c ft_printf_unsigned.c \
		ft_printf_char.c ft_printf_pointer.c  \
		ft_printf_hex.c	ft_printf_string.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all:	$(NAME)

%.o: %.c Makefile ft_printf.h
		$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I $(LIB_PATH)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:	
			$(RM) $(OBJS) $(BNSOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean flcean re
