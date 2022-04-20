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
typedef struct nodoUsuario *lista;

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
typedef struct nodoPaciente *listaP;

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
typedef struct nodoDoctor *listaD;

struct nodoCita{
	
	//int codigoDoctorCita;
	//int cedulaPacienteCita;
	int idCita;
	string sintomas1;
	int anno;
	int mes;
	int dia;
    int hora;
    int minutos;
    nodoCita *siguiente;
    nodoCita *anterior;
    nodoDoctor *doc;
    nodoPaciente *pac;
};
typedef struct nodoCita *listaC;

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

nodoCita *crearNodo(int id,string sin1,int an,int ms,int d,int hor,int min)
{
    nodoCita *aux = new (struct nodoCita);
    aux->idCita=id;
    aux->sintomas1=sin1;
    aux->anno=an;
    aux->mes=ms;
    aux->dia=d;
    aux->hora=hor;
    aux->minutos=min;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    aux->doc=NULL;
    aux->pac=NULL;
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
        cout<<"\n\tPaciente "<<nombre<<" agregado"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    cout<<"\n\tPaciente "<<nombre<<" agregado"<<endl;
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
        cout<<"\n\tDoctor "<<codigoD<<" agregado"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    	cout<<"\n\tDoctor "<<codigoD<<" agregado"<<endl;
    }
}

void mostrar (lista cabeza)
{
    lista aux;
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	cout<<"------------------------"<<endl;
            cout<<"Nombre: "<<aux->nombre<<endl;
            cout<<"Primer apellido: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido: "<<aux->apellido2<<endl;
            cout<<"Codigo: "<<aux->codigo<<endl;
            cout<<"Tipo de usuario: "<<aux->tipoUsuario<<endl;
            cout<<"Contrasenna: "<<aux->contrasenna<<endl;
            cout<<"Estado de la cuenta: "<<aux->estado<<endl;
            cout<<"------------------------"<<endl;
           aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
}

//PACIENTES
void mostrarPaciente (listaP cabeza)
{
    listaP aux;
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	cout<<"------------------------"<<endl;
            cout<<"Nombre: "<<aux->nombre<<endl;
            cout<<"Primer apellido: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido: "<<aux->apellido2<<endl;
            cout<<"Cedula: "<<aux->cedula<<endl;
            cout<<"Telefono: "<<aux->telefono<<endl;
            cout<<"Sintomas: "<<aux->sintomas<<endl;
            cout<<"Fecha de ingreso: "<<aux->fechaIngreso<<endl;
            cout<<"------------------------"<<endl;
aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
}


void eliminarPaciente(listaP &cabeza,int ced)
{
	listaP aux;
	
	if(cabeza==NULL)
	cout <<"\n\tLista vacia"<<endl;
	else
	{
		aux=cabeza;
		do
		{
			if(aux->cedula==ced && aux==cabeza)
			{
				cabeza=aux->siguiente;
				aux->siguiente->anterior =aux->anterior;
				aux->anterior->siguiente=aux->siguiente;
				aux->anterior=NULL;
				aux->siguiente=NULL;			
				delete(aux);		
					cout<<"\n\tPaciente "<<ced<<" eliminado"<<endl;		
				aux=cabeza;
			}
			else
			{
				if(aux->cedula==ced && aux!=cabeza)
				{
					aux->anterior->siguiente=aux->siguiente;
					aux->siguiente->anterior=aux->anterior;    
					aux->siguiente=NULL;
					aux->anterior=NULL;      					
					delete(aux);
					cout<<"\n\tPaciente "<<ced<<" eliminado"<<endl;
					aux=cabeza;                         
				}

			}
			aux=aux->siguiente;
		}
		while(aux!=cabeza);
	}
}

void modificarPaciente(listaP &cabeza,int cedula)
{
	string nombren,apellido1n,apellido2n,sintomasn,fechan;

	int opcion,telefonon;
	listaP aux;
	
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	if(aux->cedula==cedula && aux==cabeza)
			{
		    cout<<"Nombre Actual: "<<aux->nombre<<endl;
            cout<<"Primer apellido actual: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido actual: "<<aux->apellido2<<endl;
            cout<<"Numero de telefono actual: "<<aux->telefono<<endl;
            cout<<"Sintomas actuales: "<<aux->sintomas<<endl;
            cout<<"Fecha de ingreso actual: "<<aux->fechaIngreso<<endl;
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo nombre: "<<endl;
            cin>>nombren;         
            cout<<"Nuevo primer apellido: "<<endl;
            cin>>apellido1n;
            cout<<"Nuevo segundo apellido: "<<endl;
            cin>>apellido2n;
            cout<<"Nuevo numero de telefono: "<<endl;
            cin>>telefonon;
            cout<<"Nuevos sintomas: "<<endl;
            cin>>sintomasn;
            cout<<"Nueva fecha de ingreso: "<<endl;
            cin>>fechan;
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
             
            cout<<"Desea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
            cin>>opcion;
             
            if(opcion==1)  {
				   		
			aux->nombre=nombren;
            aux->apellido1=apellido1n;
            aux->apellido2=apellido2n;
            aux->telefono=telefonon;
            aux->sintomas=sintomasn;
            aux->fechaIngreso=fechan;
            
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo nombre modificado: "<<nombren<<endl;
            cout<<"Nuevo primer apellido modificado: "<<apellido1n<<endl;
            cout<<"Nuevo segundo apellido modificado: "<<apellido2n<<endl;
            cout<<"Nuevo telefono modificado: "<<telefonon<<endl;
            cout<<"Nuevos sintomas modificados: "<<sintomasn<<endl;
            cout<<"Nueva fecha de ingreso modificada: "<<fechan<<endl;

            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
		    }
		    else if(opcion==2)
		    {
		    	cout<<"\n\tLos datos no fueron guardados"<<endl;
			}
			else{
			cout<<"\n\tOpcion invalida"<<endl;	
			}		
			}
			else
			{
				if(aux->cedula==cedula && aux!=cabeza)
				{
		cout<<"Nombre Actual: "<<aux->nombre<<endl;
            cout<<"Primer apellido actual: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido actual: "<<aux->apellido2<<endl;
            cout<<"Numero de telefono actual: "<<aux->telefono<<endl;
            cout<<"Sintomas actuales: "<<aux->sintomas<<endl;
            cout<<"Fecha de ingreso actual: "<<aux->fechaIngreso<<endl;
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo nombre: "<<endl;
            cin>>nombren;         
            cout<<"Nuevo primer apellido: "<<endl;
            cin>>apellido1n;
            cout<<"Nuevo segundo apellido: "<<endl;
            cin>>apellido2n;
            cout<<"Nuevo numero de telefono: "<<endl;
            cin>>telefonon;
            cout<<"Nuevos sintomas: "<<endl;
            cin>>sintomasn;
            cout<<"Nueva fecha de ingreso: "<<endl;
            cin>>fechan;
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
             
            cout<<"\n\tDesea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
            cin>>opcion;
             
            if(opcion==1)  {
				   		
			aux->nombre=nombren;
            aux->apellido1=apellido1n;
            aux->apellido2=apellido2n;
            aux->telefono=telefonon;
            aux->sintomas=sintomasn;
            aux->fechaIngreso=fechan;
            
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo nombre modificado: "<<nombren<<endl;
            cout<<"Nuevo primer apellido modificado: "<<apellido1n<<endl;
            cout<<"Nuevo segundo apellido modificado: "<<apellido2n<<endl;
            cout<<"Nuevo telefono modificado: "<<telefonon<<endl;
            cout<<"Nuevos sintomas modificados: "<<sintomasn<<endl;
            cout<<"Nueva fecha de ingreso modificada: "<<fechan<<endl;

            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
		    
		    }
		    else if(opcion==2)
		    {
		    	cout<<"\n\tLos datos no fueron guardados"<<endl;
			}
			else{
			cout<<"\n\tOpcion invalida"<<endl;	
			}	                     
				}

			}            
			aux=aux->siguiente;
        }
		while(aux!=cabeza); 
    }	
}





//DOCTORES
void mostrarDoctor (listaD cabeza)
{
	int contador = 0;

    listaD aux;
    
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	cout<<"------------------------"<<endl;
            cout<<"Nombre: "<<aux->nombre<<endl;
            cout<<"Primer apelldio: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido: "<<aux->apellido2<<endl;
            cout<<"Especialidad: "<<aux->especialidad<<endl;
            cout<<"Codigo: "<<aux->codigoD<<endl;
            cout<<"------------------------"<<endl;
        	contador=contador+1;
			aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
    		cout<<"\n\tDoctores en total: "<<contador<<"\n\n";
}

void eliminarDoctor(listaD &cabeza,int codigo = 0)
{
	listaD aux;
	
	if(cabeza==NULL)
	cout <<"\n\tLista vacia"<<endl;
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
					cout<<"\n\tDoctor "<<codigo<<" eliminado"<<endl;		
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
					cout<<"\n\tDoctor "<<codigo<<" eliminado"<<endl;
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
	string nombren,apellido1n,apellido2n,especialidadn;
	bool confirmacion=false;
	int opcion;
	listaD aux;
	
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	if(aux->codigoD==codigo && aux==cabeza)
			{
		    cout<<"Nombre Actual: "<<aux->nombre<<endl;
            cout<<"Primer apellido actual: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido actual: "<<aux->apellido2<<endl;
            cout<<"Especialidad actual: "<<aux->especialidad<<endl;
            cout<<"Codigo: "<<aux->codigoD<<endl;
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo nombre: "<<endl;
            cin>>nombren;         
            cout<<"Nuevo primer apellido: "<<endl;
            cin>>apellido1n;
            cout<<"Nuevo segundo apellido: "<<endl;
            cin>>apellido2n;
            cout<<"Nueva especialidad: "<<endl;
            cin>>especialidadn;
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
             
            cout<<"\n\tDesea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
            cin>>opcion;
             
            if(opcion==1)  {
				   		
			aux->nombre=nombren;
            aux->apellido1=apellido1n;
            aux->apellido2=apellido2n;
            aux->especialidad=especialidadn;
            
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo nombre modificado: "<<nombren<<endl;
            cout<<"Nuevo primer apellido modificado: "<<apellido1n<<endl;
            cout<<"Nuevo segundo apellido modificado: "<<apellido2n<<endl;
            cout<<"Nuevo especialidad modificado: "<<especialidadn<<endl;
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
		    }
		    else if(opcion==2)
		    {
		    	cout<<"\n\tLos datos no fueron guardados"<<endl;
			}
			else{
			cout<<"\n\tOpcion invalida"<<endl;	
			}		
			}
			else
			{
				if(aux->codigoD==codigo && aux!=cabeza)
				{
			cout<<"Nombre Actual: "<<aux->nombre<<endl;
            cout<<"Primer apellido actual: "<<aux->apellido1<<endl;
            cout<<"Segundo apellido actual: "<<aux->apellido2<<endl;
            cout<<"Especialidad actual: "<<aux->especialidad<<endl;
            cout<<"Codigo: "<<aux->codigoD<<endl;
            
            cout<<"------------------------"<<endl;
            cout<<"Nuevo nombre: "<<endl;
            cin>>nombren;         
            cout<<"Nuevo primer apellido: "<<endl;
            cin>>apellido1n;
            cout<<"Nuevo segundo apellido: "<<endl;
            cin>>apellido2n;
            cout<<"Nueva especialidad: "<<endl;
            cin>>especialidadn;
             
             cout<<"\n\tDesea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
             cin>>opcion;
             
            if(opcion==1)  {
			     
		
			aux->nombre=nombren;
            aux->apellido1=apellido1n;
            aux->apellido2=apellido2n;
            aux->especialidad=especialidadn;
            
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo nombre modificado: "<<nombren<<endl;
            cout<<"Nuevo primer apellido modificado: "<<apellido1n<<endl;
            cout<<"Nuevo segundo apellido modificado: "<<apellido2n<<endl;
            cout<<"Nuevo especialidad modificado: "<<especialidadn<<endl;
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
            
		    }
		    else if(opcion==2)
		    {
		    	cout<<"\n\tLos datos no fueron guardados"<<endl;
			}
			else{
			cout<<"\n\tOpcion invalida"<<endl;	
			}	                     
				}

			}            
			aux=aux->siguiente;
        }
		while(aux!=cabeza); 
    }	
}

void modificarEstado(lista &cabeza,int codigoUsuario)
{
	string estadon;
	int opcion;
	lista aux;
	
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	if(aux->codigo==codigoUsuario && aux==cabeza)
			{
			cout<<"Codigo del usuario: "<<aux->codigo<<endl;
			cout<<"Nombre del usuario: "<<aux->nombre<<" "<<aux->apellido1<<endl;
			cout<<"Estado actual: "<<aux->estado<<endl;
			
			cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo estado:\n(activo o inactivo) "<<endl;
            cin>>estadon;         
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
             
            cout<<"\n\tDesea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
            cin>>opcion;
			
            if(opcion==1)	{
				   		
			aux->estado=estadon;

            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo estado modificado: "<<estadon<<endl;
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
		    }
		    else if(opcion==2)
		    	{
		    	cout<<"\n\tLos cambios no fueron guardados"<<endl;
				}
				
			else{
			cout<<"\n\tOpcion inválida"<<endl;	
				}		
			}
			else
			{
			if(aux->codigo==codigoUsuario && aux!=cabeza)
				{
					
			cout<<" "<<endl;
			cout<<"Codigo del usuario: "<<aux->codigo<<endl;
			cout<<"Nombre del usuario: "<<aux->nombre<<" "<<aux->apellido1<<endl;
			cout<<"Estado actual: "<<aux->estado<<endl;
			cout<<" "<<endl;
			
			cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo estado:\n(activo o inactivo) "<<endl;
            cin>>estadon;         
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
             
             cout<<"\n\tDesea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
             cin>>opcion;
             
            if(opcion==1)  {
			     
		
			aux->estado=estadon;
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"Nuevo estado modificado: "<<estadon<<endl;
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
            
		    }
		    else if(opcion==2)
		    {
		    	cout<<"\n\tLos cambios no fueron guardados"<<endl;
			}
			else{
			cout<<"\n\tOpcion inválida"<<endl;	
			}	                     
				}

			}            
			aux=aux->siguiente;
        }
		while(aux!=cabeza); 
    }	
}


void desactivar (lista &cabeza,int codigoUsuario)
{
    lista aux;
    
    if(cabeza==NULL)
	cout <<"\n\tLista vacia"<<endl;
	else
	{
        aux=cabeza;
        
		
		do
		{
			if(aux->codigo==codigoUsuario && aux==cabeza)
			{
				cabeza=aux->siguiente;
				aux->siguiente->anterior=aux->anterior;
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
	


	void printStrongNess(string& input,int& check)
{
    int n = input.length();
    check = 0;
 
 
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
    cout << "\n\n\tComplejidad de contrasena: ";
    if (hasLower && hasUpper && hasDigit &&
        specialChar && (n >= 8)){
        cout << "\n\tLa contrasena si cumple con los requisitos, puede continuar con el registro\n\n" <<  endl;
        check = 1;
    } else {
        cout<< "\n\tLa contrasena no cumple con los requisitos, debe ser mas compleja\n\n"<<endl;
        check = 0;
    }
};

void mostrarCitas (listaC cabeza)
{
	int contador = 0;

    listaC aux;
    
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	cout<<"------------------------"<<endl;
            cout<<"ID : "<<aux->idCita<<endl;
            cout<<"Sintomas: "<<aux->sintomas1<<endl;
            cout<<"Anno: "<<aux->anno<<endl;
            cout<<"Mes: "<<aux->mes<<endl;
            cout<<"Dia: "<<aux->dia<<endl;
            cout<<"Hora: "<<aux->hora<<endl;
            cout<<"Minuto: "<<aux->minutos<<endl;
            cout<<"------------------------"<<endl;
        	contador=contador+1;
			aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
    		cout<<"\n\tCitas en total: "<<contador<<"\n\n";
}

void asignarCita(listaC &cabeza,int idCita, string sintomas1,int anno,int mes,int dia, int hora,int minutos)
{
	nodoCita *nuevo;
    nuevo=crearNodo(idCita,sintomas1,anno,mes,dia,hora,minutos);

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
        cout<<"\n\tCita "<<"aa"<<" agregado"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
        cout<<"\n\tCita "<<"aa"<<" agregado"<<endl;
    };
	
    
    
}
	
    int main(){
    	
	string sintomas1;
	int mes;
		
    int opcion = 0,edad = 0,codigo = 0,codigoUsuario = 0;
    string nombre,apellido1,apellido2,cuenta,contrasenna;
    string sintomas,fechaIngreso;
    string especialidad;
    int cedula = 0,telefono = 0;
    int codigoD = 0;
    char tipo;
    string estado;
    string activacion;
    lista List=NULL;
    listaP ListP=NULL;
    listaD ListD=NULL;
    listaC ListC=NULL;
    
    ingresarFinalUsuarios(List,"Valeria","Soto","Corrales",703210563,'A',"Vales","Vale123!","inactivo");
    ingresarFinalUsuarios(List,"Diego","Colorado","Murillo",708910891,'E',"diegoma","Diego123!","activo");
    ingresarFinalPaciente(ListP,"Carolina","Chinchilla","Solis",702360763,87671212,"Fiebre","12/02/2020");
    ingresarFinalDoctor(ListD,"Juan","Guadamuz","Fernandez","Dermatologo",1);
	ingresarFinalDoctor(ListD,"Luis","Monge","Abarca","Dentista",1);
    ingresarFinalDoctor(ListD,"Rodrigo","Guevara","Hidalgo","Cirujano",1);
    ingresarFinalDoctor(ListD,"Jose","Quiros","Meneses","Psicologo",1);
    asignarCita(ListC,1,"fractura",2020,12,10,20,30);
    
    int c = 0;
	//string input = " aB4$cfgty";
    //printStrongNess(input);
    //return 0;

    do
    {
        
        cout << "MENU PRINCIPAL ESTANDAR" <<endl;
        cout << "1. Ingresar un nuevo paciente" <<endl;
        cout << "2. Mostrar pacientes" <<endl;
        cout << "3. Modificar paciente" <<endl;
        cout << "4. Eliminar paciente" <<endl;
        cout << "5. Asignar una cita medica" <<endl;
        cout << "6. Modificar una cita medica (Insertar doctor)" <<endl;
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
                     
                    cout<<"Digite el numero de cedula del paciente que desea modificar"<<endl;
                    cin>>cedula;
                    modificarPaciente(ListP,cedula);
            break;
            case 4:
                    cout<<"Digite la cedula del paciente que desea eliminar"<<endl;
                    cin>>cedula;
					eliminarPaciente(ListP,cedula);
					mostrarPaciente(ListP);
					 system("Pause");
            break;
            case 5:
                    cout<<"por hacer"<<endl;
            break;
            case 6:
                    cout<<"por hacer"<<endl;
            break;
            case 7:
                	cout<<"por hacer"<<endl;
                	mostrarCitas(ListC);
                	
            break;

        }
    }
    while(opcion!=8);

/*
    do
    {
        
		cout<<"\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n\tMENU PRINCIPAL ADMINISTRADOR\t";
		cout<<"\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
        cout << "\t 1: Ingresar un nuevo usuario" <<endl;
        cout << "\t 2: Ver lista de usuarios" <<endl;
        cout << "\t 3: Activar o desactivar una cuenta\n\n" <<endl;

        cout << "\t 4: Registrar nuevo doctor" <<endl;
        cout << "\t 5: Eliminar doctor" <<endl;
        cout << "\t 6: Modificar datos de un doctor" <<endl;
        cout << "\t 7: Ver lista de doctores\n\n" <<endl;

        cout << "\t 8: Ingresar paciente" <<endl; 
		 cout <<"\t 9: Ver lista de pacientes" <<endl;    
        cout << "\t10: Eliminar paciente" <<endl;
        cout << "\t11: Modificar datos de paciente\n\n" <<endl;

        cout << "\t12. Salir\n\n" <<endl;
        cout << "\tLa opcion que desea es: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1: 
                    cout << "\n\tDigite el nombre: ";
                    cin >> nombre;
                    cout << "\tDigite el primer apellido: ";
                    cin >> apellido1;
                    cout << "\tDigite el segundo apellido: ";
                    cin >> apellido2;
                    cout << "\tDigite el codigo de usuario: ";
                    cin >> codigo;
                    cout << "\tDigite el tipo de usuario: ";
                    cin >> tipo;
                    cout << "\tDigite el nombre de la cuenta del usuario: ";
                    cin >> cuenta;
                    cout << "\tDigite la contrasenna: ";
                    do{
                    cin >> contrasenna;
                    printStrongNess(contrasenna,c);
                    }while(c!=1);
                    
                    cout << "\tDigite el estado de la cuenta, activa o inactiva: ";
                    cin >> activacion;        
                    ingresarFinalUsuarios(List,nombre,apellido1,apellido2,codigo,tipo,cuenta,contrasenna,activacion); 
                    cout << "\n\t"; system("Pause");
            break;
            case 2: 
            
                  mostrar(List);
                  cout << "\n\t"; system("Pause");
                  
            break;
            case 3: 
            
            cout<<"\n\tDigite el codigo del usuario que desea activar o desactivar: ";
       		cin>>codigoUsuario;
       		modificarEstado(List,codigoUsuario);
       		cout << "\n\t"; system("Pause");
                    //desactivar(List,codigoUsuario);
            break;
            case 4:
                    cout << "\n\tDigite el nombre del doctor: ";
                    cin >> nombre;
                    cout << "\tDigite el primer apellido del doctor: ";
                    cin >> apellido1;
                    cout << "\tDigite el segundo apellido del doctor: ";
                    cin >> apellido2;
                    cout << "\tDigite la especialidad del doctor: ";
                    cin >> especialidad;
                    codigoD = rand()%500;
                    
                    ingresarFinalDoctor(ListD,nombre,apellido1,apellido2,especialidad,codigoD);
                    
                    cout << "\n\t"; system("Pause");
            		break;
            case 5:
            	
                    cout<<"\n\tDigite el codigo del doctor que desea eliminar: ";
                    cin>>codigoD;
				    eliminarDoctor(ListD,codigoD);
				    //	mostrarDoctor(ListD);
				    cout << "\n\t"; system("Pause");
            		break;
            case 6:
                     cout<<"\n\tDigite el codigo del doctor que desea modificar: ";
                     cin>>codigoD;
                     modificarDoctor(ListD,codigoD);
                     cout << "\n\t"; system("Pause");
            break;
            case 7:
            		mostrarDoctor(ListD);
            		cout << "\n\t"; system("Pause");
                    //cout<<"por hacer"<<endl;
            break;
             case 8:
                    cout <<"Digite el nombre del paciente:"<<endl;
                    cin >> nombre;
                    cout << "Digite el primer apellido del paciente: " <<endl;
                    cin >> apellido1;
                    cout << "Digite el segundo apellido del paciente: " <<endl;
                    cin >> apellido2;
                    cout<<"Digite el numero de cedula del paciente: "<<endl;
                    cin>>cedula;
                    cout << "Digite el numero de telefono del paciente: " <<endl;
                    cin >> telefono;
					cout<<"Digite los sintomas del paciente: "<<endl;	
					cin>>sintomas;
					cout<<"Digite la fecha de ingreso (DD/MM/YYYY): "<<endl;
					cin>>fechaIngreso;			
					ingresarFinalPaciente(ListP,nombre,apellido1,apellido2,cedula,telefono,sintomas,fechaIngreso);
					 cout << "\n\t"; system("Pause");
            break;
             case 9:
                     mostrarPaciente(ListP);
                      cout << "\n\t"; system("Pause");
            break;
            case 10:
                      cout<<"Digite la cedula del paciente que desea eliminar"<<endl;
                    cin>>cedula;
					eliminarPaciente(ListP,cedula);
					mostrarPaciente(ListP);
					 cout << "\n\t"; system("Pause");
            break;
            case 11:
                      cout<<"Digite el numero de cedula del paciente que desea modificar"<<endl;
                    cin>>cedula;
                    modificarPaciente(ListP,cedula);
                    cout << "\n\t"; system("Pause");
					
            break;
        }
    }
    while(opcion!=12);
    */
    
    cout << "Fin del sistema" <<endl;
    }
