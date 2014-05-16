// preguntas.cpp

#include <iostream>
#include "cadenas.h"
#include "con_ras.h"
#include "graficos.h"
#include "Marco.h"
#include "imagen.h"
#include "Preguntas.h"

using namespace std;
using namespace graficos;

Preguntas::Preguntas (con_ras rasgos) //llamar siempre con un con_ras
{
    char* task;
    con_ras aux (rasgos);
    this->rasgos=aux;
    fuente=new char [100];
   
    for (int i=0; i<rasgos.Size_con_ras(); i++)
    {
        for (int j=0; j<rasgos.Size_ras_tipo(i); j++)
        {
            task=rasgos.Ob_pregunta (i,j);
            preguntas.AddCadenas(task);
        }
    }
}

Preguntas::~Preguntas(){ }

char * Preguntas::ObPreguntasR (int i, int j)
{
    return rasgos.Ob_pregunta (i,j);
}

void Preguntas::Add_pregunta (char* nueva)
{
    preguntas.AddCadenas(nueva);
}

int Preguntas::SizeCadenas()
{
    return preguntas.SizeCadenas();
}

char* Preguntas::ObPreguntasA (int i)
{
    return preguntas.ObCadena(i);
}

void Preguntas::crea_ventana_preguntas()
{
    m.CreaMarco();
}

void Preguntas::Escribe_en_marco()
{
   
    int startx=0;
     int starty=0;
     int tama=0;
    int tam1=0;
    int tam2=0;
    char* cad;
   
    startx = m.ObPunto().ObX()+m.ObAncho_m();
    starty = m.ObPunto().ObY()+m.ObAlto_m ();
   
   
    for(int i=0; i<preguntas.SizeCadenas ();i++)
    {
    EscribirTexto(startx, (starty+tama),preguntas.ObCadena(i),  CargarFuente(fuente, tamf),  font.Obr(), font.Obg(), font.Obb());
    TamanoTexto(CargarFuente(fuente, tamf),cad,tam2,tam1);
    tama=tama+tam1+15;
    }
   
}

istream& operator >> (istream &is, Preguntas &p)
{
    is>>p.m;
    is.get();
    is.getline(p.fuente,100);
    is>>p.tamf;
    is.get();
    is>>p.font;
   
   
    return is;
}