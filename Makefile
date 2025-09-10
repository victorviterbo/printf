# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2025/09/10 15:43:08 by victorviter      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_conv_utils.c ft_itoa_base.c ft_memutils.c ft_printf.c ft_strutils.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) compiled successfully"

$(OBJS) : $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS) -I$(HEADER)


.PHONY: all clean fclean re
