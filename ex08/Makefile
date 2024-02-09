NAME = exe
CC = c++
FLAGS = -Wall -Wextra -std=c++17

all :				${NAME}

${NAME} :
					${CC} ${FLAGS} main.cpp ../src/booleFunctions.cpp ../src/MyNatural.cpp -o $@

clean :				
					rm -f ${NAME}

re :				clean all

.PHONY: all re clean