#include "Bloque.h"

Bloque::Bloque(char * nom, char * cont, int pb,int ub,Archivo * a)
{
    this->tamnombre=strlen(nom);
    this->nombre=nom;
    this->tamcont=strlen(cont);
    this->contenido=cont;
    this->primerbloque=pb;
    this->ultimobloque=ub;
    this->tambloque=20+tamnombre+tamcont;
    this->arch=a;
    //ultimo bloque, se calcula o va en parametro?

}
char * Bloque::BloquerchtoChar()
{
    int pos=0;
    char *datos=new char[4096];
    pos+=4;
    memcpy(&(datos[pos]), nombre,20);
    pos+=20;
    memcpy(&(datos[pos]),contenido, 500);
    pos+=500;
    memcpy(&(datos[pos]),&primerbloque,4);
    pos+=4;
    memcpy(&(datos[pos]),&ultimobloque,4);
    pos+=4;
    return datos;


}
void Bloque::InitFromChar(char * datos)
{

    int pos=0;
    nombre=new char[tamnombre];
    memcpy(nombre,&(datos[pos]),20);
    pos+=20;
    contenido=new char[tamcont];
    memcpy(contenido,&(datos[pos]),500);
    pos+=500;
    memcpy(&primerbloque,&(datos[pos]),4);
    pos+=4;
    memcpy(&ultimobloque,&(datos[pos]),4);
    pos+=4;



}
void Bloque::Guardar()
{
        char * data = BloquerchtoChar();


    this->arch->Write(primerbloque*4096,data,4096);
    //empezar a escribir desde primer bloque?
}
Bloque::~Bloque()
{
    //dtor
}
