#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#include<ctime>
#include<cmath>

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
    string estado;
    nodoUsuario *siguiente;
    nodoUsuario *anterior;
};
struct nodoPaciente
{
    string nombre;
    string apellido1;
    string apellido2;
    int cedula;
    int telefono;
    string sintomas;
    string fechaIngreso;
    nodoPaciente *siguiente;
    nodoPaciente *anterior;
};
struct nodoDoctor
{
	
	string nombre;
	string apellido1;
    string apellido2;
    string especialidad;
    int codigoD;
    nodoDoctor *siguiente;
    nodoDoctor *anterior;
};
typedef struct nodoUsuario *lista;
typedef struct nodoPaciente *listaP;
typedef struct nodoDoctor *listaD;

nodoUsuario *crearNodo(string nom,string ap1,string ap2,int cod,char tipoU, string cuen,string con, string es)
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
nodoPaciente *crearNodo(string nom,string ap1,string ap2,int ced,int tel, string sint,string fIng)
{
    nodoPaciente *aux = new (struct nodoPaciente);
    aux->nombre=nom;
    aux->apellido1=ap1;
    aux->apellido2=ap2;
    aux->cedula=ced;
    aux->telefono=tel;
    aux->sintomas=sint;
    aux->fechaIngreso=fIng;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    return aux;
}

nodoDoctor *crearNodo(string nom,string ap1,string ap2,string espec,int codD)
{
    nodoDoctor *aux = new (struct nodoDoctor);
    aux->nombre=nom;
    aux->apellido1=ap1;
    aux->apellido2=ap2;
    aux->especialidad=espec;
    aux->codigoD=codD;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    return aux;
}

//lista circular doble
void ingresarFinalUsuarios(lista &cabeza,string nombre, string apellido1,string apellido2, int codigo, char tipoUsuario, string cuenta, string contrasenna,string estado)
{
    nodoUsuario *nuevo;
    nuevo=crearNodo(nombre,apellido1,apellido2,codigo,tipoUsuario,cuenta,contrasenna,estado);
    

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
        cout<<"Usuario "<<codigo<<" agregado"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    cout<<"Usuario "<<codigo<<" agregado"<<endl;
    }
}


void ingresarFinalPaciente(listaP &cabeza,string nombre, string apellido1,string apellido2,int cedula,int telefono, string sintomas, string fechaIngreso)
{

    nodoPaciente *nuevo;
    nuevo=crearNodo(nombre,apellido1,apellido2,cedula,telefono,sintomas,fechaIngreso);
    

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
        cout<<"Paciente "<<nombre<<" agregado"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    cout<<"Paciente "<<nombre<<" agregado"<<endl;
    }
}

void ingresarFinalDoctor(listaD &cabeza,string nombre, string apellido1,string apellido2,string especialidad, int codigoD)
{
    nodoDoctor *nuevo;
    nuevo=crearNodo(nombre,apellido1,apellido2,especialidad,codigoD);
    

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
        cout<<"Doctor "<<codigoD<<" agregado"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    cout<<"Doctor "<<codigoD<<" agregado"<<endl;
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
            cout<<"Primer apellido: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido: "<<aux->apellido2<<endl;
            cout<<"Codigo: "<<aux->codigo<<endl;
            cout<<"Tipo de usuario: "<<aux->tipoUsuario<<endl;
            cout<<"Contrasenna: "<<aux->contrasenna<<endl;
            cout<<"Estado de la cuenta: "<<aux->estado<<endl;
            
            cout<<"=========================="<<endl;
           aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
}
void mostrarPaciente (listaP cabeza)
{
    listaP aux;
    if (cabeza==NULL)
    cout<<"Lista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
            cout<<"Nombre: "<<aux->nombre<<endl;
            cout<<"Primer apellido: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido: "<<aux->apellido2<<endl;
            cout<<"Cedula: "<<aux->cedula<<endl;
            cout<<"Telefono: "<<aux->telefono<<endl;
            cout<<"Sintomas: "<<aux->sintomas<<endl;
            cout<<"Fecha de ingreso: "<<aux->fechaIngreso<<endl;
            cout<<"=========================="<<endl;
aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
}


//DOCTORES
void mostrarDoctor (listaD cabeza)
{
    listaD aux;
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
            cout<<"Especialidad: "<<aux->especialidad<<endl;
            cout<<"Codigo: "<<aux->codigoD<<endl;
            cout<<"=========================="<<endl;
            
aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
}

void eliminarDoctor(listaD &cabeza,int codigo)
{
	listaD aux;
	
	if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
		aux=cabeza;
		do
		{
			if(aux->codigoD==codigo && aux==cabeza)
			{
				cabeza=aux->siguiente;
				aux->siguiente->anterior =aux->anterior;
				aux->anterior->siguiente=aux->siguiente;
				aux->anterior=NULL;
				aux->siguiente=NULL;			
				delete(aux);		
					cout<<"Doctor"<<codigo<<" eliminado"<<endl;		
				aux=cabeza;
			}
			else
			{
				if(aux->codigoD==codigo && aux!=cabeza)
				{
					aux->anterior->siguiente=aux->siguiente;
					aux->siguiente->anterior=aux->anterior;    
					aux->siguiente=NULL;
					aux->anterior=NULL;      					
					delete(aux);
					cout<<"Doctor"<<codigo<<" eliminado"<<endl;
					aux=cabeza;                         
				}

			}
			aux=aux->siguiente;
		}
		while(aux!=cabeza);
	}	
}

void modificarDoctor(listaD &cabeza,int codigo)
{
	
}

void desactivar (lista &cabeza,int codigoUsuario)
{
    lista aux;
    
    if(cabeza==NULL)
	cout <<"Lista vacia"<<endl;
	else
	{
        aux=cabeza;
        
		
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


	void printStrongNess(string& input)
{
    int n = input.length();
 
    // Checking lower alphabet in string
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
    string normalChars = "abcdefghijklmnopqrstu"
        "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
 
    for (int i = 0; i < n; i++) {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;
 
        size_t special = input.find_first_not_of(normalChars);
        if (special != string::npos)
            specialChar = true;
    }
 
    // Strength of password
    cout << "Strength of password: ";
    if (hasLower && hasUpper && hasDigit &&
        specialChar && (n >= 8))
        cout << "La contrasena si cumple con los requisitos" << endl;
    else 
        cout<< "La contrasena no cumple con los requisitos"<<endl;
    }

	
    int main(){
    int opcion,edad,codigo,codigoUsuario;
    string nombre,apellido1,apellido2,cuenta,contrasenna;
    string sintomas,fechaIngreso;
    string especialidad;
    int cedula,telefono;
    int codigoD;
    char tipo;
    string estado;
    string activacion;
    lista List=NULL;
    listaP ListP=NULL;
    listaD ListD=NULL;
	//string input = " aB4$cfgty";
    //printStrongNess(input);
    //return 0;
  /*
    do
    {
        
        cout << "MENU PRINCIPAL ESTANDAR" <<endl;
        cout << "1. Ingresar un nuevo paciente" <<endl;
        cout << "2. Mostrar pacientes" <<endl;
        cout << "3. Modificar paciente" <<endl;
        cout << "4. Eliminar paciente" <<endl;
        cout << "5. Asignar una cita medica" <<endl;
        cout << "6. Modificar una cita medica" <<endl;
        cout << "7. Eliminar una cita medica" <<endl;
        cout << "8. Salir" <<endl;
        cout << "La opcion que desea es: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1: 
                    cout << "Digite el nombre del paciente: " <<endl;
                    cin >> nombre;
                    cout << "Digite el primer apellido del paciente: " <<endl;
                    cin >> apellido1;
                    cout << "Digite el segundo apellido del paciente: " <<endl;
                    cin >> apellido2;
                    cout << "Digite el DNI del paciente: " <<endl;
                    cin >> cedula;
                    cout << "Digite el telefono  del paciente: " <<endl;
                    cin >> telefono;
                    cout << "Digite los sintomas del paciente: " <<endl;
                    cin >> sintomas;
                    cout << "Digite la fecha de ingreso  del paciente: " <<endl;
                    cin >> fechaIngreso;

                    
                    ingresarFinalPaciente(ListP,nombre,apellido1,apellido2,cedula,telefono,sintomas,fechaIngreso);
                            
            break;
            case 2: 
                  mostrarPaciente(ListP);
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

        }
    }
    while(opcion!=8);
*/

    do
    {
        
        cout << "MENU PRINCIPAL ADMINISTRADOR" <<endl;
        cout << "*************************************" <<endl;
        cout << "1. Ingresar un nuevo usuario" <<endl;
        cout << "2. Ver lista de usuarios" <<endl;
        cout << "3. Activar o desactivar una cuenta" <<endl;
        cout << "*************************************" <<endl;
        cout << "4. Registrar nuevo doctor" <<endl;
        cout << "5. Eliminar doctor" <<endl;
        cout << "6. Modificar datos de un doctor" <<endl;
        cout << "7. Ver lista de doctores" <<endl;
        cout << "*************************************" <<endl;
        cout << "8. Ingresar paciente" <<endl;    
        cout << "9. Eliminar paciente" <<endl;
        cout << "10. Modificar datos de paciente" <<endl;
    	cout << "*************************************" <<endl;
        cout << "11. Salir" <<endl;
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
                     cout << "Digite el estado de la cuenta, activa o inactiva: " <<endl;
                    cin >> activacion;
                    
                    ingresarFinalUsuarios(List,nombre,apellido1,apellido2,codigo,tipo,cuenta,contrasenna,activacion);
                    
                    
                    system("Pause");
            break;
            case 2: 
                  mostrar(List);
                  system("Pause");
            break;
            case 3: 
            cout<<"Digite el codigo del usuario que desea desactivar"<<endl;
       cin>>codigoUsuario;
                     desactivar(List,codigoUsuario);
            break;
            case 4:
                    cout <<"Digite el nombre del doctor:"<<endl;
                    cin >> nombre;
                    cout << "Digite el primer apellido del doctor: " <<endl;
                    cin >> apellido1;
                    cout << "Digite el segundo apellido del doctor: " <<endl;
                    cin >> apellido2;
                    cout << "Digite la especialidad del doctor: " <<endl;
                    cin >> especialidad;
                    codigoD = rand()%500;
                    
                    ingresarFinalDoctor(ListD,nombre,apellido1,apellido2,especialidad,codigoD);

            break;
            case 5:
                   cout<<"Digite el codigo del doctor que desea eliminar"<<endl;
                   cin>>codigoD;
				    eliminarDoctor(ListD,codigoD);
				    system("Pause");
            break;
            case 6:
                     cout<<"por hacer"<<endl;
            break;
            case 7:
            		mostrarDoctor(ListD);
            		system("Pause");
                    //cout<<"por hacer"<<endl;
            break;
             case 8:
                     cout<<"por hacer"<<endl;
            break;
             case 9:
                     cout<<"por hacer"<<endl;
            break;
        }
    }
    while(opcion!=11);
    
    cout << "Fin del sistema" <<endl;
    }
