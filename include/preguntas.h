//Preguntas.h

#ifndef _preguntas_h_
#define _preguntas_h_

#include <iostream>
#include <cadena.h>
#include <todosrasgos.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Preguntas{
	int n_rasgos_pre, preguntastot;
	Cadenas * preguntas;
	public:
		/**
		@brief Constructor
		*/
		Preguntas();
		/**
		@brief Crea las preguntas a partir de todos los rasgos
		*/
		Preguntas CrearPreguntas(Todosrasgos &T);
		/**
		@brief Devuelve el numero de rasgos
		*/
		int SacarRasgos(){return this->n_rasgos_pre;}
		/**
		@brief Devuelve el numero de preguntas totales
		*/
		int SacarPreguntastot(){return this->preguntastot;}
		/**
		@brief Devuelve la pregunta i, j
		*/
		char * SacarPreguntas(int i, int j);
		/**
		@brief Devuelve el numero de preguntas de i 
		*/
		int SacarNumPreguntas(int i){return this->preguntas[i].GetPal();}
		/**
		@brief Sobrecarga del operador <<
		*/
		friend ostream &operator<<(ostream &os, Preguntas &P);
		/**
		@brief Devuelve la pregunta dada por el numero
		*/
		char * BuscaPreguntas(int numeropre);
};

#endif