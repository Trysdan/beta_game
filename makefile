# Variables
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -I./src -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = src
BIN_DIR = bin
ASSET_DIR = assent
TARGET = $(BIN_DIR)/beta_game.exe

# Archivos fuente y objetos
SRCS = main.cpp $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Reglas
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(BIN_DIR)/*.o $(TARGET) *.o

.PHONY: all clean
