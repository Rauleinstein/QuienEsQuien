//cadena.cpp

#include <cadena.h>
#include <cstring>
#include <iostream>

Cadenas::Cadenas(){
	cad = 0;
	palabras = 0;
	ocupadas = 0;
}
Cadenas::Cadenas(int n){
	palabras = n;
	ocupadas = 0;
	cad = new char * [n];
}
Cadenas::Cadenas(const Cadenas &C){
	palabras = C.palabras;
	ocupadas = C.ocupadas;
	cad = new char *[palabras];
	for(int i=0; i<palabras; i++){
		cad[i] = new char [40];
		strcpy(cad[i], C.cad[i]);
	}
}
Cadenas::~Cadenas(){
	for(int i=0; i<palabras; i++){
		delete []  cad[i];
	}
	delete [] cad;
}

void Cadenas::AddCadena(const char * c){
	if(ocupadas == 0){
		cad = new char * [palabras];//SE CORROMPE AQUI Y NO SE PORQUE
	}
	if(ocupadas < palabras){
		cad[ocupadas] = new char [40];
		strcpy(cad[ocupadas], c);
		ocupadas++;
	}
	if(ocupadas>palabras){
		delete [] cad[0];
		for (int i=1;i<ocupadas;i++)
			cad[i-1]=cad[i];
		cad[ocupadas-1] = new char [40];
		for(int i=0; i<=strlen(c); i++){
			cad[ocupadas-1][i] = c[i];
		}
	}
}
istream &operator>>(istream &is, Cadenas &C){//Saber como para
	int n;
	char *cade;
	QC(is);
	is >> n;
	Cadenas caux;
	caux.palabras = n;
	for(int i=0; i<n; i++){
		QC(is);
		cade = new char [200];
		is.getline(cade, 200);
		LC(cade);
		caux.AddCadena(cade);
	}
	C = caux;
	return is;
}

ostream &operator<<(ostream &os, Cadenas &C){
	os << endl;
	os << C.ocupadas;
	os << endl;
	for(int i=0; i<C.ocupadas; i++){
		os << C.cad[i];
		os << endl;
	}
	return os;
}


Cadenas& Cadenas::operator=(const Cadenas &C){
	if(this !=0){
		for(int i=0; i<palabras; i++){
			delete [] cad[i];
		}
		delete [] cad;
	}
	ocupadas = C.ocupadas;
	palabras = C.palabras;
	cad = new char *[palabras];
	for(int i=0; i<palabras; i++){
		cad[i] = new char [40];
		strcpy(cad[i], C.cad[i]);
	}
	return *this;
}
char * Cadenas::GetCadena(int i){
	
	char *aux=new char[strlen(cad[i])+1];
	strcpy(aux, cad[i]);
	return aux;
}
