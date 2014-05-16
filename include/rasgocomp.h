#ifndef _rasgocomp_h_
#define _rasgocomp_h_
#include <iostream>
#include <cstring>
#include <cadena.h>
#include <utilidades.h>

using namespace std;

class Rasgoc{
	char * nombrerasgo;
	char * preguntagener;
	Cadenas C;
	public:
		/**
		@brief Constructor 
		*/
		Rasgoc();
		/**
		@brief Destructor
		*/
		~Rasgoc();
		/**
		@brief Constructor de copia
		*/
		Rasgoc(const Rasgoc &R);
		/**
		@brief Sobrecarga de operador = 
		*/
		Rasgoc operator=(const Rasgoc &R);
		/**
		@brief Devuelve la pregunta generica 
		*/
		char * ExtraePregunta();
		/**
		@brief Devuelve el rasgo n
		*/
		char * ExtraeRasgo(int n);
		/**
		@brief Devuelve el numero de rasgos 
		*/
		int ExtraePal(){return this->C.GetPal();}
		/**
		@brief Sobrecarga del operador >>
		*/
		friend istream &operator>>(istream &is, Rasgoc &Rc);
		/**
		@brief Sobrecarga del operador << 
		*/
		friend ostream &operator<<(ostream &os, Rasgoc &Rc);
};

#endif