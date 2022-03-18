#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct nodoUsuario
{
    string nombre;
    string apellido1;
    string apellido2;
    int codigo;
    char tipoUsuario;
    string cuenta;
    string contrasenna;
    bool estado;
    nodoUsuario *siguiente;
    nodoUsuario *anterior;
};
typedef struct nodoUsuario *lista;

nodoUsuario *crearNodo(string nom,string ap1,string ap2,int cod,char tipoU, string cuen,string con, bool es)
{
    nodoUsuario *aux = new (struct nodoUsuario);
    aux->nombre=nom;
    aux->apellido1=ap1;
    aux->apellido2=ap2;
    aux->codigo=cod;
    aux->tipoUsuario=tipoU;
    aux->cuenta=cuen;
    aux->contrasenna=con;
    aux->estado=es;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    return aux;
}

void mostrar (lista cabeza)
{
    lista aux;
    if (cabeza==NULL)
    cout<<"Lista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
            cout<<"Nombre: "<<aux->nombre<<endl;
            cout<<"Primer apelldio: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido: "<<aux->apellido2<<endl;
            cout<<"Codigo: "<<aux->codigo<<endl;
            cout<<"Tipo de usuario: "<<aux->tipoUsuario<<endl;
            cout<<"Contraseña: "<<aux->contrasenna<<endl;

            if (aux->estado==true)
            {
            cout<<"Cuenta activa"<<endl;
            }else
            {
                cout<<"Cuenta inactiva"<<endl;
            }
            cout<<"=========================="<<endl;
aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
}



//lista circular doble
void ingresarFinal(lista &cabeza,string nombre, string apellido1,string apellido2, int codigo, char tipoUsuario, string cuenta, string contrasenna,bool estado)
{
    nodoUsuario *nuevo;
    nuevo=crearNodo(nombre,apellido1,apellido2,codigo,tipoUsuario,cuenta,contrasenna,estado);

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
    }
    else
    {
    nuevo->siguiente=cabeza;
    nuevo->anterior=cabeza->anterior;
    cabeza->anterior->siguiente=nuevo;
    cabeza->anterior=nuevo;
    }
}

int main()
{
    lista List=NULL;
    ingresarFinal(List,"Pablo","Hernandez","Gutierrez",1,'E',"PabloH26","1234",true);   
     ingresarFinal(List,"Maria","Castillo","Fernandez",2,'E',"MCast45","contraseña",true);   
      ingresarFinal(List,"Andres","Ortega","Perez",3,'A',"AndresOrtega1","4321",false);
      mostrar(List);
}