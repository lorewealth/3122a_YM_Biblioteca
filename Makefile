CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = proiect3122a_YM_BiblioTest
SRC = src/main.cpp

all: $(TARGET)

$(TARGET):$(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
