CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = p06_automata_cliente
OBJS = p06_automata_cliente.o automata.o state.o alphabet.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)