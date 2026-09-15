# Variables del compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Nombres de los ejecutables
TARGET1 = p01_single_grades
TARGET2 = p01_multiple_grades

# Archivos objeto necesarios para cada ejecutable
OBJS1 = p01_single_grades_cliente.cc p01_single_grades.cc
OBJS2 = p01_multiplate_grades_cliente.cc p01_multiplate_grades.cc

# Regla principal: compila ambos programas por defecto al usar 'make'
all: $(TARGET1) $(TARGET2)

# Regla para compilar single_grades
$(TARGET1): $(OBJS1)
	$(CXX) $(CXXFLAGS) -o $(TARGET1) $(OBJS1)

# Regla para compilar multiple_grades
$(TARGET2): $(OBJS2)
	$(CXX) $(CXXFLAGS) -o $(TARGET2) $(OBJS2)

.PHONY: all clean

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET1) $(TARGET2)

