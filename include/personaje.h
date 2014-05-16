#ifndef _personaje_h_
#define _personaje_h_
#include <ccrasgos.h>
#include <iostream>
#include <cstring>
#include <utilidades.h>

using namespace std;

class Personaje{
	char * nombre;
	char * ruta;
	CRasgos rasgos;
	public:
		/**
		@brief Constructor
		*/
		Personaje();
		/**
		@brief Destructor
		*/
		~Personaje();
		/**
		@brief Constructor de copia
		*/
		Personaje(const Personaje &P);
		/**
		@brief Sobrecarga del operador >> 
		*/
		friend istream &operator>>(istream &is, Personaje &P);
		/**
		@brief Sobrecarga del operador <<
		*/
		friend ostream &operator<<(ostream &os, const Personaje * &O);
		/**
		@brief Sobrecarga del operador =
		*/
		Personaje &operator=(const Personaje &P);
		/**
		@brief Devuelve la ruta
		*/
		char * Ruta();
		/**
		@brief Devuelve los rasgos del personaje
		*/
		CRasgos SacaRasgos(){return rasgos;}
		/**
		@brief Devuelve la respuesta del personaje a una pregunta
		*/
		bool Respuesta(char * pregunta_selec);
};

#endif