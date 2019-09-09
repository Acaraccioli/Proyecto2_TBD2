#include "BD.h"

BD::BD(int tamArch,Archivo *a)
{
    this->CantidadBloques=((tamArch*1024*1024)/4096);
    this->arch=a;
    this->CantidadTablas=0;
    //this->cantbloquesparabitmap=ceil((CantidadBloques/8)/4096);
    this->cantbloquesparabitmap = 1; //PORMIENTRAS
    //printf("Cant bloques: %d\n", this->CantidadBloques);
    printf("Cant bitmap blocks: %d\n", this->cantbloquesparabitmap);
    this->posenindice=16;

}
char * BD::MasterBlockToChar()
{
    int pos=0;

    char * datos= new char[16];
    
    memcpy(&(datos[pos]),&CantidadBloques,4);
    pos+=4;
    memcpy(&(datos[pos]),&CantidadTablas,4);
    pos+=4;
    memcpy(&(datos[pos]),&cantbloquesparabitmap,4);
    pos+=4;
    memcpy(&(datos[pos]),&posenindice,4);
     
    return datos;

}

void BD::Initfromchar(char * datos)
{
    int pos=0;
    memcpy(&CantidadBloques,&(datos[pos]),4);
    pos+=4;

    memcpy(&CantidadTablas,&(datos[pos]),4);
    pos+=4;

     memcpy(&cantbloquesparabitmap,&(datos[pos]),4);
    pos+=4;
    memcpy(&posenindice,&(datos[pos]),4);
  //  printf("cantbloques = %d, cantTablas = %d, cantbloquesbitmap = %d, posindice = %d\n",CantidadBloques,CantidadTablas,cantbloquesparabitmap,posenindice);
   // pos+=4;

}
void BD::Cargar()
{
   
    Initfromchar(this->arch->Read(0,16));
}
void BD::Guardar()
{
    char *datos=MasterBlockToChar();
    this->arch->Write(0,datos,16);
}
BD::~BD()
{
    //dtor
}
