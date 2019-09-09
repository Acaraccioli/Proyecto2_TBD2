#include "Tabla.h"

Tabla::Tabla(int pos,int cant, char nom[20], char k[20], int e, int t,Archivo *a)
{       //cout<<"nueva tabla"<<nom<<"empieza"<<e<<"termina"<<t<<endl;
        borrado=0;
        this->posactual=pos;
        this->cantcol=cant;
        strcpy(nombre,nom);
        strcpy(key,k);
        this->empieza=e;
        this->termina=t;
        this->num=0;
        nombresstring[cant];


        nombres = new char *[cant];
        for (int i=0; i<cant;i++)
        {
            nombres[i]=new char[20];
            nombres[i]="nomcolumna";

        }
        this->tipos=new int[cant];
        this->arch=a;

}
void Tabla::agregarCol(char * nom, int tipo)
{
    nombres[num]=nom;
    tipos[num]=tipo;
    num++;

}
char * Tabla::ToChar()
{
    int pos=0;
    char *datos= new char[60];
    //printf("bot = %d, posactual = %d, cantcol = %d, nom = %s,key = %s,empieza = %d,termina = %d\n",
    //borrado,posactual,cantcol,nombre,key,empieza,termina);
    memcpy(&(datos[pos]),&borrado,4); //bool
    pos+=4;
    memcpy(&(datos[pos]),&posactual,4); //int
    pos+=4;
    memcpy(&(datos[pos]),&cantcol,4); //int
    pos+=4;
    memcpy(&(datos[pos]),nombre,20); //
    pos+=20;
    memcpy(&(datos[pos]),key,20);
    pos+=20;
    memcpy(&(datos[pos]),&empieza,4);
    pos+=4;
     memcpy(&(datos[pos]),&termina,4);
    pos+=4;
    return datos;
}

/*

    void Tabla::Guardar()
{
    char *datos=BDToChar();
    this->arch->Write(0,datos,4096);
}*/


void Tabla::Guardar()
{
    int po=posactual;

    cout<<"guardando tabla:"<<po<<endl;
    char *datos=ToChar();
    this->arch->Write(po,datos,60);
    po+=60;
    char * tipostemp= new char[cantcol*4]; //tipos cols 
    char * nomtemp= new char[cantcol*20]; 

    for(int x=0; x<cantcol;x++)
    {
       memcpy(&(tipostemp[x*4]),&(tipos[x]),4);
       memcpy(&(nomtemp[x*20]),(nombres[x]),20);

    }
    
    
    cout<<"guardando tipos en pos:"<<po<<endl;
    this->arch->Write(po,tipostemp,cantcol*4);
    po+=4*cantcol;
    cout<<"guardando nombres en pos:"<<po<<endl;
    this->arch->Write(po,nomtemp,cantcol*20);

}

void Tabla::GuardarMetadata()
{
    int po=posactual;

    cout<<"guardando tabla:"<<po<<endl;
    char *datos=ToChar();
    this->arch->Write(po,datos,60);
    po+=60;
    char * tipostemp= new char[cantcol*4]; //tipos cols 
    char * nomtemp= new char[cantcol*20]; 
}
void Tabla::Initfromchar(char * datos)
{
    int t=0;
    memcpy(&borrado,&(datos[t]),4);
    printf("bot = %d, ",borrado);
    t+=4;
    memcpy(&posactual,&(datos[t]),4);
    printf("posacutal = %d, ",posactual);
    t+=4;
    memcpy(&cantcol,&(datos[t]),4);
    printf("cantcol = %d, ",cantcol);
    t+=4;
    memcpy(nombre,&(datos[t]),20);
    t+=20;
    memcpy(key,&datos[t],20);
    t+=20;
    memcpy(&empieza,&(datos[t]),4);
    t+=4;
    memcpy(&termina,&(datos[t]),4); 

}

void Tabla::InitColumnas(char * datos)
{
    string uno;
    string dos;
    int t=0;

    //columnas
     for(int x=0; x<cantcol;x++)
    {
       memcpy(&(tipos[x]),&datos[t+(x*4)],4);
    }
    t+=cantcol*4;
   for(int x=0; x<cantcol;x++)
    {
            char temp[20]="";

    memcpy(temp,&datos[t+(x*20)],20);
   // cout<<"x"<<temp;
    memcpy(&(nombresarreglo[x*20]),(temp),20);
   
    }
    /*for(int x=0; x<cantcol*20; x++)
    {
        if(x%20==0)
        cout<<"\n";
        cout<<nombresarreglo[x];
    }*/






}
void Tabla::Cargar(int e, int c)
{
    
    Initfromchar(this->arch->Read(e,c));
    //cout<<nombre;
}
Tabla::~Tabla()
{
    //dtor
}
