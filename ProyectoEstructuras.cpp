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
void ingresarFinalUsuarios(lista &cabeza,string nombre, string apellido1,string apellido2, int codigo, char tipoUsuario, string cuenta, string contrasenna,bool estado)
{
    nodoUsuario *nuevo;
    nuevo=crearNodo(nombre,apellido1,apellido2,codigo,tipoUsuario,cuenta,contrasenna,estado);
    
/*Los numeros del 48 al 57 son digitos en ASCII, del 65 al 90 mayusculas, del 97 al 122 minusculas. Los demas rangos son caracteres especiales
  for(int i=0;i<contrasenna.length();i++)
   {
    if (((contrasenna[i]>=33 && contrasenna[i]<=37) || (contrasenna[i]>=58 && contrasenna[i]<=64)||
    (contrasenna[i]>=91 && contrasenna[i]<=96)|| (contrasenna[i]>=123 && contrasenna[i]<=126))&&
       (contrasenna[i]>=48 && contrasenna[i]<=57)&& 
       (contrasenna[i]>=65 && contrasenna[i]<=90)&&      
       (contrasenna[i]>=97 && contrasenna[i]<=122))
        
        {     
          bandera=1;
        }
         
    
  } 
  if (bandera==1)
  {
    cout<<"Contraseña válida"<<endl;
  }
  else
  {
    cout<<"Contraseña invalida"<<endl;
  }
  */
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
    int opcion,edad,codigo;
    string nombre,apellido1,apellido2,cuenta,contrasenna;
    char tipo;
    bool estado;
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
                    ingresarFinalUsuarios(List,nombre,apellido1,apellido2,codigo,tipo,cuenta,contrasenna,estado);
                    cout << "Datos almacenados" <<endl;
                    
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
    
