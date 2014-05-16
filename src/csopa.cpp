//csopa.cpp

#include <csopa.h>

using namespace std;


Sopa::Sopa(){//Constructor por defecto
    nf = 0;
    nc = 0;
    m = 0;
}

Sopa::Sopa(int nf, int nc){//Constructor por parametros
    this->nf = nf;
    this->nc = nc;
    m = new char * [nf];
    for(int i=0; i<nf; i++){
            m[i] = new char [nc];
    }
}
Sopa::~Sopa(){
    for(int i=0; i<nf; i++)
            delete [] m[i];
    delete [] m;
}
Sopa::Sopa(const Sopa &S){
     nf = S.nf;
     nc = S.nc;
     m = new char * [nf];
    for(int i=0; i<nf; i++){
            m[i] = new char [nc];
    }
    for(int i=0; i<nf; i++){
            for(int j=0; j<nc; j++){
                    m[i][j] = S.m[i][j];
            }
    }
}
Sopa & Sopa::operator=(const Sopa & S){
	if(this !=&S){
	for(int i=0; i<nf; i++){
		delete [] m[i];
	}
	delete []m;
	nf = S.nf; 
	nc = S.nc; 
	m = new char* [nf];
	for (int i=0; i<nf; i++){
		m[i] = new char [nc];
	}
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			m[i][j] = S.m[i][j];
		}
	}
	}
	return *this;
}
const char * Sopa::operator[](int i)const{
	return m[i];
}
char Sopa::operator()(int i, int j)const{
	return m[i][j];
}
istream & operator>>(istream &is, Sopa &S){
	int f, c;
	is >> f >> c;
	Sopa Saux(f, c);
	for(int i=0; i<Saux.nf; i++){
		for(int j=0; j<Saux.nc; j++){
			is>>Saux.m[i][j];
		}
	}
	S = Saux;
	return is;
}
ostream & operator<<(ostream &os,const Sopa &S){
	os << S.nf << " " << S.nc << endl;
	for(int i=0; i<S.nf; i++){
		for(int j=0; j<S.nc; j++){
			os << S.m[i][j] << " " ;
		}
		os << endl;
	}
	return os;
}

