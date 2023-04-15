# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makurz <dumba@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 20:04:51 by makurz            #+#    #+#              #
#    Updated: 2023/04/15 20:05:21 by makurz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the name of the library
NAME := libftprintf.a

# Set compiler and debugger according to OS
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	CC := gcc
	DB := gdb
	CFLAGS ?= -Wall -Wextra -Werror -fsanitize=leak
else ifeq ($(UNAME), Darwin)
	CC := clang
	DB := lldb
	CFLAGS ?= -Wall -Wextra -Werror
else
	$(error Unsupported operating system: $(UNAME))
endif

# Add the neccessary flags for compiling 
LDFLAGS ?=
ARFLAGS := -rcs

# Add the remove command
RM := rm -f

# Add paths for the source files
VPATH = src/

# Explicitly state all function names for the mandatory part
SRCS :=	ft_printf.c ft_printf_utils_str.c ft_printf_utils_nbr.c

# Define a directory for object files
OBJ_DIR := ./_obj
OBJ_DIR_DEBUG := ./_obj_debug

# Substitute the suffix .c with .o for the object files
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:ft_%.c=%.o))

# Specify folder for header file
INC := -I ./header

# Create object files for debugging
OBJS_DEBUG := $(addprefix $(OBJ_DIR_DEBUG)/, $(SRCS:ft_%.c=%.o))

# Color codes
Y := "\033[33m"
R := "\033[31m"
G := "\033[32m"
X := "\033[0m"
UP := "\033[A"
CUT := "\033[K"

# Main rule to compile Libft
all: $(NAME)
	@printf "\n"
	@echo $(G)"                       **"
	@echo $(G)"                      /**"
	@echo $(G)"  **********   ******  /**  ** **   ** ****** ******"
	@echo $(G)" //**//**//** //////** /** ** /**  /**//**//*////**"
	@echo $(G)"  /** /** /**  ******* /****  /**  /** /** /    **"
	@echo $(G)"  /** /** /** **////** /**/** /**  /** /**     **"
	@echo $(G)"  *** /** /**//********/**//**//******/***    ******"
	@echo $(G)" ///  //  //  //////// //  //  ////// ///    //////"$(X)
	@printf "\n\n"

$(NAME): $(OBJS)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@ar $(ARFLAGS) $(NAME) $(OBJS)
	@printf $(UP)$(CUT)
	@echo $(G)Finished"  "[$(NAME)]...$(X)

# Create a static rule for compiling from source to object file
$(OBJ_DIR)/%.o: ft_%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p _obj
	@$(CC) $(CFLAGS) -MMD -MP -c $< $(INC) -o $@
	@printf $(UP)$(CUT)

# Cleans only the object files if they exist
clean:
	@if [ -d "${OBJ_DIR}" ]; then \
		echo $(R)Cleaning"  "[$(OBJ_DIR)]...$(X); \
		rm -r ${OBJ_DIR}; \
		echo $(G)Cleaned!$(X); \
	fi

# Cleans the debug files if ran with -g flag
clean_debug:
	@if [ -d "${OBJ_DIR_DEBUG}" ]; then \
		echo $(R)Cleaning"  "[$(OBJ_DIR_DEBUG)]...$(X); \
		rm -r ${OBJ_DIR_DEBUG}; \
		echo $(G)Cleaned!$(X); \
	fi

# Cleans also the library
fclean: clean clean_debug
	@if [ -f "$(NAME)" ]; then \
		echo $(R)Cleaning"  "[$(NAME)]...$(X); \
		rm -r $(NAME); \
		echo $(G)Cleaned!$(X); \
	fi

# Cleans all object files and also the library and newly create the library
re: fclean all

# Runs the compiler with the debugger flag
debug: $(OBJS_DEBUG)
	$(CC) $(CFLAGS) -g $^ $(LIB) -o debug
	$(DB) debug


# Rule for the debug compilation
$(OBJ_DIR_DEBUG)/%.o: ft_%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p _obj_debug
	@$(CC) $(CFLAGS) -g -MMD -MP -c $< $(INC) -o $@
	@printf $(UP)$(CUT)

# Tell the Makefile that all those commands are actual commands and not files
.PHONY: all clean fclean debug re

-include $(OBJ:%.o=%.d)
