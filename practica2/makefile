CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = p02_strings
OBJS = p02_strings_cliente.o p02_alphabet.o p02_chain.o p02_language.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)