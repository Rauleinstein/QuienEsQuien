
#include <cpersonajes.h>
#include <graficos.h>

using namespace graficos;
using namespace std;

CPersonajes::CPersonajes(){
	n_personajes = 0;
}
CPersonajes::~CPersonajes(){
	delete [] P;
}
CPersonajes::CPersonajes(const CPersonajes &CP){
	n_personajes = CP.n_personajes;
	for(int i=0; i<n_personajes; i++){
		P[i] = CP.P[i];
	}
}
istream &operator>>(istream &is, CPersonajes &CP){
	QC(is);
	is >> CP.n_personajes;
	QC(is);
	CP.P = new Personaje [CP.n_personajes];
	for(int i=0; i<CP.n_personajes; i++){
		QC(is);
		is >> CP.P[i];
	}
	
	return is;
}
ostream &operator<<(ostream &os, CPersonajes &CP){
	os << "El numero de personajes es: " << CP.n_personajes << endl;
	for(int i=0; i<CP.n_personajes; i++){
		os << &CP.P[i];
	}
	return os;
}
Personaje CPersonajes::AccedePersonaje(int n){
	return P[n];
}
CPersonajes & CPersonajes::operator=(const CPersonajes & CP){
	if(this != &CP){
		delete [] P;
		n_personajes = CP.n_personajes;
		for(int i=0; i<n_personajes; i++){
			P[i] = CP.P[i];
		}
	}
	return *this;
}
CPersonajes & CPersonajes::EliminaPersonaje(int n){
	CPersonajes Caux;
	Caux.n_personajes = n_personajes-1;
	for(int i=0; i<n_personajes; i++){
		if(i < n)
			Caux.P[i] = P[i];
		if(i > n)
			Caux.P[i-1] = P[i];
	}
}
