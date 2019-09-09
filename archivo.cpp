#include "archivo.h"
#include <fstream>
#include <cstring>

Archivo::Archivo(char * nombre, bool nuevo)
{
    this->nombre = nombre;
    if(nuevo){
        file = fopen(nombre, "w+");
        fclose(file);

    }
}

 char * Archivo::Read(int pos, int longitud){
    Open();
    printf("pos : %d, long : %d\n", pos, longitud);
    char * data = (char*)malloc(sizeof(char)*longitud+1);
    //unsigned char data[longitud];
    fseek(file, pos, SEEK_SET);
    fread(data, sizeof(char), longitud, file);
  std::cout<<"meow";
    Close();
  // char *data2 = &data[0];
    //printf("s: %s\n", data);
    int c = 0;
   return data;

} 
/*
char * Archivo::Read(int pos, int longitud){
    std::ifstream fileR;
    fileR.open(this->nombre,std::ios::out | std::ios::in);
    fileR.seekg(pos);
    //char * data = (char*)malloc(sizeof(char)*longitud+1);
    char * data = new char[longitud+1];
    fileR.read(data,longitud);
    fileR.close();
        
    return data;
} */

void Archivo::Write(int pos, char * data, int longitud){
    Open();
    fseek(file, pos, SEEK_SET);
    fwrite(data, sizeof(char), longitud, file);
    Close();
}

void Archivo::Open(){
    file = fopen(nombre, "r+");
}

void Archivo::Close(){
    fclose(file);
}

void Archivo::setTam(int pos){
    Open();
    fseek(file, pos, SEEK_SET);
    fputc('\0', file);
    Close();
}

void Archivo::Delete(){
        remove(nombre);
}
