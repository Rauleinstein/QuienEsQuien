#include <rasgocomp.h>
#include <iostream>
#include <cstring>
#include <cadena.h>

using namespace std;

Rasgoc::Rasgoc(){
	nombrerasgo = 0;
	preguntagener = 0;
}
Rasgoc::~Rasgoc(){
	delete [] nombrerasgo;
	delete [] preguntagener;
}
Rasgoc::Rasgoc(const Rasgoc &R){
	nombrerasgo = new char [strlen(R.nombrerasgo)+1];
	preguntagener = new char [strlen(R.preguntagener)+1];
	strcpy(preguntagener, R.preguntagener);
	strcpy(nombrerasgo, R.nombrerasgo);
	C = R.C;
}
Rasgoc Rasgoc::operator=(const Rasgoc &R){
	if(this != &R){
		delete [] nombrerasgo;
		delete [] preguntagener;
		nombrerasgo = new char [strlen(R.nombrerasgo)+1];
		preguntagener = new char [strlen(R.preguntagener)+1];
		strcpy(preguntagener, R.preguntagener);
		strcpy(nombrerasgo, R.nombrerasgo);
		C = R.C;
	}
	return *this;
}
istream &operator>>(istream &is, Rasgoc &Rc){
	QC(is);
	Rc.nombrerasgo = new char [80];
	is.getline(Rc.nombrerasgo, 80);
	QC(is);
	Rc.preguntagener = new char [80];
	is.getline(Rc.preguntagener, 80);
	QC(is);
	is >> Rc.C;
	return is;
}
ostream &operator<<(ostream &os, Rasgoc &Rc){
	os << Rc.nombrerasgo << endl;
	os << Rc.preguntagener << endl;
	os << Rc.C;
	return os;
}
char * Rasgoc::ExtraePregunta(){
	
	char *aux=new char[strlen(preguntagener)+1];
	strcpy(aux, preguntagener);
	return aux;
}
char * Rasgoc::ExtraeRasgo(int n){
	
	char *aux=new char[strlen(C.GetCadena(n))+1];
	strcpy(aux, C.GetCadena(n));
	return aux;
}