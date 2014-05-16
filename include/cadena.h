/**
  * @file cadenas.h
  * @brief Fichero cabecera para la gestión de Cadenas
  *
  *Sirve para poder usar Cadenas 
  *
  */

#ifndef _cadena_h_
#define _cadena_h_
#include <iostream>
#include <cstring>
#include <utilidades.h>

using namespace std;
/**
@class Cadenas Sirve para guardar Conjutos de cadenas

*/
class Cadenas {
	char **cad;
	int palabras, ocupadas;
	public:
		/**
		@brief Constructor
		*/
		Cadenas();
		/**
		@brief Constructor con parametros
		*/
		Cadenas(int n);
		/**
		@brief Constructor de copia
		*/
		Cadenas(const Cadenas&C);
		/**
		@brief Destructor
		*/
		~Cadenas();
		/**
		@brief Añade una cadena a una Cadenas ya construida
		@param cad Cadena que se va a añadir
		*/
		void AddCadena(const char * cad);
		/**
		@brief Pone el numero de palabras a p
		@param p el int que queremos que tenga palabras
		*/
		void SetPal(int p){palabras = p;}
		/**
		@brief Devuelve el numero de palabras 
		*/
		int GetPal(){return palabras;}
		/**
		@brief Devuelve el numero de palabras ocupadas
		*/
		int Getocupadas(){return ocupadas;}
		/**
		@brief Devuelve la cadena de la posicion i
		@param i posicion a la que queremos acceder
		*/
		char * GetCadena(int i);
		/**
		@brief Sobrecarga del operator >>
		*/
		friend istream &operator>>(istream &is, Cadenas &C);
		/**
		@brief Sobrecarga del operator << 
		*/
		friend ostream &operator<<(ostream &os, Cadenas &C);
		/**
		@brief Sobrecarga del operator = 
		*/
		Cadenas& operator=(const Cadenas &C);
};

#endif 