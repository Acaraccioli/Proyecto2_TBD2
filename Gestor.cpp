#include "Gestor.h"

Gestor::Gestor(char * nom, int tam, int n)
{
    bitmap= new bool[((tam*1024*1024)/4096)];
    cout<<(((tam*1024*1024)/4096));
    this->nombre= nom;
    this->tamano=tam;


    this->ar= new Archivo(nombre,n);
    ar->setTam(tam);

    this->tempb= new BD(tam,this->ar);
    if(n)
    tempb->Guardar();
    key= new char[20];
    if(n==1)
    {
        //IniciarBD();
        IniciarBit();
        CargarBits();
        IniciarBloques();
        //CargarBloques();
    }
    else if(n==0){
         IniciarBD();
        //CargarBloques();
        CargarBits();
        CargarTablas();
    }
    else if(n==-1){
        //nada es borrar
    }


}

void Gestor::IniciarBD()
{
    this->tempb->Cargar();

}

void Gestor::CargarTablas()
{       
        list<Tabla*> Tablas2;
        list<int> Types2;
        list<char*> Nombres2;
        Tablas=Tablas2;
        Types=Types2;
        Nombres=Nombres2;
        int t=0;
        int v=14;
        //std::cout<<"Cantidad de Tablas:"<<tempb->CantidadTablas<<endl;
      /*  unsigned char * data;
        //strcpy(data,ar->Read(16,60));
        memcpy(&data,(char*)(ar->Read(16,60)),60);
        int c = 0;
        for(int a = 0; a < 60; a++){
            printf("char: %c, c = %d\n", data[a],c);
            c++;
        }  */
        int pos=16;
        for(int x=0;x<tempb->CantidadTablas;x++)
        {
        Tabla *tab=new Tabla(0,0,"","",0,0,ar);
        tab->Initfromchar(ar->Read(pos,60));
        pos+=60;
        tab->InitColumnas(ar->Read(pos,(tab->cantcol*4)+tab->cantcol*20));
        pos+=((tab->cantcol*4)+tab->cantcol*20);
        Tablas.push_back(tab);
        }       
       //tab->Initfromchar(data);

   //if(tab != nullptr)
   // {

    //std::cout<<"Nom: "<<tab->nombre<<endl;
    //for(int a = 0; a < 3; a++){
        //std::cout<<"Cols: "<<tab->nombres[0]<<endl;
    //}
    
   // }
    //std::cout<<"Ok";
    //this->Tablas.push_back(tab)

   // }
   // else
      //  {
           // t+=((4*cantcol)+(30*cantcol));


       // }
    }





void Gestor::ImprimirTablas()
{
    cout<<endl<<"\n***IMPRIMIENDO TABLAS***"<<endl;

    for(list<Tabla*>::iterator l=Tablas.begin();l!=Tablas.end();l++)
    {  // cout<<"Iterator"<<endl;

        Tabla *t=*l;
        if(t->borrado==0)
        {
        cout<<"Nombre:"<<t->nombre;

        for(int i=0; i<t->cantcol;i++){
        if(i%20==0)
          cout<<"\n";
        if(t->tipos[i]==-2)
        {
               cout<<"Tipo: Double";;
        }  
        else if(t->tipos[i]==-1)
        {
              cout<<"Tipo: Integer";;
        }
        else
        {
             cout<<"Tipo: Varchar["<<t->tipos[i]<<"]";
        }
        
     
        cout<<" Nom: ";
        
        for(int x=i*20;x<(i*20)+20;x++)
        {
            cout<<t->nombresarreglo[x];
        }
        cout<<"\n";
        }

        }
        cout<<"\n";


    }

    /*
    for(list<int>::iterator l=Types.begin();l!=Types.end();l++)
    {
         //   cout<<"Iterator2"<<endl;

        int t=*l;
        cout<<"Tipo:"<<t<<endl;
    }
    for(list<char*>::iterator l=Nombres.begin();l!=Nombres.end();l++)
    {
        //cout<<"Iterator3"<<endl;

        char * c=*l;
        cout<<"Cols:"<<c<<endl;
    }*/
}
int Gestor::BuscarBit()
{
    for (int i = 0; i < tempb->CantidadBloques; i++)
  {
      if (bitmap[i]==0)
      {     return i;

      }
  }
  return -1;
}
Tabla* Gestor::BuscarTabla(char * nom)
{
    Tabla *tab=new Tabla(0,0,"","",0,0,ar);
     for(list<Tabla*>::iterator l=Tablas.begin();l!=Tablas.end();l++){
        Tabla *t=*l;
        if(strcmp(t->nombre, nom) == 0)
        {
            tab=t;
            return tab;
        }

    }
}
void Gestor::CargarBloques()
{
    int p=4097;
      for (int i = 0; i < tempb->CantidadBloques; i++)
  {

     char * d = ar->Read(p,1);
    memcpy(&(this->bitmap[i]),&d,1);
  }
}
void Gestor::IniciarBloques()
{   int y=20480;
    for(int i=0;i<tempb->CantidadBloques;i++)
    {
        char *nume = reinterpret_cast<char*>(&i);
        ar->Write(y,nume,4);
        y+=4094;
        ar->Write(y,"0",4);
        y+=4;


    }

}
void Gestor::CargarBits()
{
    int pos=0;

     char * da=new  char[tempb->CantidadBloques];
    da = ar->Read(4096*2,tempb->cantbloquesparabitmap*4096);
    for(int i=0;i<tempb->CantidadBloques;i++)
    {bool x;
     memcpy(&x,&(da[i]),1);
     bitmap[i]=x;
    }
    /*for(int i=0;i<tempb->CantidadBloques;i++)
    {
        cout<<"B:"<<bitmap[i];
    }*/

}
/*evelyn menjivar
3170 0075
tabacalera hondurena 
fundidora norte
erick 
31700092*/

void Gestor::IniciarBit()
{
    char * da=new char[tempb->CantidadBloques];
    bitmap[0]=1;
    memcpy(&(da[0]),&(bitmap[0]),1);
    bitmap[1]=1;
    memcpy(&(da[1]),&(bitmap[1]),1);
    
    for (int i = 0; i < tempb->cantbloquesparabitmap; i++)
    {
     bitmap[i+2]=1;
     memcpy(&(da[i+2]),&(bitmap[i+2]),1);

    }

  for (int i = tempb->cantbloquesparabitmap+1; i < tempb->CantidadBloques; i++)
  {
        this->bitmap[i]=0;
        memcpy(&(da[i]),&(bitmap[i]),1);
  }

    ar->Write(4096,da,tempb->CantidadBloques);

}


void Gestor::CrearTabla(int cant, char * nom, char * k)
{   cout<<"creando tabla"<<endl;
    int x=BuscarBit();
    temp= new Tabla(tempb->posenindice,cant,nom,k,x,x,ar);
    this->bitmap[x]=1;
    GuardarBits();

    tempb->CantidadTablas=tempb->CantidadTablas+1;
    tempb->posenindice= tempb->posenindice+60;
    tempb->Guardar();

}
void Gestor::GuardarBits()
{
        char * da=new char[tempb->CantidadBloques];

  for (int i = 0; i < tempb->CantidadBloques; i++)
  {
        memcpy(&(da[i]),&(bitmap[i]),1);
  }


    ar->Write(4096*2,da,tempb->cantbloquesparabitmap*4096);

}
void Gestor::GuardarTabla()
{
    temp->Guardar();
    //cout<<"Guardando Cant COl:"<<temp->cantcol<<"index esta en:"<<tempb->index<<endl;
   // tempb->index=tempb->index+57+(4*temp->cantcol)+(30*temp->cantcol);
    tempb->Guardar();
    cout<<tempb->posenindice<<endl;


}
void Gestor::AgregarColumna(int t, char * n)
{
    temp->agregarCol(n,t);
    tempb->posenindice+=24;
}
void Gestor::BorrarTabla(char* nom)
{
     Tabla * t=BuscarTabla(nom);
     t->borrado=1;
     t->GuardarMetadata();
    // CargarTablas();
}

void Gestor::AgregarDatos(char* nom, char* col)
{
    Tabla * t=BuscarTabla(nom);
        int integer;
        double doble;
        char buffer[300];
        int posenbuffer=t->termina;
        int tam=0;
     for(int i=0; i<t->cantcol;i++){
        cout<<"Ingrese valor para la columna: ";
        
        for(int x=i*20;x<(i*20)+20;x++)
        {
            cout<<t->nombresarreglo[x];
        }
        cout<<"   ";

        if(t->tipos[i]==-2)
        {
               cout<<"Tipo: Double\n";
               cin>>doble;
               memcpy(&(buffer[posenbuffer]),(&doble),8);
               posenbuffer+=8;
               tam+=8;

        }  
        else if(t->tipos[i]==-1)
        {
              cout<<"Tipo: Integer\n";
              cin>>integer;
              memcpy(&(buffer[posenbuffer]),(&doble),8);
               posenbuffer+=4;
              tam+=4;
        }
        else
        {
             char vartype[t->tipos[i]];
             cout<<"Tipo: Varchar["<<t->tipos[i]<<"]\n";
             cin>>vartype;
             memcpy(&(buffer[posenbuffer]),vartype,t->tipos[i]);
             posenbuffer+=t->tipos[i];
             tam+=t->tipos[i];;

        }

     
        }

         ar->Write((t->empieza*4096)+t->termina,buffer,tam);
         t->termina+=tam;
         t->GuardarMetadata();
         


   /* int x=(((BuscarBit())*4096)+4);
    ar->Write(x,col,sizeof(col));
    char * num= new char[4];
    int a=BuscarBit();
    memcpy(&(num[0]),&a,4);
    ar->Write(((t->termina*4096)+4092),num,4);
    t->termina=BuscarBit();
    t->Guardar();
    bitmap[BuscarBit()]=1;
    GuardarBits();*/
}

void Gestor::ImprimirDatos(char * nom)
{
        Tabla * t=BuscarTabla(nom);

         char * datos= new char[4096];
      
        datos = ar->Read((t->empieza*4096),4096);
        int pos=0;
        while(pos<1000)
        {
        for(int x=0;x<t->cantcol;x++)
        {
           cout<<"Valor de columna: ";
            
            for(int y=x*20;x<(x*20)+20;y++)
            {
                cout<<t->nombresarreglo[y];
            }
            cout<<"   ";


            if(t->tipos[x]==-2)
            {
                double a=0;
                memcpy(&a,&(datos[pos]),8);
                cout<<a;
                pos+=8;

            }

            else if(t->tipos[x]==-1)
              {
                  int b=0;
                memcpy(&b,&(datos[pos]),4);
                  cout<<b;

                pos+=4;
              }
            else

            {
                char  c[t->tipos[x]];
                memcpy(c,&(datos[pos]),t->tipos[x]);
                cout<<c;
                pos+=t->tipos[x];
            }
        
        }
        
        }


}
void Gestor::ActualizarInt(char* nom, char* col, int val)
{

}


void Gestor::BorrarDatos(char* nom, char* col, char* cond)
{

}

void Gestor::Seleccion(char* nom, char* cols, char* cond, char* val)
{
     Tabla * t=BuscarTabla(nom);
     if(t->posactual==0)
        return;

        list<char*> columnas;

        for (int x=0; x<sizeof(cols);x+=30)
        {
            char * d= new char[30];
            memcpy(&(d[x]),&(cols[x]),30);
            columnas.push_back(d);
        }

        for(int y=0; y<t->cantcol;y++)
        {
            for(list<char*>::iterator l=columnas.begin();l!=columnas.end();l++)
            {

            }

        }


    char * columna=new char[30];
    for(int i=0; i<t->cantcol;i++)
    {

    }


}
Gestor::~Gestor()
{
    //dtor
}
