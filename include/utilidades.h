//Utilidades.h
#ifndef _utilidades_h_
#define _utilidades_h_

#include <iostream>
#include <cstring>

using namespace std;

/**
@brief Quita espacios del flujo istream 
*/
void QE(istream &is);
/**
@brief Quita comentarios del flujo istream
*/
void QC(istream &is);
/**
@brief Limpia comentarios del la cadena  
*/
void LC(char *cadena);
/**
@brief Añade el char c a la cadena
*/
void Add(char * &cad, char c);
/**
@brief Borra el ultimo caracter de la cadena cad 
*/
void Borrar(char * &cad);
/**
@brief Le introduce un "Humano > " a la cadena cad
*/
char * ConcatenarJugador(char * cad);
/**
@brief Le introduce un "Maquina > " a la cadena cad
*/
char * ConcatenarMaquina(char * cad);

#endif