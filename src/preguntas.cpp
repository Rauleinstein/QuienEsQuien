//preguntas.cpp

#include <preguntas.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>

using namespace std;

Preguntas::Preguntas(){
}

Preguntas Preguntas::CrearPreguntas(Todosrasgos &T){
	n_rasgos_pre = T.Numerorasgos();
	char * pregunta;
	char * aux;
	int numeropre = 0;
	preguntas = new Cadenas [n_rasgos_pre];
	Cadenas * Caux = new Cadenas [n_rasgos_pre];
	for(int n=0; n<n_rasgos_pre; n++){
		int rasgostot = 1;
		Rasgoc Raux = T.ExtraeRasgo(n);
		pregunta = Raux.ExtraePregunta();
		aux = new char [strlen(pregunta)];
		strcpy(aux, pregunta);
		strtok(aux, "*");
		char * aux2 = strstr(pregunta, "*");
		if(aux2!=0){
			for(int j=0; j<Raux.ExtraePal(); j++){
				Caux[n].SetPal(Raux.ExtraePal());
				aux = new char [strlen(pregunta)];
				strcpy(aux, pregunta);
				strtok(aux, "*");
				strcat(aux, Raux.ExtraeRasgo(j));
				char * aux2 = strstr(pregunta, "*");
				aux2++;
				strcat(aux, aux2);
				char * aux3 = new char [40];
				sprintf(aux3, "%d", numeropre);
				strcat(aux3, ".-");
				strcat(aux3, aux);
				Caux[n].AddCadena(aux3);
				rasgostot++;
				numeropre++;
			}
		}
		else{
			Caux[n].SetPal(1);
			char * aux3 = new char [40];
			sprintf(aux3, "%d", numeropre);
			strcat(aux3, ".-");
			strcat(aux3, pregunta);
			Caux[n].AddCadena(aux3);
			numeropre++;
		}
		preguntas[n] = Caux[n];
	}
	preguntastot = numeropre;
}

char * Preguntas::BuscaPreguntas(int numeropre){
	char * auxnumpre = new char [40];
	char * aux = new char [40];
	sprintf(auxnumpre, "%d", numeropre);
	for(int i=0; i<n_rasgos_pre; i++){
		for(int j=0; j<preguntas[i].GetPal(); j++){
			aux = preguntas[i].GetCadena(j);
			if(strstr(aux, auxnumpre) !=0){
				if(numeropre < 10)
					aux = aux+3;
				else
					aux = aux+4;
				return aux;
			}
		}
	}
	return aux;
}

ostream &operator<<(ostream &os, Preguntas &P){
	for(int i=0; i<P.n_rasgos_pre; i++){
		os << P.preguntas[i];
	}
	return os;
}
char * Preguntas::SacarPreguntas(int i, int j){
	
	char *aux=new char[strlen(preguntas[i].GetCadena(j))+1];
	strcpy(aux, preguntas[i].GetCadena(j));
	return aux;
}