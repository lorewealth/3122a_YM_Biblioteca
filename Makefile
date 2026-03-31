CXX = g++
INCLUDE_DIRS = $(shell find src -type d)
INC_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))
CXXFLAGS = -Wall -Wextra -std=c++17 $(INC_FLAGS)
TARGET = 3122a_YM_Biblioteca
SRC = $(shell find src -name '*.cpp')
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
