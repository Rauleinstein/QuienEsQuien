//utilidades.cpp
#include <utilidades.h>
#include <iostream>
#include <cstring>

using namespace std;

void QE(istream &is){//quitar espacios
	char aux =is.get();
	while(aux==' ' || aux=='\n' || aux=='\t'){
		aux=is.get();
	}
	is.unget();
}

void QC(istream &is){//quitar comentarios
	QE(is);
	char aux=is.peek();
	while(aux == '#'){
		is.ignore(1000, '\n');
		QE(is);
		aux=is.peek();
	}
}



void LC(char *cadena){
	char * aux=strstr(cadena, "#");
	if(aux!=0)
		*aux='\0';
	aux = cadena+(strlen(cadena)-1);
	while(aux!=cadena && *aux==' ')
		aux--;
	aux++;
	if(*aux==' ')
		*aux = '\0';
}

void Add(char * &cad, char c){
	char * aux = new char [strlen(cad)+2];
	for (int i=0; i<strlen(cad); i++){
		aux[i] = cad[i];
	}
	aux[strlen(cad)] = c;
	aux[strlen(cad)+1] = '\0';
	delete [] cad;
	cad = aux;
}
void Borrar(char * &cad){
	if(strlen(cad) > 0){
		char * aux = new char [strlen(cad)];
		for (int i=0; i<strlen(cad)-1; i++){
			aux[i] = cad[i];
		}
		aux[strlen(cad)-1] = '\0';
		delete [] cad;
		cad = aux;
	}
}
char * ConcatenarJugador(char * cad){
	char * aux = new char [200];
	strcpy(aux, "Humano > ");
	strcat(aux, cad);
	return aux;
}
char * ConcatenarMaquina(char * cad){
	char * aux = new char [200];
	strcpy(aux, "Maquina > ");
	strcat(aux, cad);
	return aux;
}