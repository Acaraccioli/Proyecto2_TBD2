#ifndef BD_H
#define BD_H
#include "archivo.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;


class BD
{
    public:
        BD(int tamArch, Archivo *a);
        int posenindice;
        int CantidadBloques;
        int CantidadTablas;
        int cantbloquesparabitmap;
        //primer bloque Archivo?
        Archivo *arch;
        char *MasterBlockToChar();
        void Guardar();
        void Initfromchar(char *data);
        void Cargar();
        virtual ~BD();

    protected:

    private:
};

#endif // BD_H
