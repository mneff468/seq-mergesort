CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall -Wextra -pedantic
TARGET = mergesort
SRC = src/main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o
