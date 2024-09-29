# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amecani <amecani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 21:15:16 by amecani           #+#    #+#              #
#    Updated: 2024/09/29 18:09:10 by amecani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++17 -MMD -MP
NAME=KoichiIfHeWasAFixedPoint

SRC= main.cpp Fixed.cpp
OBJ=$(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) ${OBJ}

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf $(OBJ)

re: fclean all

.PHONY: re all fclean clean