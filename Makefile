CXX = g++
INCLUDE_DIRS = $(shell find src lib -type d)
INC_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))
CXXFLAGS = -Wall -Wextra -std=c++17 $(INC_FLAGS)
TARGET = 3122a_YM_Biblioteca
SRC = $(shell find src lib -name '*.cpp')
OBJ = $(SRC:.cpp=.o)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL

all: $(TARGET)

$(TARGET):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	find src lib -name "*.o" -delete
	rm -f $(TARGET)
