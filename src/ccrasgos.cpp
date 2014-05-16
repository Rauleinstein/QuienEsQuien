#include <ccrasgos.h>
#include <iostream>
#include <cstring>

using namespace std;

CRasgos::CRasgos(){
	nrasgos = 0;
}

CRasgos::~CRasgos(){
	nrasgos = 0;
}
CRasgos::CRasgos(const CRasgos &Cop){
	nrasgos = Cop.nrasgos;
	CR = new Rasgo [nrasgos];
	for(int i=0; i<nrasgos; i++){
		CR[i] = Cop.CR[i];
	}
}
void CRasgos::MeterRasgo(Rasgo * R){
	Rasgo * aux = new Rasgo [nrasgos +1];
	for(int i=0; i<nrasgos; i++){
		aux[i] = CR[i];
	}
	aux[nrasgos+1] = R[nrasgos+1];
}
istream &operator>>(istream &is, CRasgos & C){
	QC(is);
	is >> C.nrasgos;
	C.CR = new Rasgo [C.nrasgos];
	for(int i=0; i<C.nrasgos; i++){
		QC(is);
		is >> C.CR[i];
	}
	return is;
}
ostream &operator<<(ostream &os, const CRasgos & C){
	os << "El numero de rasgos es: " << C.nrasgos << endl;
	os << "Los rasgos son:"<< endl;
	for(int i=0; i<C.nrasgos; i++){
		os << C.CR[i] << endl;
	}
	return os;
}
CRasgos & CRasgos::operator=(const CRasgos &C){
	if(this != &C){
		nrasgos = C.nrasgos;
		CR = new Rasgo [nrasgos];
		for(int i=0; i<nrasgos; i++){
			CR[i] = C.CR[i];
			
		}
	}
	return *this;
}