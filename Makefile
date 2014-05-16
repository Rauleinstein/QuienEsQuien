#make de quien es quien
CXX = g++
INC = include
INC_GRAF = ../graficos/include
SRC = src
OBJ = obj
BIN = bin
LIB = lib
LIB_GRAF = ./../graficos/lib
CPPFLAGS = -Wall -g -c -I$(INC)
CPPFLAGS_GRAF = 
LDFLAGS = -L$(LIB_GRAF) -lm
LDFLAGS2 = -Llib -L../SDL_aulas/lib -lgraficos -lSDL -lSDL_gfx -lSDL_ttf -lfreetype


all: main

$(OBJ)/csopa.o: $(SRC)/csopa.cpp $(INC)/csopa.h $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/csopa.cpp -o $(OBJ)/csopa.o
	@echo Compila CSopa!!!

$(OBJ)/cmarco.o: $(SRC)/cmarco.cpp $(INC)/cmarco.h $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) -I$(INC) -I$(INC_GRAF) $(SRC)/cmarco.cpp -o $(OBJ)/cmarco.o
	@echo Compila CMarco!!!

$(OBJ)/cadena.o: $(SRC)/cadena.cpp $(INC)/cadena.h $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/cadena.cpp -o $(OBJ)/cadena.o
	@echo Compila Cadenas!!!

$(OBJ)/csopaamp.o: $(SRC)/csopaamp.cpp $(INC)/csopaamp.h
	$(CXX) -g -c -I$(INC) $(SRC)/csopaamp.cpp -o $(OBJ)/csopaamp.o
	@echo Compila CSopaamp!!!

$(OBJ)/crasgo.o: $(SRC)/crasgo.cpp $(INC)/crasgo.h $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/crasgo.cpp -o $(OBJ)/crasgo.o
	@echo Compila CRasgo!!!

$(OBJ)/ccrasgos.o: $(SRC)/ccrasgos.cpp $(INC)/ccrasgos.h $(INC)/crasgo.h $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/ccrasgos.cpp -o $(OBJ)/ccrasgos.o
	@echo Compila CCRasgos!!!

$(OBJ)/rasgocomp.o: $(SRC)/rasgocomp.cpp $(INC)/rasgocomp.h $(INC)/cadena.h $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/rasgocomp.cpp -o $(OBJ)/rasgocomp.o
	@echo Compila Rasgocomp!!!

$(OBJ)/todosrasgos.o: $(SRC)/todosrasgos.cpp $(INC)/todosrasgos.h $(INC)/rasgocomp.h $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/todosrasgos.cpp -o $(OBJ)/todosrasgos.o
	@echo Compila Todosrasgos!!!
	
$(OBJ)/personaje.o: $(SRC)/personaje.cpp $(INC)/personaje.h $(INC)/ccrasgos.h $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/personaje.cpp -o $(OBJ)/personaje.o
	@echo Compila Personaje!!!

$(OBJ)/cpersonajes.o: $(SRC)/cpersonajes.cpp $(INC)/cpersonajes.h $(INC)/personaje.h $(INC)/utilidades.h $(INC_GRAF)/graficos.h
	$(CXX) $(CPPFLAGS) -I$(INC) -I$(INC_GRAF) $(SRC)/cpersonajes.cpp -o $(OBJ)/cpersonajes.o
	@echo Compila CPersonajes!!!

$(OBJ)/config.o: $(SRC)/config.cpp $(INC)/config.h $(INC)/cmarco.h $(INC)/cadena.h $(INC_GRAF)/graficos.h
	$(CXX) $(CPPFLAGS) -I$(INC_GRAF) $(SRC)/config.cpp -o $(OBJ)/config.o
	@echo Compila Config!!!

$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/utilidades.cpp -o $(OBJ)/utilidades.o
	@echo Compila Utilidades!!!

$(OBJ)/preguntas.o: $(SRC)/preguntas.cpp $(INC)/preguntas.h $(INC)/todosrasgos.h $(INC)/cadena.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/preguntas.cpp -o $(OBJ)/preguntas.o
	@echo Compila Preguntas!!!

$(OBJ)/tablero.o: $(SRC)/tablero.cpp $(INC)/tablero.h $(INC)/cpersonajes.h $(INC)/personaje.h
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/tablero.cpp -o $(OBJ)/tablero.o
	@echo Compila Tablero!!!

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/config.h $(INC_GRAF)/graficos.h
	$(CXX) $(CPPFLAGS) -I$(INC_GRAF) $(SRC)/main.cpp -o $(OBJ)/main.o
	@echo Compila Main!!!

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/Doxyfile

# ************ Enlazado y creación de ejecutables ************
main: $(BIN)/main
$(BIN)/main: $(OBJ)/config.o $(OBJ)/cmarco.o $(OBJ)/main.o $(OBJ)/cpersonajes.o $(OBJ)/personaje.o $(OBJ)/ccrasgos.o $(OBJ)/crasgo.o $(OBJ)/todosrasgos.o $(OBJ)/rasgocomp.o $(OBJ)/tablero.o $(OBJ)/cadena.o $(OBJ)/utilidades.o $(OBJ)/preguntas.o
	@echo Construido el ejecutable ...
	$(CXX) -o $(BIN)/main $(OBJ)/config.o $(OBJ)/cmarco.o $(OBJ)/main.o $(OBJ)/tablero.o $(OBJ)/cpersonajes.o $(OBJ)/personaje.o $(OBJ)/ccrasgos.o $(OBJ)/crasgo.o $(OBJ)/todosrasgos.o $(OBJ)/rasgocomp.o $(OBJ)/cadena.o $(OBJ)/utilidades.o  $(OBJ)/preguntas.o $(LDFLAGS) $(LDFLAGS2)

clean:
	-rm  $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

