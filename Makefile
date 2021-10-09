NAME = ft_container
SRC =	main.cpp\
		vector.cpp\

HEADERS = ./vector_test.hpp\
			./iterator_test.hpp\


all: $(NAME) $(HEADERS)

$(NAME): $(SRC) $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)