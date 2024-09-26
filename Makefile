### Makefile for BST ###
EXE=BST
INC=\

SRC=\
	src/main.cpp\
	src/BST.cpp\

CXX=clang++
CXXFLAGS=-g -Iinclude/
LFLAGS=
LDFLAGS=

.SUFFIXES:

all:	$(EXE)

$(INC): $(SRC)

$(EXE):	$(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@ $(LFLAGS) $(LDFLAGS)

clean:
	rm -f $(EXE)
