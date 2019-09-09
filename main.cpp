#include <iostream>
#include <stdio.h>
#include <string>
#include "BD.h"
#include "archivo.h"
#include "Gestor.h"
using namespace std;

int main()
{

    Gestor *g;
    int opcion=0;
    while(opcion!=10)
    {
    cout << "1. Crear Base de Datos\n2. Crear Tabla\n3. Imprimir datos de la tabla\n4. Borrar Tabla\n5.Imprimir Tablas\n6.Agregar Datos \n7. Drop Databse\n8. Cargar Database\n9. Guardar Tabla Actual \n10. Salir"<<endl;
    cin >> opcion;
    char *nom=new char[20];
    
    char * llave=new char[20];
    int tam=0;
    char * cont=new char[20];

    switch (opcion)
    {
    case 1:
        cout<<"Ingresar Nombre de la Base de datos"<<endl;
        cin>>nom;
        cout<<"Ingresar Tamano de la Base de datos"<<endl;
        cin>>tam;
        g= new Gestor(nom,tam,1);
        break;
    case 2:
        cout<<"Ingresar Nombre de la Tabla"<<endl;
        cin >> nom;
        cout<<"Ingresar Llave Primaria de la Tabla"<<endl;
        cin>>llave;
        cout<<"Ingresar Cantidad de columnas de la Tabla"<<endl;
        cin>>tam;
        g->CrearTabla(tam,nom,llave);

        //columnas
        for(int x=0; x<tam;x++)
        {
        char * nomCol = new char[20];
        cout<<"Datos para la columna: "<<x+1<<endl;    
        int tipo;
        cout<<"Ingresar Tipo de Columna\n-2 para doubles \n-1 para int \nSi no especifique tamano de char\n"<<endl;
        cin>>tipo;
        cout<<"Ingresar Nombre de Columna"<<endl;
        cin >> nomCol;
        g->AgregarColumna(tipo,nomCol);
        }
        g->GuardarTabla();

        break;
    case 3:
     cout<<"Ingresar Nombre de Tabla a Ver los dats"<<endl;
        cin >> nom;
        g->ImprimirDatos(nom);
        break;
    case 4:
        cout<<"Ingresar Nombre de Tabla a Borrar"<<endl;
        cin >> nom;
        g->BorrarTabla(nom);
        break;
    case 5:
        g->CargarTablas();
        g->ImprimirTablas();
        break;
    case 6:
    cout<<"Ingresar Nombre de Tabla que desee agregar datos"<<endl;
        cin >> nom;
    g->AgregarDatos(nom,"");

        break;
    case 7:
        cout<<"Ingresar Nombre de la Base de datos a Borrar"<<endl;
        cin>>nom;
        g= new Gestor(nom,10,-1);
        g->ar->Delete();
        break;

    case 8:
        cout<<"Ingresar Nombre de la Base de datos"<<endl;
        cin>>nom;
        g= new Gestor(nom,10,0);
        break;

    case 9:
        g->GuardarTabla();
        break;
    case 10:
//        dv->ar->Close();

        cout<<"Cerrando Programa"<<endl;
        break;
    }
    }

/*

g->CargarBits();



g->CrearTabla(3,"tabla2","primekey");

g->AgregarColumna(23,"fruta");
g->AgregarColumna(24,"fruta2");
g->AgregarColumna(24,"fruta3");
g->GuardarTabla();
g->CargarTablas();
g->ImprimirTablas();
cout<<"borrando tabla"<<endl;
g->BorrarTabla("tabla2");
g->CargarTablas();
g->ImprimirTablas();

//g->temp->Guardar(g->tempb->index);
//g	>BorrarTabla("h");
//g	>CargarTablas();
//g	>ImprimirTablas();
//g	>IniciarBit();
//g->CrearTabla(3,"prueba","llave",3,4);
//g->CrearTabla(4,"prueba2","llave2",5,6);
//cout<<g->BuscarBit()<<endl;*/
    return 0;
}
