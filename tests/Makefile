# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makurz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 14:11:05 by makurz            #+#    #+#              #
#    Updated: 2023/04/04 16:50:59 by makurz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Specify the used compiler
CC := cc

# Specify the compiler flags
CFLAGS := -Wall -Wextra -Werror

# Specify the library paths
LDFLAGS := -lcriterion -L.. -lftprintf

# Specify the remove flags
RM := rm -f

# Specify all test sources
SRCS :=	C_tests.c ID_tests.c P_tests.c Perc_tests.c \
		S_tests.c U_tests.c Xx_tests.c

# Create the names of the executable files from the source files
EXECS := $(SRCS:%.c=%.out)

# Create a strict rule on how to compile the object files
%.out: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# create all the executable files
all: $(EXECS)

# run all the executable files
run: all
	for exec in $(EXECS); do ./$$exec; done

# Define a rule 'clean' to remove the executable files
clean:
	$(RM) $(EXECS)

# Setup the executable files newly
re: clean run

# Define PHONY targets
.PHONY: all run clean
