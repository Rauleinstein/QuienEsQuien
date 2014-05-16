#include <todosrasgos.h>
#include <rasgocomp.h>
#include <iostream>
#include <cstring>

using namespace std;

Todosrasgos::Todosrasgos(){
	n_rasgos = 0;
	Rs = 0;
}
Todosrasgos::~Todosrasgos(){
	delete [] Rs;
}
Todosrasgos::Todosrasgos(const Todosrasgos &T){
	n_rasgos = T.n_rasgos;
	Rs = new Rasgoc [n_rasgos];
	for(int i=0; i<T.n_rasgos; i++)
		Rs[i] = T.Rs[i];
}
Todosrasgos & Todosrasgos::operator=(const Todosrasgos &T){
	if(this != &T){
		delete [] Rs;
		n_rasgos = T.n_rasgos;
		Rs = new Rasgoc [n_rasgos];
		for(int i=0; i<T.n_rasgos; i++)
			Rs[i] = T.Rs[i];
	}
	return *this;
}
istream &operator>>(istream &is, Todosrasgos &T){
	QC(is);
	is >> T.n_rasgos;
	QC(is);
	T.Rs = new Rasgoc [T.n_rasgos];
	for(int i=0; i<T.n_rasgos; i++){
		QC(is);
		is >> T.Rs[i];
	}
	return is;
}
ostream &operator<<(ostream &os, Todosrasgos &T){
	os << "El numero de rasgos es: " << T.n_rasgos << endl;
	for(int i=0; i<T.n_rasgos; i++){
		os << T.Rs[i];
	}
	return os;
}
