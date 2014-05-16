//cmarco.h

#ifndef _cmarco_h_
#define _cmarco_h_
#include <iostream>
#include <graficos.h>
#include <utilidades.h>

using namespace graficos;
using namespace std;

struct Color{
	unsigned int r, g, b;
};
/**
@brief Sobrecarga del operador >>
*/
istream & operator>>(istream &is, Color &C);
ostream & operator<<(ostream &os, Color &C);
class Marco{
	private:
		int x, y;
		int ancho, alto;
		Color fondo;
		int ancho_m, alto_m;
		Color marco;
	public:
		/**
		@brief Sobrecarga del operador >>
		*/
		friend istream & operator>>(istream &is, Marco &M);
		/**
		@brief Sobrecarga del operador << 
		*/
		friend ostream & operator<<(ostream &os, Marco &M);
		/**
		@brief Devuelve el valor de x 
		*/
		int Getx(){return x;}
		/**
		@brief Devuelve el valor de y 
		*/
		int Gety(){return y;}
		/**
		@brief Devuelve el valor de alto 
		*/
		int Getalto(){return alto;}
		/**
		@brief Devuelve el valor de ancho
		*/
		int Getancho(){return ancho;}
		/**
		@brief Devuelve el valor de alto_m
		*/
		int Getalto_m(){return alto_m;}
		/**
		@brief Devuelve el valor de ancho_m
		*/
		int Getancho_m(){return ancho_m;}
		/**
		@brief Devuelve la estructura color fondo 
		*/
		Color Getfondo(){return fondo;}
		/**
		@brief Devuelve la estructura color marco
		*/
		Color Getmarco(){return marco;}
		/**
		@brief Crea graficamente el marco dado por los elementos anteriores
		*/
		void Pinta();
};
#endif