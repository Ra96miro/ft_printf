# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 13:03:39 by gramiro-          #+#    #+#              #
#    Updated: 2022/03/26 19:00:04 by gramiro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		= ft_functionprintf.c ft_printf.c 
OBJS		= $(SRCS:.c=.o)
INCL		= includes/ft_printf.h
CFLAGS		= -Wall -Wextra -Werror -I.
RM			= rm -f
CC			= gcc
all:		$(NAME)
$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean all
.PHONY:		clean fclean all re
