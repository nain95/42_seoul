FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ./main.cpp ./Zombie.cpp ./ZombieHorde.cpp
NAME = zombie

OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

.cpp.o:
	c++ $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	c++ $(FLAGS) -o $(NAME)  $(OBJS)

clean :
		rm -rf $(OBJS)
		
fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONE : all clean fclean re