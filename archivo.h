#ifndef Archivo_H
#define Archivo_H
#include <stdio.h>
#include <iostream>

class Archivo
{
    public:
        Archivo(char * nombre, bool nuevo);
        char * Read(int pos, int longitud);
        void Write(int pos, char * data, int longitud);

        void Open();
        void Close();
        void setTam(int pos);
        void Delete();

        FILE * file;
        char * nombre;
};

#endif // Archivo_H
