#ifndef _tablero_h_
#define _tablero_h_

#include <iostream>
#include <cpersonajes.h>
#include <personaje.h>
#include <cstring>
#include <cstdio>
#include <stdlib.h>

using namespace std;

class Tablero {
	int nf, nc;
	Personaje ** MatrixP;
	bool ** SN;
	public:
		/**
		@brief Constructor
		*/
		Tablero();
		/**
		@brief Destructor
		*/
		~Tablero();
		/**
		@brief Constructor por parametros
		*/
		Tablero(int cols, int fils, CPersonajes &CP);
		/**
		@brief Devuelve en numero de filas
		*/
		int Filas(){return nf;}
		/**
		@brief Devuelve el numero de columnas
		*/
		int Columnas(){return nc;}
		/**
		@brief Devuelve el personaje i , j 
		*/
		Personaje AccedePersonaje(int i, int j);
		/**
		@brief Pone a false el booleano del personaje i, j
		*/
		void Tacha(int i, int j);
		/**
		@brief Pone a true el booleano del personaje i, j
		*/
		void DesTacha(int i, int j);
		/**
		@brief Comprueba si queda solo 1 personaje por tachar  
		*/
		bool ComprGanador(int &x, int &y);
};

#endif