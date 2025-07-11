
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -O2

SRC = src/main.cpp src/integer.cpp src/floating.cpp
OBJ = $(SRC:.cpp=.o)

all: infprec-cli

infprec-cli: $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^

clean:
    rm -f $(OBJ) infprec-cli
