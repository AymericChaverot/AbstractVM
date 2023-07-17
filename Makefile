##
## EPITECH PROJECT, 2023
## abstractVM
## File description:
## Makefile
##

NAME = abstractVM

SRC =	src/main.cpp \
		src/Operands/Exceptions/DivisionByZeroException.cpp \
		src/Operands/Exceptions/OverflowException.cpp \
		src/Operands/Exceptions/UnderflowException.cpp \
		src/Operands/Exceptions/UnknownTypeException.cpp \
		src/Operands/AOperand.cpp \
		src/Operands/Int8/Int8.cpp \
		src/Operands/Int16/Int16.cpp \
		src/Operands/Int32/Int32.cpp \
		src/Operands/Float/Float.cpp \
		src/Operands/Double/Double.cpp \
		src/Operands/Factory/OperandFactory.cpp \
		src/Memory/Exceptions/EmptyStackPopException.cpp \
		src/Memory/Exceptions/CantLoadException.cpp \
		src/Memory/Memory.cpp \
		src/IO/Exceptions/CantOpenFileException.cpp \
		src/IO/Exceptions/NoExitException.cpp \
		src/IO/FileReader/FileReader.cpp \
		src/IO/CinReader/CinReader.cpp \
		src/IO/TerminalOut/TerminalOut.cpp \
		src/Processing/Exceptions/SyntaxException.cpp \
		src/Processing/Exceptions/UnknownInstructionException.cpp \
		src/Processing/Exceptions/AssertFailException.cpp \
		src/Processing/CommandHandler/CommandHandler.cpp \
		src/Processing/Processor.cpp \
		src/Processing/Chipset/Chipset.cpp

OBJ = $(SRC:.cpp=.o)

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++20 -I./src

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)

re: fclean all
