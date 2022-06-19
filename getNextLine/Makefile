# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmartine <hmartine@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 17:34:33 by hmartine          #+#    #+#              #
#    Updated: 2022/06/18 21:39:00 by hmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= test 

SRC		= 	get_next_line.c \
			get_next_line_utils.c \

OBJ 	=	$(SRC:.c=.o)

CFLAGS 	=	-Wall -Werror -Wextra

CC 		=	gcc

%.o : %.c 	
	${CC} ${CFLAGS} -D BUFFER_SIZE=6 -I ./ -c $< -o $@ 

$(NAME):	$(OBJ)
		${CC} ${CFLAGS} -D BUFFER_SIZE=6 main.c ${OBJ} -o $@
		
all:	$(NAME)

clean:
			@rm -f $(OBJ)
			@echo "Get next line OBJ deleted"

fclean: clean
			@rm -f $(NAME)
			@echo "$(NAME) deleted"

t : 
	$(MAKE) 
	./test
re: fclean all

.PHONY: all fclean clean re 
