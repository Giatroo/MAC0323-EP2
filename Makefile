CC = g++
FLAGS = -Wall -g -O0
OBJ = ./obj

all : main
	@echo "Compilado corretamente"

main : main.cpp interface.cpp
	${CC} ${FLAGS} $^ -o $@
