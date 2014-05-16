//csopaamp.h
#ifndef _csopaamp_h_
#define _csopaamp_h_
#include <csopa.h>
class Sopaamp{
	Sopa S;
	public:
		Sopaamp(){}
		friend istream & operator>>(istream &is, Sopaamp & Sop);
		friend ostream & operator<<(ostream &os, Sopaamp & Sop);
		bool LocalizarEste(const char *c);
		bool LocalizarOeste(const char *c);
		bool LocalizarNorte(const char *c);
		bool LocalizarSur(const char *c);
		bool LocalizarNorEste(const char *c);
		bool LocalizarSurEste(const char *c);
		bool LocalizarNorOeste(const char *c);
		bool LocalizarSurOeste(const char *c);
		bool Google(const char *cad);
};
#endif