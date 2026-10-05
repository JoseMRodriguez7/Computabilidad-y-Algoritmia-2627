CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = p04_html_cliente
OBJS = p04_html_cliente.o html_analyzer.o tags.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)