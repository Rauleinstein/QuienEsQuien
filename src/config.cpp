#include <config.h>
#include <stdio.h>
#include <cmarco.h>
#include <iostream>
#include <graficos.h>
#include <cstring>
#include <cpersonajes.h>
#include <preguntas.h>
#include <cadena.h>
#include <tablero.h>

using namespace graficos;
using namespace std;


Config::Config(){
	fuente = 0;
	fuente_boton = 0;
	fuente_ter = 0;
	car_ocult = 0;
}

Config::~Config(){
	delete [] fuente;
	delete [] fuente_boton;
	delete [] fuente_ter;
	delete [] car_ocult;
}

istream &operator>>(istream &is, Config &C){
	QC(is);
	is >> C.vent_alto;
	is >> C.vent_ancho;
	QC(is);
	is >> C.nft; 
	is >> C.nct;
	QC(is);
	is >> C.sep_alto;
	is >> C.sep_ancho;
	QC(is);
	is >> C.tablero_humano;
	QC(is);
	is >> C.th_tachar;
	QC(is);
	is >> C.preguntas;
	QC(is);
	C.fuente = new char [200];
	is.getline(C.fuente, 200);
	while(strcmp(C.fuente, " ") == 0)
		is.getline(C.fuente, 200);
	QC(is);
	is >> C.pre_tam_fuente;
	QC(is);
	is >> C.pre_fuente;
	QC(is);
	is >> C.tablero_maquina;
	QC(is);
	is >> C.tm_tachar;
	QC(is);
	is >> C.jugardor1;
	QC(is);
	is >> C.jugador2;
	QC(is);
	is >> C.botones;
	QC(is);
	is >> C.tiempo;
	QC(is);
	is >> C.stop;
	QC(is);
	is >> C.conometro;
	QC(is);
	is >> C.restaurar;
	QC(is);
	is >> C.tiempo_pasado;
	QC(is);
	C.fuente_boton = new char [200];
	is.getline(C.fuente_boton, 200);
	while(strcmp(C.fuente_boton, " ") == 0)
		is.getline(C.fuente_boton, 200);
	QC(is);
	is >> C.tam_bot;
	QC(is);
	is >> C.fuente_c_boton;
	QC(is);
	is >> C.terminal;
	QC(is);
	C.fuente_ter = new char [200];
	is.getline(C.fuente_ter, 200);
	while(strcmp(C.fuente_ter, " ") == 0)
		is.getline(C.fuente_ter, 200);
	QC(is);
	is >> C.tam_fter;
	QC(is);
	is >> C.fuente_c_ter;
	QC(is);
	is >> C.lineas_ter;
	QC(is);
	C.car_ocult = new char [200];
	is.getline(C.car_ocult, 200);
	while(strcmp(C.car_ocult, " ") == 0)
		is.getline(C.car_ocult, 200);
	QC(is);
	is >> C.tiempo_espera;
	return is;
}
ostream &operator<<(ostream &os, Config &C){
	os << "Alto ancho";
	os << endl;
	os << C.vent_alto;
	os << " ";
	os << C.vent_ancho;
	os << endl;
	os << "filas columnas";
	os << endl;
	os << C.nft;
	os << " ";
	os << C.nct;
	os << endl;
	os << "Separadores";
	os << endl;
	os << C.sep_alto;
	os << " ";
	os << C.sep_ancho;
	os << endl;
	os << "Tablero Humano";
	os << endl;
	os << C.tablero_humano;
	os << " ";
	os << C.th_tachar;
	os << endl;
	os << "Preguntas";
	os << endl;
	os << C.preguntas;
	os << "La fuente de las preguntas" << endl;
	os << C.fuente;
	os << endl;
	os << C.pre_tam_fuente;
	os << " ";
	os << C.pre_fuente;
	os << endl;
	os << "Tablero maquina";
	os << endl;
	os << C.tablero_maquina;
	os << " ";
	os << C.tm_tachar;
	os << endl;
	os << "Jugador1";
	os << endl;
	os << C.jugardor1;
	os << endl;
	os << "Jugador2";
	os << endl;
	os << C.jugador2;
	os << endl;
	os << "BOTONERA";
	os << endl;
	os << C.botones;
	os << endl;
	os << "Tiempo";
	os << endl;
	os << C.tiempo;
	os << endl;
	os << "Stop";
	os << endl;
	os << C.stop;
	os << endl;
	os << "Cronometro";
	os << endl;
	os << C.conometro;
	os << endl;
	os << "Restaurar";
	os << endl;
	os << C.restaurar;
	os << C.tiempo_pasado;
	os << endl;
	os << "Fuente Botones";
	os << endl;
	os << C.fuente_boton;
	os << endl;
	os << C.tam_bot;
	os << " ";
	os << C.fuente_c_boton;
	os << "Terminal";
	os << endl;
	os << C.terminal;
	os << C.fuente_ter;
	os << endl;
	os << C.tam_fter;
	os << " ";
	os << C.fuente_c_ter;
	os << endl;
	os << C.lineas_ter;
	os << endl;
	os << "Caras ocultas";
	os << endl;
	os << C.car_ocult;
	os << endl;
	os << "Tiempo espera";
	os << endl;
	os << C.tiempo_espera;
	os << endl;
	return os;
}
void Config::PintaConfig(){
	tablero_humano.Pinta();
	preguntas.Pinta();
	tablero_maquina.Pinta();
	jugardor1.Pinta();
	jugador2.Pinta();
	botones.Pinta();
	tiempo.Pinta();
	stop.Pinta();
	conometro.Pinta();
	restaurar.Pinta();
	terminal.Pinta();
	GRF_Fuente fuen_boton, fuen_boton_neg;
	fuen_boton = CargarFuente(fuente_boton, tam_bot);
	int altotex, anchotex;
	char * STOP = new char [10];
	strcpy(STOP, "STOP");
	TamanoTexto(fuen_boton, STOP, anchotex, altotex);
	int x1 = (stop.Getx()+(stop.Getancho()/2)-(anchotex/2));
	int y1 = (stop.Gety()+((stop.Getalto()/2))-(altotex/2));
	EscribirTexto(x1, y1, STOP, fuen_boton, fuente_c_boton.r,fuente_c_boton.g,fuente_c_boton.b);
	char * RESTAURAR = new char [20];
	strcpy(RESTAURAR, "RESTAURAR");
	TamanoTexto(fuen_boton, RESTAURAR, anchotex, altotex);
	int x2 = (restaurar.Getx()+(restaurar.Getancho()/2)-(anchotex/2));
	int y2 = (restaurar.Gety()+((restaurar.Getalto()/2))-(altotex/2));///METER COLORES FUENTES!!!
	EscribirTexto(x2, y2, RESTAURAR, fuen_boton,fuente_c_boton.r,fuente_c_boton.g,fuente_c_boton.b);
	fuen_boton_neg = CargarFuente(fuente_boton, tam_bot, TTF_STYLE_BOLD);
	char * CRONOMETRO = new char [20];
	strcpy(CRONOMETRO, "CRONOMETRO");
	TamanoTexto(fuen_boton_neg, CRONOMETRO, anchotex, altotex);
	int x3 = (conometro.Getx()+(conometro.Getancho()/2)-(anchotex/2));
	int y3 = (conometro.Gety()+((conometro.Getalto()/2))-(altotex/2))-conometro.Getalto();
	EscribirTexto(x3, y3, CRONOMETRO, fuen_boton_neg, fuente_c_boton.r,fuente_c_boton.g,fuente_c_boton.b);

}

void Config::DibujaCaras(Tablero &T){
	GRF_Imagen jpg;
	for(int i=0; i<T.Filas(); i++){
		for(int j=0; j<T.Columnas(); j++){
			Personaje P = T.AccedePersonaje(i, j);
			jpg = LeerImagen(P.Ruta());
			int anchojpg = AnchoImagen(jpg);
			int altojpg = AltoImagen(jpg);
			int x = sep_ancho+(j*(anchojpg+sep_ancho));
			int y = sep_alto+(i*(altojpg+sep_alto));
			DibujarImagen(jpg, x, y);
		}
	}
}
void Config::DibujaCarasOcultas(char * img){
	GRF_Imagen jpg;
	int j=0, k=0;
	for(int i=0; i<(nct*nft); i++){
		jpg = LeerImagen(img);
		int anchojpg = AnchoImagen(jpg);
		int altojpg = AltoImagen(jpg);
		int x = (sep_ancho+(j*(anchojpg+sep_ancho))+tablero_maquina.Getx());
		int y = (sep_alto+(k*(altojpg+sep_alto)))+tablero_maquina.Gety();
		DibujarImagen(jpg, x, y);
		j++;
		if(j == nct){
			j=0;
			k++;
		}
	}
}
void Config::PintaOcultoJ1(Personaje P){
	GRF_Imagen jpg;
	jpg = LeerImagen(P.Ruta());
	int x = sep_ancho + jugardor1.Getx();
	int y = sep_alto + jugardor1.Gety();
	DibujarImagen(jpg, x, y);
}
void Config::DescubreOcultoJ2(Personaje P){
	GRF_Imagen jpg;
	jpg = LeerImagen(P.Ruta());
	int x = sep_ancho + jugador2.Getx();
	int y = sep_alto + jugador2.Gety();
	DibujarImagen(jpg, x, y);
}
void Config::PintaOcultoJ2(char * img){
	GRF_Imagen jpg;
	jpg = LeerImagen(img);
	int x = sep_ancho + jugador2.Getx();
	int y = sep_alto + jugador2.Gety();
	DibujarImagen(jpg, x, y);
}

void Config::PintaPreguntas(Preguntas &P){
	GRF_Fuente Fuen_preguntas;
	Fuen_preguntas = CargarFuente(fuente, pre_tam_fuente);
	int anchotex, altotex;
	TamanoTexto(Fuen_preguntas, "PREGUNTAS", anchotex, altotex);
	int x, y;
	x = preguntas.Getx()+(preguntas.Getancho()/2)-(anchotex/2);
	y = preguntas.Gety()+(altotex/2);
	EscribirTexto(x, y, "PREGUNTAS",Fuen_preguntas, pre_fuente.r, pre_fuente.g, pre_fuente.b);
	int altotexaux = altotex;
	for(int i=0; i<P.SacarRasgos(); i++){
		for(int j=0; j<P.SacarNumPreguntas(i); j++){
			TamanoTexto(Fuen_preguntas, P.SacarPreguntas(i,j), anchotex, altotex);
			x = preguntas.Getx()+5;
			y = preguntas.Gety()+(altotex+10)+(altotexaux);
			altotexaux = altotexaux + altotex;
			EscribirTexto(x, y, P.SacarPreguntas(i,j), Fuen_preguntas, pre_fuente.r, pre_fuente.g, pre_fuente.b);
		}
	}
}

int Config::Recogedatos(Preguntas &P){
	char *cad = new char[1];
	cad [0] = '\0';
	TTecla tec;
	do{
		tec = EsperarTecla();
		if(tec >=  SDLK_0 && SDLK_9 >= tec){
			Add(cad, '0' + (tec-SDLK_0));
		}
		if(tec == SDLK_BACKSPACE){
			Borrar(cad);
		}
	}while(tec != SDLK_RETURN);
	
	int numeropre = atoi(cad);
	numeropre = numeropre % P.SacarPreguntastot();
	delete [] cad;
	cad = new char[1];
	cad [0] = '\0';
	return numeropre;
}

void Config::PintaTerminal(char * cad, Cadenas &C){
	C.SetPal(C.Getocupadas()+1);
	C.AddCadena(cad);
	terminal.Pinta();
	int j=0;
	int n =0;
		if(C.GetPal() > lineas_ter)
			n= C.GetPal()-lineas_ter;
	GRF_Fuente Fuen_terminal;
	Fuen_terminal = CargarFuente(fuente_ter, tam_fter);
	for(int i=0; n<(C.GetPal()) && i<lineas_ter; i++){
		if(i==0)
			j=0;
		char * aux = new char [40];
		strcpy(aux, C.GetCadena(n));
		int anchotex, altotex, x, y;
		TamanoTexto(Fuen_terminal, aux, anchotex, altotex);
		x = terminal.Getx()+5;
		y = terminal.Gety()+5+(altotex*j);
		EscribirTexto(x,y, aux, Fuen_terminal, fuente_c_ter.r, fuente_c_ter.g, fuente_c_ter.b);
		j++;
		n++;
	}
}
int Config::EncuentraCoordenadas(int x, int y, int &i, int &j){
	GRF_Imagen jpg;
	jpg = LeerImagen(car_ocult);
	int anchojpg = AnchoImagen(jpg);
	int altojpg = AltoImagen(jpg);
	j = (x-sep_ancho)/(anchojpg+sep_ancho);
	i = (y-sep_alto)/(altojpg+sep_alto);
	if(x > stop.Getx() && x < (stop.Getx()+stop.Getancho()))
		if(y > stop.Gety() && y < (stop.Gety()+stop.Getalto()))
			return -1;
	if(x > restaurar.Getx() && x < (restaurar.Getx()+restaurar.Getancho()))
		if(y > restaurar.Gety() && y < (restaurar.Gety()+restaurar.Getalto()))
			return -2;
	if(i > nct-1 || j > nft-1){
		i = -1;
		j = -1;
		return -3;
	}
	return 0;
}

void Config::TacharPersonaje(int i, int j){
	GRF_Imagen jpg;
	jpg = LeerImagen(car_ocult);
	int anchojpg = AnchoImagen(jpg);
	int altojpg = AltoImagen(jpg);
	int x = sep_ancho+(j*(anchojpg+sep_ancho));
	int y = sep_alto+(i*(altojpg+sep_alto));
	RectanguloR(x, y, x+anchojpg, y+altojpg, th_tachar.r, th_tachar.g, th_tachar.b);
}

void Config::TacharPersonajeM(int i, int j){
	GRF_Imagen jpg;
	jpg = LeerImagen(car_ocult);
	int anchojpg = AnchoImagen(jpg);
	int altojpg = AltoImagen(jpg);
	int x = sep_ancho+(j*(anchojpg+sep_ancho))+tablero_maquina.Getx();
	int y = sep_alto+(i*(altojpg+sep_alto))+tablero_maquina.Gety();
	RectanguloR(x, y, x+anchojpg, y+altojpg, th_tachar.r, th_tachar.g, th_tachar.b);
}

void Config::PintaCrono(long int tiempo){
	int x = conometro.Getx()+sep_ancho;
	int y = conometro.Gety()+sep_alto;
	int ancho = conometro.Getancho();
	int alto = conometro.Getalto();
	double x2 = x+((ancho-(2*sep_ancho))*(tiempo/(tiempo_espera*1.0)));
	RectanguloR(x, y, x2, y+alto-(2*sep_alto), tiempo_pasado.r, tiempo_pasado.g, tiempo_pasado.b);
}
void Config::ReiniciaCrono(){
	int x = conometro.Getx()+sep_ancho;
	int y = conometro.Gety()+sep_alto;
	int ancho = conometro.Getancho();
	int alto = conometro.Getalto();
	RectanguloR(x, y, x+ancho-(2*sep_ancho), y+alto-(2*sep_alto), conometro.Getfondo().r, conometro.Getfondo().g, conometro.Getfondo().b);
}

void Config::PintaPuntuacion(int puntuacion){
	GRF_Fuente Fuente;
	Fuente = CargarFuente(fuente_boton, tam_bot);
	char * putuacion = new char [20];
	sprintf(putuacion, "%d", puntuacion);
	int anchotex, altotex;
	TamanoTexto(Fuente, putuacion, anchotex, altotex);
	int x = (tiempo.Getx()+(tiempo.Getancho()/2)-(anchotex/2));
	int y = (tiempo.Gety()+((tiempo.Getalto()/2))-(altotex/2));
	EscribirTexto(x, y, putuacion, Fuente, fuente_c_boton.r, fuente_c_boton.g, fuente_c_boton.b);
}
void Config::LimpiaPuntuacion(){
	int x = tiempo.Getx()+sep_ancho;
	int y = tiempo.Gety()+sep_alto;
	int ancho = tiempo.Getancho();
	int alto = tiempo.Getalto();
	RectanguloR(x, y, x+ancho-(2*sep_ancho), y+alto-(2*sep_alto), tiempo.Getfondo().r, tiempo.Getfondo().g, tiempo.Getfondo().b);
}