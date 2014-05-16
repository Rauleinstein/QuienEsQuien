//main.cpp


#include <iostream>
#include <fstream>
#include <config.h>
#include <graficos.h>
#include <cpersonajes.h>
#include <personaje.h>
#include <todosrasgos.h>
#include <preguntas.h>
#include <utilidades.h>
#include <terminal.h>
#include <tablero.h>

using namespace graficos;
using namespace std;

int main(int argc, char * argv[]){
	if(argc != 2){
		cerr << "Dame un nombre de archivo" << endl;
		return 0;
	}
	ifstream f;
	f.open(argv[1]);
	Todosrasgos RT;
	Personaje POcultoJ1;
	Personaje POcultoJ2;
	CPersonajes CP;
	Config C;
	Cadenas Buffer;
	int numeropre;
	char * SI = new char [4];
	char * NO = new char [4];
	strcpy(SI, "Si");
	strcpy(NO, "No");
	char * JSI = new char [20];
	char * JNO = new char [20];
	JSI = ConcatenarJugador(SI);
	JNO = ConcatenarJugador(NO);
	char * MSI = new char [20];
	char * MNO = new char [20];
	MSI = ConcatenarMaquina(SI);
	MNO = ConcatenarMaquina(NO);
	f >> RT;
	f >> CP;
	f >> C;
	Preguntas P;
	P.CrearPreguntas(RT);
	srand(time(NULL));
	int random1 = rand() % CP.Numeroper();
	POcultoJ1 = CP.AccedePersonaje(random1);//Guarda el Personaje Oculto
	int random2 = rand() % CP.Numeroper();
	POcultoJ2 = CP.AccedePersonaje(random2);
	CrearVentana(C.Ventalto()+1, C.Ventancho()+1, "Quien es Quien");
	C.PintaConfig();
	Tablero TJugador(C.Filas(), C.Columnas(), CP);
	Tablero TMaquina(C.Filas(), C.Columnas(), CP);
	C.DibujaCaras(TJugador);
	for(int m=0; m<C.Filas(); m++){
		for(int b=0; b<C.Columnas(); b++){
			TJugador.DesTacha(m,b);
		}
	}
	for(int m=0; m<C.Filas(); m++){
		for(int b=0; b<C.Columnas(); b++){
			TMaquina.DesTacha(m,b);
			}
		}
	C.DibujaCarasOcultas(C.car_ocult);
	C.PintaOcultoJ1(POcultoJ1);
	C.PintaOcultoJ2(C.car_ocult);
	C.PintaPreguntas(P);
	
	
	///PARTE JUEGO!!!
	int iwin, jwin, puntuacion = 0, puntuaciontot = 0;
	for(int z=0; !TJugador.ComprGanador(iwin, jwin); z++){
		POcultoJ1 = CP.AccedePersonaje(random1);
		POcultoJ2 = CP.AccedePersonaje(random2);
		numeropre = C.Recogedatos(P);
		char * pregunta_selec = new char [40];
		pregunta_selec = P.BuscaPreguntas(numeropre);
		bool respuesta = POcultoJ2.Respuesta(pregunta_selec);
		pregunta_selec = ConcatenarJugador(pregunta_selec);
		C.PintaTerminal(pregunta_selec, Buffer);
		if(respuesta){
			C.PintaTerminal(MSI, Buffer);
		}
		else{
			C.PintaTerminal(MNO, Buffer);
		}
		
		int x, y, i, j;
		CronometroInicio();
		int raton1=0;
		while(raton1 != -1){
			C.PintaCrono(CronometroValor());
			if(ConsultarRaton(x, y) == SDL_BUTTON_LEFT)
				raton1 = C.EncuentraCoordenadas(x, y, i, j);
			else
				raton1 = 1;
			if(raton1 == -2){
				C.DibujaCaras(TJugador);
				for(int m=0; m<C.Filas(); m++){
					for(int b=0; b<C.Columnas(); b++){
						TJugador.DesTacha(m,b);
					}
				}
			}
			if(raton1 == 0){
				C.TacharPersonaje(i,j);
				TJugador.Tacha(i,j);
			}
			int tiempo = CronometroValor();
			if(tiempo > C.TiempoEspera())
				raton1 = -1;
		}
		int tiempo1 = CronometroValor();
		int tiempoesp = C.TiempoEspera();
		puntuaciontot = puntuaciontot + tiempo1;
		C.LimpiaPuntuacion();  
		C.PintaPuntuacion(puntuaciontot);
		bool Ganar2 = TJugador.ComprGanador(iwin, jwin);
		if(Ganar2){
			Personaje Pganador = TJugador.AccedePersonaje(iwin, jwin);
			if(strcmp(Pganador.Ruta(), POcultoJ2.Ruta()) == 0){
				C.PintaTerminal("JUGADOR HA GANADO!", Buffer);
				C.DescubreOcultoJ2(POcultoJ2);
				EsperarTecla();
				return 0;
			}
		}
		C.ReiniciaCrono();
		char * pregunta_selec2 = new char [40];
		//P.CrearPreguntas(RT);
		pregunta_selec2 = P.BuscaPreguntas(rand() % P.SacarPreguntastot());
		while(pregunta_selec2 == 0){
			pregunta_selec2 = P.BuscaPreguntas(rand() % P.SacarPreguntastot());
		}
		bool respuesta2 = POcultoJ1.Respuesta(pregunta_selec2);
		pregunta_selec2 = ConcatenarMaquina(pregunta_selec2);
		C.PintaTerminal(pregunta_selec2, Buffer);
		if(respuesta2){
			C.PintaTerminal(JSI, Buffer);
		}
		else{
			C.PintaTerminal(JNO, Buffer);
		}
		//Tacha Maquina
		for(int i=0; i<C.Filas(); i++){
			for(int j=0; j<C.Columnas(); j++){
				Personaje Ptacha = TMaquina.AccedePersonaje(i,j);
				bool respuesta3 = Ptacha.Respuesta(pregunta_selec2);
				if(respuesta3 != respuesta2){
					TMaquina.Tacha(i, j);
					C.TacharPersonajeM(i,j);
				}
			}
		}
		bool Ganar = false;
		Ganar = TMaquina.ComprGanador(iwin, jwin);
		if(Ganar == true){
			Personaje Pganador = TMaquina.AccedePersonaje(iwin, jwin);
			if(strcmp(Pganador.Ruta(), POcultoJ1.Ruta()) == 0){
				C.PintaTerminal("MAQUINA HA GANADO!", Buffer);
				C.DescubreOcultoJ2(POcultoJ2);
				EsperarTecla();
				return 0;
			}
			
		}
	}
	f.close();
}
