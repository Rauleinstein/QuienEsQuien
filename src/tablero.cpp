#include <tablero.h>

using namespace std;

Tablero::Tablero(){
	nf = 0;
	nc = 0;
	MatrixP = 0;
	SN = 0;
}
Tablero::~Tablero(){
	for (int i=0; i<nf; i++){
		delete [] MatrixP[i];
		delete [] SN[i];
	}
	delete [] MatrixP;
	delete [] SN;
}
Tablero::Tablero(int cols, int fils, CPersonajes &CP){
	nc = cols; 
	nf = fils;
	MatrixP = new Personaje * [nf];
	SN = new bool *[nf];
	for(int i=0; i<nf; i++){
		MatrixP[i] = new Personaje [nc];
		SN[i] = new bool [nc];
	}
	srand(time(NULL));
	int * numeros = new int [CP.Numeroper()];
	for(int i=0; i<CP.Numeroper(); i++){
		numeros[i] = -1;
	}
	bool esta = false;
	int n, controla=0;
	for (int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			do{
				esta = false;
				n= rand() % (CP.Numeroper());
				for(int h=0; h<CP.Numeroper(); h++){
					if(n == numeros[h]){
						esta = true;
					}
				}
			}while(esta);
			MatrixP[i][j] = CP.AccedePersonaje(n);
			numeros[controla] = n;
			SN[i][j] = true;
			controla++;
		}
	}
}
Personaje Tablero::AccedePersonaje(int i, int j){
	return MatrixP[i][j];
}
void Tablero::Tacha(int i, int j){
	SN[i][j]  = false;
}
void Tablero::DesTacha(int i, int j){
	SN[i][j]  = true;
}

bool Tablero::ComprGanador(int &x, int &y){
	bool retur = false;
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			if(SN[i][j] == true){
				retur = true;
				x = i;
				y = j;
			}
		}
	}
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			if(i!=x || j != y){
				if(SN[i][j] == true){
					retur = false;
					x = -1;
					y = -1;
				}
			}
		}
	}
	return retur;
}
