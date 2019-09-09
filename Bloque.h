#ifndef BLOQUE_h
#define BLOQUE_H
#include "archivo.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


class Bloque
{
    public:
        Bloque(char * nombre, char * contenido, int primerbloque,int ultimobloque,Archivo * a);
        virtual ~Bloque();
        int tambloque;
        int tamnombre;
        char * nombre;
        int tamcont;
        char * contenido;
        int primerbloque;
        int ultimobloque;
        Archivo *arch;
        void InitFromChar(char * info);
        char * BloquerchtoChar();
        void Guardar();

    protected:

    private:
};

#endif // Bloque_H
