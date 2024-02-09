NAME = exe
CC = c++
FLAGS = -Wall -Wextra -std=c++17

all :				${NAME}

${NAME} :
					${CC} ${FLAGS} main.cpp ../src/spaceFillingCurves.cpp -o $@

clean :				
					rm -f ${NAME} jaja.csv

re :				clean all

.PHONY: all re clean