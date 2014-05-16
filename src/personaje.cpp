#include <personaje.h>
#include <cstring>


using namespace std;

Personaje::Personaje(){
	nombre = 0;
	ruta = 0;
}
Personaje::~Personaje(){
	delete [] nombre;
	delete [] ruta;
}
Personaje::Personaje(const Personaje &P){
	nombre = new char [strlen(P.nombre)+1];
	strcpy(nombre, P.nombre);
	ruta = new char [strlen(P.ruta)+1];
	strcpy(ruta, P.ruta);
	rasgos = P.rasgos;
}
istream &operator>>(istream &is, Personaje &P){
	QC(is);
	P.nombre = new char [80];
	is.getline(P.nombre, 80);
	LC(P.nombre);
	QC(is);
	P.ruta = new char [80];
	is.getline(P.ruta, 80);
	LC(P.ruta);
	while(strcmp(P.ruta, " ") == 0)
		is.getline(P.ruta, 80);
	QC(is);
	is >> P.rasgos;
	return is;
}
ostream &operator<<(ostream &os, const Personaje *&O){
	os << "Datos del personaje" << endl;
	os << "Nombre: " << O->nombre << endl;
	os << "Ruta de la imagen: " << O->ruta << endl;
	os << O->rasgos << endl;
	return os;
}

Personaje & Personaje::operator=(const Personaje &P){
	if(this != &P){
		delete [] nombre;
		delete [] ruta;
		nombre = new char [strlen(P.nombre)+1];
		strcpy(nombre, P.nombre);
		ruta = new char [strlen(P.ruta)+1];
		strcpy(ruta, P.ruta);
		rasgos = P.rasgos;
	}
	return *this;
}
bool Personaje::Respuesta(char * pregunta_selec){
	for(int i=0; i<rasgos.Nrasgos(); i++){
		Rasgo rasgo = rasgos.SacarRasgo(i);
		char * tipo = new char [200];
		strcpy(tipo, rasgo.DevuelveTipo());
		tipo++;
		if(strstr(pregunta_selec, tipo) !=0){
			cout << rasgo.DevuelveValor();
			if(strstr(rasgo.DevuelveValor(), "i") !=0)
				return true;
			else
				return false;
		}
		if(strstr(pregunta_selec, rasgo.DevuelveValor()) !=0){
			return true;
		}
	}
	return false;
}
char * Personaje::Ruta(){
	
	char *aux=new char[strlen(ruta)+1];
	strcpy(aux, ruta);
	return aux;
}
