#ifndef _crasgo_h_
#define _crasgo_h_
#include <iostream>
#include <cstring>


using namespace std;

class Rasgo{
	char * tipo;
	char * valor;
	public:
		/**
		@brief Constructor 
		*/
		Rasgo();
		/**
		@brief Constructor por parametros
		*/
		Rasgo(char *tipo, char *valor);
		/**
		@brief Destructor
		*/
		~Rasgo();
		/**
		@brief Sobrecarga del operador =
		*/
		Rasgo & operator=(const Rasgo &R);
		/**
		@brief Devuelve el tipo
		*/
		char * DevuelveTipo();
		/**
		@brief Devuelve el valor 
		*/
		char * DevuelveValor();
		/**
		@brief Sobrecarga del operador >>
		*/
		friend istream & operator>>(istream &is, Rasgo &R);
		/**
		@brief Sobrecarga del operador << 
		*/
		friend ostream & operator<<(ostream &os, const Rasgo &R);
};

#endif