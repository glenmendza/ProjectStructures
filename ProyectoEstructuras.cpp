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

//lista circular doble
void ingresarFinalUsuarios(lista &cabeza,string nombre, string apellido1,string apellido2, int codigo, char tipoUsuario, string cuenta, string contrasenna,bool estado)
{
    nodoUsuario *nuevo;
    nuevo=crearNodo(nombre,apellido1,apellido2,codigo,tipoUsuario,cuenta,contrasenna,estado);
    

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
        cout<<"Usuario "<<cuenta<<" agregado"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    cout<<"Usuario "<<cuenta<<" agregado"<<endl;
    }
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

void desactivar (lista &cabeza)
{
    lista aux;
    int codigoUsuario;
    if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
        aux=cabeza;
        cout<<"Digite el codigo del usuario que desea desactivar"<<endl;
       cin>>codigoUsuario;
		
		do
		{
			if(aux->codigo==codigoUsuario && aux==cabeza)
			{
				cabeza=aux->siguiente;
				aux->siguiente->anterior =aux->anterior;
				aux->anterior->siguiente=aux->siguiente;
				aux->anterior=NULL;
				aux->siguiente=NULL;
				delete(aux);
				aux=cabeza;
			}
			else
			{
				if(aux->codigo==codigoUsuario && aux!=cabeza)
				{
					aux->anterior->siguiente=aux->siguiente;
					aux->siguiente->anterior=aux->anterior;    
					aux->siguiente=NULL;
					aux->anterior=NULL;      
					delete(aux);
					aux=cabeza;                         
				}

			}
			aux=aux->siguiente;
		}
		while(aux!=cabeza);
}
}

      int main(){
    int opcion,edad,codigo;
    string nombre,apellido1,apellido2,cuenta,contrasenna;
    char tipo;
    string estado;
    bool activacion;
    lista List=NULL;
    do
    {
        
        cout << "MENU PRINCIPAL ADMINISTRADOR" <<endl;
        cout << "1. Ingresar un nuevo usuario" <<endl;
        cout << "2. Ver lista de usuarios" <<endl;
        cout << "3. Activar o desactivar una cuenta" <<endl;
        cout << "4. Registrar nuevo doctor" <<endl;
        cout << "5. Eliminar doctor" <<endl;
        cout << "6. Modificar datos de un doctor" <<endl;
        cout << "7. Ingresar paciente" <<endl;    
        cout << "8. Eliminar paciente" <<endl;
        cout << "9. Modificar datos de paciente" <<endl;
        cout << "10. Salir" <<endl;
        cout << "La opcion que desea es: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1: 
                    cout << "Digite el nombre: " <<endl;
                    cin >> nombre;
                    cout << "Digite el primer apellido: " <<endl;
                    cin >> apellido1;
                    cout << "Digite el segundo apellido: " <<endl;
                    cin >> apellido2;
                    cout << "Digite el codigo de usuario: " <<endl;
                    cin >> codigo;
                    cout << "Digite el tipo de usuario: " <<endl;
                    cin >> tipo;
                     cout << "Digite el nombre de la cuenta del usuario: " <<endl;
                    cin >> cuenta;
                     cout << "Digite la contrasenna: " <<endl;
                    cin >> contrasenna;
                     cout << "Digite el estado de la cuenta (true=activada o false=inactiva): " <<endl;
                    cin >> estado;
                    if(estado==)
                    ingresarFinalUsuarios(List,nombre,apellido1,apellido2,codigo,tipo,cuenta,contrasenna,estado);
                    
                    
            break;
            case 2: 
                  mostrar(List);
            break;
            case 3: 
                     cout<<"por hacer"<<endl;
            break;
            case 4:
                    cout<<"por hacer"<<endl;
            break;
            case 5:
                    cout<<"por hacer"<<endl;
            break;
            case 6:
                     cout<<"por hacer"<<endl;
            break;
            case 7:
                     cout<<"por hacer"<<endl;
            break;
             case 8:
                     cout<<"por hacer"<<endl;
            break;
             case 9:
                     cout<<"por hacer"<<endl;
            break;
        }
    }
    while(opcion!=10);
    cout << "Fin del sistema" <<endl;
    }