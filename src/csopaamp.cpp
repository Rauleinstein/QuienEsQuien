//csopaamp.cpp

#include <cstring>
#include <csopaamp.h>

istream & operator>>(istream &is, Sopaamp & Sop){
	is>>Sop.S;
	return is;
}
ostream & operator<<(ostream &os, Sopaamp & Sop){
	os<<Sop.S;
	return os;
}
bool Sopaamp::LocalizarEste(const char *c){//Va Bien
	bool encontrada = false;
	if(strlen(c) > S.GetFilas() || strlen(c) > S.GetCols())
		return false;
	for(int i=0; i<S.GetFilas(); i++){
		for(int j=0; j<S.GetCols(); j++){
			if(c[0] == S.Get(i, j)){
				for(int q=0; q<strlen(c); q++){
					if(c[q] != S.Get(i, j+q)){
						encontrada = false;
					}
					else{
						encontrada = true;
					}
				}
				if(encontrada)
					return true;
			 }
		}
	}
	return encontrada;
}
bool Sopaamp::LocalizarOeste(const char *c){//va bien
	bool encontrada = false;
	if(strlen(c) > S.GetFilas() || strlen(c) > S.GetCols())
		return false;
	for(int i=0; i<S.GetFilas(); i++){
		for(int j=0; j<S.GetCols(); j++){
			if(c[0] == S.Get(i, j)){
				for(int q=0; q<strlen(c); q++){
					if(c[q] != S.Get(i, j-q)){
						encontrada = false;
					}
					else{
						encontrada = true;
					}
				}
				if(encontrada)
					return true;
			 }
		}
	}
	return encontrada;
}
bool Sopaamp::LocalizarNorte(const char *c){//va bien
	bool encontrada = false;
	if(strlen(c) > S.GetFilas() || strlen(c) > S.GetCols())
		return false;
	for(int i=0; i<S.GetFilas(); i++){
		for(int j=0; j<S.GetCols(); j++){
			if(c[0] == S.Get(i, j)){
				for(int q=0; q<strlen(c); q++){
					if(S.GetFilas() > q+i && i-q > 0){
						if(c[q] != S.Get(i-q, j)){
							encontrada = false;
						}
						else{
							encontrada = true;
						}
					}
				}
				if(encontrada)
					return true;
			 }
		}
	}
	return encontrada;
}
bool Sopaamp::LocalizarSur(const char *c){
	bool encontrada = false;
	if(strlen(c) > S.GetFilas() || strlen(c) > S.GetCols())
		return false;
	for(int i=0; i<S.GetFilas(); i++){
		for(int j=0; j<S.GetCols(); j++){
			if(c[0] == S.Get(i, j)){
				for(int q=1; q<strlen(c); q++){
					if(S.GetFilas() > q+i && i-q > 0){
						if(c[q] == S.Get(i+q, j)){
							encontrada = true;
						}
						if(c[q] != S.Get(i-q, j)){
							return false;
						}
					}
				}
				if(encontrada)
					return true;
			 }
		}
	}
	return encontrada;
}
bool Sopaamp::LocalizarNorEste(const char *c){
	bool encontrada = false;
	if(strlen(c) > S.GetFilas() || strlen(c) > S.GetCols())
		return false;
	for(int i=0; i<S.GetFilas(); i++){
		for(int j=0; j<S.GetCols(); j++){
			if(c[0] == S.Get(i, j)){
				for(int q=1; q<strlen(c); q++){
					if(S.GetFilas() > q+i && i-q > 0){
						if(c[q] == S.Get(i-q, j+q)){
							encontrada = true;
						}
						if(c[q] != S.Get(i-q, j)){
							return false;
						}
					}
				}
				if(encontrada)
					return true;
			 }
		}
	}
	return encontrada;
}
bool Sopaamp::LocalizarNorOeste(const char *c){
	bool encontrada = false;
	if(strlen(c) > S.GetFilas() || strlen(c) > S.GetCols())
		return false;
	for(int i=0; i<S.GetFilas(); i++){
		for(int j=0; j<S.GetCols(); j++){
			if(c[0] == S.Get(i, j)){
				for(int q=1; q<strlen(c); q++){
					if(S.GetFilas() > q+i && i-q > 0){
						if(c[q] == S.Get(i-q, j-q)){
							encontrada = true;
						}
						if(c[q] != S.Get(i-q, j)){
							return false;
						}
					}
				}
				if(encontrada)
					return true;
			 }
		}
	}
	return encontrada;
}
bool Sopaamp::LocalizarSurEste(const char *c){
	bool encontrada = false;
	if(strlen(c) > S.GetFilas() || strlen(c) > S.GetCols())
		return false;
	for(int i=0; i<S.GetFilas(); i++){
		for(int j=0; j<S.GetCols(); j++){
			if(c[0] == S.Get(i, j)){
				for(int q=1; q<strlen(c); q++){
					if(S.GetFilas() > q+i && i-q > 0){
						if(c[q] == S.Get(i+q, j+q)){
							encontrada = true;
						}
						if(c[q] != S.Get(i-q, j)){
							return false;
						}
					}
				}
				if(encontrada)
					return true;
			 }
		}
	}
	return encontrada;
}
bool Sopaamp::LocalizarSurOeste(const char *c){
	bool encontrada = false;
	if(strlen(c) > S.GetFilas() || strlen(c) > S.GetCols())
		return false;
	for(int i=0; i<S.GetFilas(); i++){
		for(int j=0; j<S.GetCols(); j++){
			if(c[0] == S.Get(i, j)){
				for(int q=1; q<strlen(c); q++){
					if(S.GetFilas() > q+i && i-q > 0){
						if(c[q] == S.Get(i+q, j-q)){
							encontrada = true;
						}
						if(c[q] != S.Get(i-q, j)){
							return false;
						}
					}
				}
				if(encontrada)
					return true;
			 }
		}
	}
	return encontrada;
}
bool Sopaamp::Google(const char *cad){
	if(LocalizarEste(cad))
		return true;
	if(LocalizarOeste(cad))
		return true;
	if(LocalizarNorte(cad))
		return true;
	if(LocalizarSur(cad))
		return true;
	if(LocalizarNorEste(cad))
		return true;
	if(LocalizarNorOeste(cad))
		return true;
	if(LocalizarSurOeste(cad))
		return true;
	if(LocalizarSurOeste(cad))
		return true;
	return false;
}