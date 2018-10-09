# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <abiri@1337.MA>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 17:31:52 by abiri             #+#    #+#              #
#    Updated: 2018/10/07 19:16:11 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = EXEC
LIBDIR = ../libftwrong

all: part1 part2 bonus
part1:
	@echo "\033[0;96m-----------Compiling part 1----------"
	gcc -Wall -Werror -Wextra -o $(NAME)-1 tools.c src/part1.c -I$(LIBDIR) -L$(LIBDIR) -lft
	@echo "\033[0;96m"
part2:
	gcc -Wall -Werror -Wextra -o $(NAME)-2 tools.c src/part2.c -I$(LIBDIR) -L$(LIBDIR) -lft
bonus:
	gcc -Wall -Werror -Wextra -o $(NAME)-bonus tools.c src/bonus.c -I$(LIBDIR) -L$(LIBDIR) -lft
