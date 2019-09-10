#ifndef GESTOR_H
#define GESTOR_H
#include <iostream>
#include "archivo.h"
#include <stdio.h>
#include <string.h>
#include "Tabla.h"
#include "BD.h"
#include <vector>
#include "list"
#include <stdlib.h>

using namespace std;
class Gestor
{
    public:
        Gestor(char * nom, int tam, int n);
        char* nombre;
        int tamano;
        int cantbloquesbitmap;
        Archivo *ar;
        Tabla * temp;
        BD * tempb;
        char * key;
        list<Tabla*> Tablas;
        list<int> Types;
        list<char*> Nombres;
        int * bitmap;
        void CargarTablas();
        void IniciarBit();
        int BuscarBit();
        void ImprimirTablas();
        Tabla* BuscarTabla(char * x);
        void CargarBloques();
        void CargarBits();
        void GuardarBloques();
        void GuardarBits();
        void IniciarBD();
        void IniciarBloques();
        void CrearTabla(int cant, char * nom, char * k);
        void BorrarTabla(char * nom);
        void AgregarDatos(char * nom, char * col);
        void ImprimirDatos(char * nom);
        void ActualizarInt(char * nom, char * col, int val);
        void ActualizarDouble(char * nom, char * col, double val);
        void ActualizarChar(char * nom, char * col, char * val);
        void BorrarDatos(char * nom, char * col, char * cond);
        void Seleccion(char * nom, char * cols, char * cond, char * val);
        void GuardarTabla();
        void AgregarColumna(int t, char * x);
        void printBitmap();
        virtual ~Gestor();

    protected:

    private:

};

#endif // GESTOR_H
