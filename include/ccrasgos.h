#ifndef _ccrasgos_h_
#define _ccrasgos_h_
#include <crasgo.h>
#include <iostream>
#include <utilidades.h>

using namespace std;

class CRasgos{
	Rasgo * CR;
	int nrasgos;
	public:
		/**
		@brief Constructor por defecto
		*/
		CRasgos();
		/**
		@brief Destructor 
		*/
		~CRasgos();
		/**
		@brief Constructor de copia 
		*/
		CRasgos(const CRasgos &Cop);
		/**
		@brief Inserta el Rasgo R en el conjunto de rasgos
		@param R rasgo que le pasamos para que lo meta
		*/
		void MeterRasgo(Rasgo * R);
		/**
		@brief Devuelve el numero de rasgos
		*/
		int Nrasgos(){return nrasgos;}
		/**
		@brief Devuelve el Rasgo dado por el int n
		@param n para saber el rasgo que queremos
		*/
		const Rasgo SacarRasgo(int n){return CR[n];}
		/**
		@brief Sobrecarga del operador >>
		*/
		friend istream &operator>>(istream &is, CRasgos & C);
		/**
		@brief Sobrecarga del operador << 
		*/
		friend ostream &operator<<(ostream &os, const CRasgos & C);
		/**
		@brief Sobrecarga del operador = 
		*/
		CRasgos & operator=(const CRasgos &C);
};

#endif
