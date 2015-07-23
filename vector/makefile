BIN=./bin
INCLUDE=include
SRC=./src
OBJ=./obj
LIB=./lib
CXX = g++
CPPFLAGS = -Wall -g -c -I$(INCLUDE)


all: $(BIN)/prueba

$(BIN)/prueba: $(OBJ)/prueba.o $(LIB)/libimagen.a 
	$(CXX) $(OBJ)/prueba.o $(LIB)/libimagen.a -o $(BIN)/prueba

$(OBJ)/prueba.o: $(SRC)/prueba.cpp $(INCLUDE)/imagen.h
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba.cpp -o $(OBJ)/prueba.o

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/codificar.o 
	ar -rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/codificar.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INCLUDE)/imagen.h $(INCLUDE)/pgm.h
	$(CXX) $(CPPFLAGS)  $(SRC)/imagen.cpp -o $(OBJ)/imagen.o 

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INCLUDE)/pgm.h
	$(CXX) $(CPPFLAGS)  $(SRC)/pgm.cpp -o $(OBJ)/pgm.o 

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INCLUDE)/byte.h
	$(CXX) $(CPPFLAGS) $(SRC)/byte.cpp -o $(OBJ)/byte.o 

$(OBJ)/codificar.o: $(SRC)/codificar.cpp $(INCLUDE)/codificar.h
	$(CXX) $(CPPFLAGS)  $(SRC)/codificar.cpp -o $(OBJ)/codificar.o 


	
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	echo "Borrado de archivos objetos : "
	rm $(OBJ)/*.o
	echo "Borrado imagenes generadas anteriormente :"
	rm *.pgm
	echo "Borrado de los ejecutables"
	rm $(BIN)/*

mrproper: clean
	rm $(BIN)/testimagen
