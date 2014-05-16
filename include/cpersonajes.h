#ifndef _cpersonajes_h_
#define _cpersonajes_h_
#include <personaje.h>
#include <iostream>
#include <cstring>
#include <utilidades.h>

using namespace std;

class CPersonajes{
	int n_personajes;
	Personaje * P;
	public:
		/**
		@brief Constructor
		*/
		CPersonajes();
		/**
		@brief Destructor
		*/
		~CPersonajes();
		/**
		@brief Constructor de copia 
		*/
		CPersonajes(const CPersonajes &CP);
		/**
		@brief Sobrecarga del operador >> 
		*/
		friend istream &operator>>(istream &is, CPersonajes &CP);
		/**
		@brief Sobrecarga del operador <<
		*/
		friend ostream &operator<<(ostream &os, CPersonajes &CP);
		/**
		@brief Devuelve el personaje n
		*/
		Personaje AccedePersonaje(int n);
		/**
		@brief Elimina el personaje n
		*/
		CPersonajes &EliminaPersonaje(int n);
		/**
		@brief Sobrecarga del operador = 
		*/
		CPersonajes & operator=(const CPersonajes & CP);
		/**
		@brief Devuelve el numero de personajes 
		*/
		int Numeroper(){return n_personajes;}
};

#endif