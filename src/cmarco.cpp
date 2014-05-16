//cmarco.cpp

#include <cmarco.h>
#include <iostream>
#include <graficos.h>

using namespace graficos;
using namespace std;

istream & operator>>(istream &is, Color &C){
	int r1, g1, b1;
	QC(is);
	is >> r1;
	QC(is);
	is >> g1;
	QC(is);
	is >> b1;
	C.r = r1;
	C.g = g1;
	C.b = b1;
	return is;
}
ostream &operator<<(ostream &os, Color &C){
	os << C.r << endl;
	os << C.g << endl;
	os << C.b << endl;
	return os;
}

istream & operator>>(istream &is, Marco &M){
	QC(is);
	is >> M.x;
	QC(is);
	is >> M.y;
	QC(is);
	is >> M.ancho;
	QC(is);
	is >> M.alto;
	QC(is);
	is >> M.fondo;
	QC(is);
	is >> M.ancho_m;
	QC(is);
	is >> M.alto_m;
	QC(is);
	is >> M.marco;
	return is;
}
ostream & operator<<(ostream &os, Marco &M){
	os << M.x << endl;
	os << M.y << endl;
	os << M.ancho << endl;
	os << M.alto << endl;
	os << M.fondo;
	os << M.ancho_m << endl;
	os << M.alto_m << endl;
	os << M.marco;
	return os;
}

void Marco::Pinta(){

	RectanguloR(x, y, x+ancho, y+alto, marco.r, marco.g, marco.b);
	RectanguloR(x+ancho_m, y+alto_m, (x+ancho)-ancho_m, (y+alto)-alto_m, fondo.r, fondo.g, fondo.b);
}

