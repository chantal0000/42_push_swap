# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:14:10 by chbuerge          #+#    #+#              #
#    Updated: 2023/12/04 16:15:00 by chbuerge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# defines name of the output library file
NAME = push_swap
# defines name of the lobrary file of libft project
LIBFT_NAME = libft/libft.a

# which c compiler to use -> cc
CC = cc
# which flags to use for warnings and treating warnings
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
# where to locate libft
LIBFT_DIR = ./libft

# list of the source files srequired to build the project
SRCS =		a_to_b.c \
			check_input.c \
			create_nodes.c \
			main.c \
			prep_b.c \
			sorting.c \
			utils_nodes.c \
			operations/push.c \
			operations/rotate_reverse.c \
			operations/rotate.c \
			operations/sort_three.c \
			operations/swap.c

# defines the object files that will be generated from the cource files
OBJS = ${SRCS:.c=.o}

# BUILD TARGETS
all: ${NAME}

$(NAME): $(LIBFT_NAME) $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBFT_NAME) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

#makelibft:
# -C allows you to change directories before running make process
# enter libft directory and run the make process there
#	@make -C $(LIBFT_DIR)
# cp -> copies 'libft.a' into the current directory '.'
#	@cp $(LIBFT_DIR)/$(LIBFT_NAME) .
# rename the libft.a to libftprintf.a
#	@mv $(LIBFT_NAME) $(NAME)
# compiles the object files into the push_swap static library (ar, archive)
#${NAME}: makelibft ${OBJS}
#	@ar -r ${NAME} ${OBJS}

$(LIBFT_NAME):
	cd libft && make
# Remove object files and executables
clean:
	@rm -f ${OBJS}
	@cd $(LIBFT_DIR) && make clean

# Remove object files, executables, and the libft library
fclean:	clean
	@rm -f ${NAME}
	@cd $(LIBFT_DIR) && make fclean

# Rebuild the project from scratch
re:	fclean all



.PHONY: all clean fclean re
