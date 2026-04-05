ifeq ($(OS), Windows_NT) # Windows
    SFML_LIB_DIR = ./lib/SFML/bin-windows
    LDFLAGS = -L$(SFML_LIB_DIR)
    LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopengl32
    TARGET = 3122a_YM_Biblioteca.exe
else # Linux
	SFML_LIB_DIR = ./lib/SFML/bin-linux
	LDFLAGS += -L$(SFML_LIB_DIR) -Wl,-rpath,$(SFML_LIB_DIR)
	LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lGL
	TARGET = 3122a_YM_Biblioteca
endif

CXX = g++
INCLUDE_DIRS = $(shell find src lib -type d)
INC_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))
CXXFLAGS = -Wall -Wextra -std=c++20 $(INC_FLAGS)
SRC = $(shell find src lib -name '*.cpp')
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

ifeq ($(OS), Windows_NT) #Windows
run: $(TARGET)
	PATH="$(SFML_LIB_DIR):$$PATH" ./$(TARGET)
clean:
	powershell -Command "Get-ChildItem -Recurse -Filter '*.o' | Remove-Item -Force"
	-rm -f "$(TARGET)"
else # Linux
run: $(TARGET)
	./$(TARGET)
clean:
	find src lib -name "*.o" -delete
	rm -f $(TARGET)
endif
