# Solo generamos UN ejecutable (el cliente)
EXEC = p01_multiplate_grades_cliente

all: $(EXEC)

# Juntamos ambos códigos para crear el único ejecutable
p01_multiplate_grades_cliente: p01_multiplate_grades_cliente.cc p01_multiplate_grades.cc
	g++ -o $@ $^

.PHONY: all clean

clean:
	rm -f $(EXEC)

