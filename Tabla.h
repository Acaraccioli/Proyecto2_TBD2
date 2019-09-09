#ifndef TABLA_H
#define TABLA_H
#include <string.h>
#include <iostream>
#include "archivo.h"
using namespace std;

class Tabla
{
    public:
        Tabla(int pos,int cant, char nom[20], char k[20], int e, int t, Archivo *a);
        virtual ~Tabla();
        int borrado;
        int cantcol;
        char nombre[20] = "";
        char key[20] = "";
        string  nombresstring;
        int posactual;
        int empieza;
        int termina;
        int num;
        void Initfromchar(char * datos);
        void InitColumnas(char * datos);
        void Cargar(int e, int c);
        char** nombres;
        int * tipos;
        Archivo *arch;
        char *ToChar();
        void Guardar();
        void GuardarMetadata();
        void agregarCol( char * nom, int tipo);
        char nombresarreglo[200]="";
        int cantdatos;





    protected:

    private:
};

#endif // TABLA_H
