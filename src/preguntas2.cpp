//preguntas.cpp

#include <preguntas.h>
#include <iostream>
#include <cstring>

using namespace std;

Preguntas::Preguntas(){
	hechas = 0;
}
Preguntas Preguntas::CrearPreguntas(Todosrasgos &T){
	n_rasgos_pre = T.Numerorasgos();
	char * pregunta;
	char * aux;
	preguntas = new Cadenas [n_rasgos_pre];
	for(int n=0; n<n_rasgos_pre; n++){
		Cadenas Caux;
		int rasgostot = 1;
		cout << Caux;
		Rasgoc Raux = T.ExtraeRasgo(n);
		pregunta = Raux.ExtraePregunta();
		aux = new char [strlen(pregunta)];
		strcpy(aux, pregunta);
		strtok(aux, "*");
		cout << aux << endl;
		if(aux!=0){
			for(int j=0; j<Raux.ExtraePal(); j++){
				Caux.SetPal(Raux.ExtraePal());
				aux = new char [strlen(pregunta)];
				strcpy(aux, pregunta);
				strtok(aux, "*");
				strcat(aux, Raux.ExtraeRasgo(j));
				char * aux2 = strstr(pregunta, "*");
				aux2++;
				strcat(aux, aux2);
				cout << aux;
				Caux.AddCadena(aux);
				cout << Caux;
				rasgostot++;
			}
		}
		else{
			Caux.SetPal(rasgostot);
			Caux.AddCadena(pregunta);
			rasgostot++;
		}
		preguntas[n] = Caux;
		cout << preguntas[n];
	}
//	hechas = new bool [Caux.GetPal()];
//	for(int i=0; i<Caux.GetPal(); i++)
//		hechas[i] = false;
}

ostream &operator<<(ostream &os, Preguntas &P){
	os << P.preguntas;
	return os;
}