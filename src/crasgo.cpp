#include <crasgo.h>
#include <iostream>
#include <cstring>



Rasgo::Rasgo(){
	tipo = 0;
	valor = 0;
}
Rasgo::Rasgo(char *tipo, char *valor){
	this->tipo = new char [strlen(tipo)+1];
	this->valor = new char [strlen(valor)+1];
	strcpy(this->tipo, tipo);
	strcpy(this->valor, valor);
}
Rasgo::~Rasgo(){
	delete [] tipo;
	delete [] valor;
}
Rasgo & Rasgo::operator=(const Rasgo &R){
	if(this != &R){
		delete [] tipo;
		delete [] valor;
		tipo = new char [strlen(R.tipo)+1];
		valor = new char [strlen(R.valor)+1];
		strcpy(tipo, R.tipo);
		strcpy(valor, R.valor);
	}
	return *this;
}
istream & operator>>(istream &is, Rasgo &R){
	R.tipo = new char [80];
	is.getline(R.tipo, 80);
	R.valor = new char [80];
	is.getline(R.valor, 80);
	return is;
}
ostream & operator<<(ostream &os,const Rasgo &R){
	os << "Rasgo: "<< R.tipo << endl;
	os << "Valor: " << R.valor << endl;
	return os;
}
char * Rasgo::DevuelveValor(){
	
	char *aux=new char[strlen(valor)+1];
	strcpy(aux, valor);
	return aux;
}
char * Rasgo::DevuelveTipo(){
	
	char *aux=new char[strlen(tipo)+1];
	strcpy(aux, tipo);
	return aux;
}