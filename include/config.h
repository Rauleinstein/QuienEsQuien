#ifndef _config_h_
#define _config_h_
#include <iostream>
#include <cmarco.h>
#include <graficos.h>
#include <cpersonajes.h>
#include <preguntas.h>
#include <stdio.h>
#include <cadena.h>
#include <config.h>
#include <cmarco.h>
#include <cstring>
#include <tablero.h>

using namespace graficos;
using namespace std;


class Config{
	public:
	///Opciones Generales
	int vent_alto, vent_ancho;
	int nft, nct;
	int sep_alto, sep_ancho;
	///Tablero Humano
	Marco tablero_humano;
	Color th_tachar;
	///Parte Preguntas
	Marco preguntas;
	char * fuente;
	int pre_tam_fuente;
	Color pre_fuente;
	///Tablero Maquina
	Marco tablero_maquina;
	Color tm_tachar;
	/*Personajes Ocultos*/
	///Jugador1
	Marco jugardor1;
	///Jugador2
	Marco jugador2;
	///Recuadro de botones
	Marco botones;
	///Tiempo acumulado
	Marco tiempo;
	///Boton STOP
	Marco stop;
	///Conometro
	Marco conometro;
	///Cuadro restaurar
	Marco restaurar;
	Color tiempo_pasado;
	///Fuente Botones
	char * fuente_boton;
	int tam_bot;
	Color fuente_c_boton;
	///Terminal
	Marco terminal;
	char * fuente_ter;
	int tam_fter;
	Color fuente_c_ter;
	int lineas_ter;
	///caras ocultas
	char * car_ocult;
	///tiempo
	int tiempo_espera;
	//FUNCIONES
	/**
	@brief Constructor
	*/
	Config();
	/**
	@brief Destructor 
	*/
	~Config();
	/**
	@brief Sobrecarga del operador >> 
	*/
	friend istream & operator>>(istream &is, Config & C);
	/**
	@brief Sobrecarga del operador << 
	*/
	friend ostream & operator<<(ostream &os, Config &C);
	/**
	@brief Devuelve el valor de nft
	*/
	int Filas(){return nft;}
	/**
	@brief Devuelve el valor de nct
	*/
	int Columnas(){return nct;}
	/**
	@brief Dibuja graficamente toda la configuración
	*/
	void PintaConfig();
	/**
	@brief Dibuja graficamente todas las caras que estan en el tablero
	@param T Se le pasa un Tablero
	*/
	void DibujaCaras(Tablero &T);
	/**
	@brief Dibuja las Caras ocultas del tablero de la maquina 
	*/
	void DibujaCarasOcultas(char * img);
	/**
	@brief Dibuja el Personaje del Jugador1
	*/
	void PintaOcultoJ1(Personaje P);
	/**
	@brief Descubre el Personaje oculto de la Maquina 
	*/
	void DescubreOcultoJ2(Personaje P);
	/**
	@brief Dibuja el Personaje Oculto de la Maquina
	*/
	void PintaOcultoJ2(char * img);
	/**
	@brief Dibuja en el entorno grafico todas las Preguntas
	*/
	void PintaPreguntas(Preguntas &P);
	/**
	@brief Recoge por teclado todos los datos 
	*/
	int Recogedatos(Preguntas &P);
	/**
	@brief Escribe la cadena cad en el terminal
	@param cad cadena que queremos escribir en el terminal
	@param C Buffer donde almacenamos la conversacion
	*/
	void PintaTerminal(char * cad, Cadenas &C);
	/**
	@brief Pasando unas coordenadas de raton devuelve unas coordenadas de matriz
	@return 0 si ha encontrado en matriz
	@return -1 si ha pinchado en el boton stop
	@return -2 si ha pinchado en el boton RESTAURAR
	@return -3 si no ha pinchado en los anteriores
	*/
	int EncuentraCoordenadas(int x, int y, int &i, int &j);
	/**
	@brief Tacha personaje i, j del tablero humano 
	*/
	void TacharPersonaje(int i, int j);
	/**
	@brief Tacha personaje i, j del tablero maquina 
	*/
	void TacharPersonajeM(int i, int j);
	/**
	@brief Pinta el Cronometro segun el tiempo dado
	@param tiempo El tiempo que CronometroValor da 
	*/
	void PintaCrono(long int tiempo);
	/**
	@brief Devuelve el tiempo_espera
	*/
	int TiempoEspera(){return tiempo_espera;}
	/**
	@brief Repinta el cronometro  
	*/
	void ReiniciaCrono();
	/**
	@brief Pinta la Puntuacion que se le pasa por parametros
	@param tiempo es el tiempo que se le pasa para pintar el cronometro
	*/
	void PintaPuntuacion(int puntuacion);
	/**
	@brief Limpia la puntuacion para evitar sobreescrituras
	*/
	void LimpiaPuntuacion();
	/**
	@brief Devuelve el ancho de la ventana
	*/
	int Ventancho(){return vent_ancho;}
	/**
	@brief Devuelve el alto de la ventana
	*/
	int Ventalto(){return vent_alto;}
};

#endif