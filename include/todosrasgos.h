//todosrasgos.h

#ifndef _todosrasgos_h_
#define _todosrasgos_h_
#include <iostream>
#include <cstring>
#include <rasgocomp.h>
#include <utilidades.h>

using namespace std;

class Todosrasgos {
	int n_rasgos;
	Rasgoc * Rs;
	public:
		/**
		@brief Constructor 
		*/
		Todosrasgos();
		/**
		@brief Destructor
		*/
		~Todosrasgos();
		/**
		@brief Constructor de copia
		*/
		Todosrasgos(const Todosrasgos &T);
		/**
		@brief Sobrecarga del operador =
		*/
		Todosrasgos & operator=(const Todosrasgos &T);
		/**
		@brief Devuelve el numero de rasgos
		*/
		int Numerorasgos(){return this->n_rasgos;}
		/**
		@brief Devuelve el rasgo n 
		*/
		Rasgoc ExtraeRasgo(int n){return this->Rs[n];}
		/**
		@brief Sobrecarga del operador >> 
		*/
		friend istream & operator>>(istream &is, Todosrasgos &T);
		/**
		@brief Sobrecarga del operador << 
		*/
		friend ostream &operator<<(ostream &os, Todosrasgos &T);
};
#endif