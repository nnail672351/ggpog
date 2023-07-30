CXX = g++
CXXFLAGS = -std=c++11
OBJ = main.o 
SRC = main.cpp head.h
EXE = text
all: $(EXE)
$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC)
clean:
	rm -f $(EXE)
	rm -f $(OBJ)