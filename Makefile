# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:45:22 by vviterbo          #+#    #+#              #
#    Updated: 2024/10/16 15:08:52 by vviterbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_conv_utils.c ft_itoa_base.c ft_printf.c ft_strutils.c ft_memutils.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

clean :
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS) -I$(HEADER)


.PHONY: all clean fclean re bonus
