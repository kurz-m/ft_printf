# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makurz <makurz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 18:12:43 by makurz            #+#    #+#              #
#    Updated: 2023/04/03 14:23:10 by makurz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME := libftprintf.a

# Define the compiler the Makefile should use
CC := cc

# Add the neccessary flags for compiling 
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := -rcs

# Add the remove command
RM := rm -f

# Explicitly state all function names for the mandatory part
SRCS :=	ft_printf.c ft_printf_utils_str.c ft_printf_utils_nbr.c

# Substitute the suffix .c with .o for the object files
OBJS := $(SRCS:%.c=%.o)

# Main rule to compile the mandatory part
$(NAME): $(OBJS)
	@ar $(ARFLAGS) $@ $^

# Create a static rule for compiling from source to object file
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Only clean the object files
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

# Additionally removes the library
fclean: clean
	@$(RM) $(NAME)

# Cleans all object files and also the library and newly create the library
re: fclean all

# Creates the library from the mandatory and bonus part
all: $(NAME)

# Tell the Makefile that all those commands are actual commands and not files
.PHONY: all clean fclean re

