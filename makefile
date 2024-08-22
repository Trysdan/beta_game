# Variables
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -I./src -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/beta_game.exe

# Archivos fuente y objetos
ROOT_SRCS = main.cpp Settings.cpp
SRCS = $(ROOT_SRCS) $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst %.cpp,$(BIN_DIR)/%.o,$(notdir $(SRCS)))

# Reglas
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	rm -f $(OBJS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN_DIR)/main.o: main.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BIN_DIR)/Settings.o: Settings.cpp
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: all clean

clean:
	rm -rf $(BIN_DIR)/*.o $(TARGET)
