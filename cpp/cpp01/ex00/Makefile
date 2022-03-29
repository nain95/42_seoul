FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ./Zombie.cpp ./newZombie.cpp ./randomChump.cpp ./main.cpp
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