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
    int sintomas;
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
	
	int idCita;
	int sintomas1;
	int anno;
	int mes;
	int dia;
    int hora;
    int minutos;
    int doc1;
    int pac1;
    nodoCita *siguiente;
    nodoCita *anterior;
    nodoDoctor *doc;
    nodoPaciente *pac;
};
typedef struct nodoCita *listaC;

struct nodoExpediente {
	string nombre;
	string apellido1;
    string apellido2;
    int anno;
    int mes;
    int dia;
    int codigoD;
    int sintomas;
    string medicamentos;
    string examen;
    nodoExpediente *siguiente;
    nodoExpediente *anterior;
};
typedef struct nodoExpediente *listaE;

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
nodoPaciente *crearNodo(string nom,string ap1,string ap2,int ced,int tel, int sint,string fIng)
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

nodoCita *crearNodo(int id,int sin1,int an,int ms,int d,int hor,int min,int doc,int pac)
{
    nodoCita *aux = new (struct nodoCita);
   //aux->cedulaPacienteCita=ced;
    aux->idCita=id;
    aux->sintomas1=sin1;
    aux->anno=an;
    aux->mes=ms;
    aux->dia=d;
    aux->hora=hor;
    aux->minutos=min;
    aux->doc1=doc;
    aux->pac1=pac;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    aux->doc=NULL;
    aux->pac=NULL;
    return aux;
}

nodoExpediente *crearExpediente(string nom,string ap1,string ap2,int an,int ms,int di,int codD,int sint,string med,string ex)
{
	nodoExpediente *aux = new(struct nodoExpediente);
	aux->nombre=nom;
	aux->apellido1=ap1;
	aux->apellido2=ap2;
	aux->anno=an;
	aux->mes=ms;
	aux->dia=di;
	aux->codigoD=codD;
	aux->sintomas=sint;
	aux->medicamentos=med;
	aux->examen=ex;
	aux->siguiente=NULL;
	aux->anterior=NULL;	
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
        cout<<"\n\tEl usuario con cedula "<<codigo<<" fue agregado"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    cout<<"\n\tEl usuario con cedula "<<codigo<<" fue agregado"<<endl;
    }
}

void ingresarFinalUsuariosSinNotf(lista &cabeza,string nombre, string apellido1,string apellido2, int codigo, char tipoUsuario, string cuenta, string contrasenna,string estado)
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
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    }
}

void ingresarFinalPaciente(listaP &cabeza,string nombre, string apellido1,string apellido2,int cedula,int telefono, int sintomas, string fechaIngreso)
{

    nodoPaciente *nuevo;
    nuevo=crearNodo(nombre,apellido1,apellido2,cedula,telefono,sintomas,fechaIngreso);
    

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
        cout<<"\n\tPaciente "<<nombre<<" fue agregado"<<endl;
        cout << "\n\t"; system("Pause");
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    	cout<<"\n\tPaciente "<<nombre<<" fue agregado"<<endl;
    	cout << "\n\t"; system("Pause");
    }
}

void ingresarFinalPacienteSinNotf(listaP &cabeza,string nombre, string apellido1,string apellido2,int cedula,int telefono, int sintomas, string fechaIngreso)
{

    nodoPaciente *nuevo;
    nuevo=crearNodo(nombre,apellido1,apellido2,cedula,telefono,sintomas,fechaIngreso);
    

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
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
        cout<<"\n\tDoctor con el codig o"<<codigoD<<" fue agregado"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    	cout<<"\n\tDoctor con el codigo "<<codigoD<<" fue agregado"<<endl;
    }
}

void ingresarFinalDoctorSinNoft(listaD &cabeza,string nombre, string apellido1,string apellido2,string especialidad, int codigoD)
{
    nodoDoctor *nuevo;
    nuevo=crearNodo(nombre,apellido1,apellido2,especialidad,codigoD);
    

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    }
}

void mostrar (lista cabeza)
{
    lista aux;
    if (cabeza==NULL)
    cout<<"\n\tLista vacia de usuarios"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	cout<<"\n\t------------------------"<<endl;
            cout<<"\tNombre: "<<aux->nombre<<endl;
            cout<<"\tPrimer apellido: "<<aux->apellido1<<endl;
            cout<<"\tSegundo apellido: "<<aux->apellido2<<endl;
            cout<<"\tCedula: "<<aux->codigo<<endl;
            cout<<"\tTipo de usuario: "<<aux->tipoUsuario<<endl;
            cout<<"\tContrasenna: "<<aux->contrasenna<<endl;
            cout<<"\tEstado de la cuenta: "<<aux->estado<<endl;
            cout<<"\t------------------------\n"<<endl;
           aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
}

//PACIENTES
void mostrarPaciente (listaP cabeza)
{
	string defsinto;
    listaP aux;
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	if (aux->sintomas==1){
        		defsinto="Gangrena";
			}else if(aux->sintomas==2){
				defsinto="Carie";
			}else if(aux->sintomas==3){
				defsinto="Fractura";
			}else if(aux->sintomas==4){
				defsinto="Depresión";
			}
        	
        	cout<<"\n\t------------------------"<<endl;
            cout<<"\tNombre: "<<aux->nombre<<endl;
            cout<<"\tPrimer apellido: "<<aux->apellido1<<endl;
            cout<<"\tSegundo apellido: "<<aux->apellido2<<endl;
            cout<<"\tCedula: "<<aux->cedula<<endl;
            cout<<"\tTelefono: "<<aux->telefono<<endl;
            cout<<"\tSintomas: "<<defsinto<<" ["<<aux->sintomas<<"] "<<endl;
            cout<<"\tFecha de ingreso: "<<aux->fechaIngreso<<endl;
            cout<<"\t------------------------\n\n"<<endl;
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
	string nombren,apellido1n,apellido2n,fechan;

	int opcion,telefonon,sintomasn;
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
		    cout<<"\tNombre Actual: "<<aux->nombre<<endl;
            cout<<"\tPrimer apellido actual: "<<aux->apellido1<<endl;
            cout<<"\tSegundo apellido actual: "<<aux->apellido2<<endl;
            cout<<"\tNumero de telefono actual: "<<aux->telefono<<endl;
            cout<<"\tSintomas actuales: "<<aux->sintomas<<endl;
            cout<<"\tFecha de ingreso actual: "<<aux->fechaIngreso<<endl;
            cout<<" "<<endl;
            cout<<"\t------------------------"<<endl;
            cout<<"\tNuevo nombre: "<<endl;
            cin>>nombren;         
            cout<<"\tNuevo primer apellido: "<<endl;
            cin>>apellido1n;
            cout<<"\tNuevo segundo apellido: "<<endl;
            cin>>apellido2n;
            cout<<"\tNuevo numero de telefono: "<<endl;
            cin>>telefonon;
            cout<<"\tNuevos sintomas:\n\n \t\t[1]Gangrena \n \t\t[2]Carie\n \t\t[3]Fractura\n \t\t[4]Depresion\n "<<endl;
            cin>>sintomasn;
            cout<<"\tNueva fecha de ingreso: "<<endl;
            cin>>fechan;
            cout<<"\t------------------------"<<endl;
            cout<<" "<<endl;
             
            cout<<"\tDesea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
            cin>>opcion;
             
            if(opcion==1)  {
				   		
			aux->nombre=nombren;
            aux->apellido1=apellido1n;
            aux->apellido2=apellido2n;
            aux->telefono=telefonon;
            aux->sintomas=sintomasn;
            aux->fechaIngreso=fechan;
            
            
            cout<<" "<<endl;
            cout<<"\t------------------------"<<endl;
            cout<<"\tNuevo nombre modificado: "<<nombren<<endl;
            cout<<"\tNuevo primer apellido modificado: "<<apellido1n<<endl;
            cout<<"\tNuevo segundo apellido modificado: "<<apellido2n<<endl;
            cout<<"\tNuevo telefono modificado: "<<telefonon<<endl;
            cout<<"\tNuevos sintomas modificados: "<<sintomasn<<endl;
            cout<<"\tNueva fecha de ingreso modificada: "<<fechan<<endl;

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
		cout<<"\tNombre Actual: "<<aux->nombre<<endl;
            cout<<"\tPrimer apellido actual: "<<aux->apellido1<<endl;
            cout<<"\tSegundo apellido actual: "<<aux->apellido2<<endl;
            cout<<"\tNumero de telefono actual: "<<aux->telefono<<endl;
            cout<<"\tSintomas actuales: "<<aux->sintomas<<endl;
            cout<<"\tFecha de ingreso actual: "<<aux->fechaIngreso<<endl;
            cout<<" "<<endl;
            cout<<"\t------------------------"<<endl;
            cout<<"\tNuevo nombre: "<<endl;
            cin>>nombren;         
            cout<<"\tNuevo primer apellido: "<<endl;
            cin>>apellido1n;
            cout<<"\tNuevo segundo apellido: "<<endl;
            cin>>apellido2n;
            cout<<"\tNuevo numero de telefono: "<<endl;
            cin>>telefonon;
            cout<<"\tNuevos sintomas: "<<endl;
            cin>>sintomasn;
            cout<<"\tNueva fecha de ingreso: "<<endl;
            cin>>fechan;
            cout<<"\t------------------------"<<endl;
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
            cout<<"\t------------------------"<<endl;
            cout<<"\tNuevo nombre modificado: "<<nombren<<endl;
            cout<<"\tNuevo primer apellido modificado: "<<apellido1n<<endl;
            cout<<"\tNuevo segundo apellido modificado: "<<apellido2n<<endl;
            cout<<"\tNuevo telefono modificado: "<<telefonon<<endl;
            cout<<"\tNuevos sintomas modificados: "<<sintomasn<<endl;
            cout<<"\tNueva fecha de ingreso modificada: "<<fechan<<endl;

            cout<<"\t------------------------"<<endl;
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
        		
        
        	cout<<"\n\t------------------------"<<endl;
            cout<<"\tNombre: "<<aux->nombre<<" "<<aux->apellido1<<" "<<aux->apellido2;
            cout<<"\n\tEspecialidad: "<<aux->especialidad<<endl;
            cout<<"\tCodigo: "<<aux->codigoD<<endl;
            cout<<"\t------------------------\n"<<endl;
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

int buscarSintoma(listaP cabeza, int cedulaRet)
{
	int sintomaRetorno=0;
	listaP aux;
	
	if (cabeza==NULL)
    cout<<"\n\tLista vacia sintoma"<<endl;
    else
	{
        aux=cabeza;
        do
        {
        	if(aux->cedula==cedulaRet && aux==cabeza)
				{
		    		//cout<<"\tSintoma 1: "<<aux->sintomas<<endl;
					sintomaRetorno=aux->sintomas;
				}
			else
			{
				if(aux->cedula==cedulaRet && aux!=cabeza)
				{
					//cout<<"\tSintoma 2: "<<aux->sintomas<<endl;	
					sintomaRetorno=aux->sintomas;

				}

			}            
			aux=aux->siguiente;
        }
		while(aux!=cabeza); 
    }
    return sintomaRetorno;
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
		    cout<<"\tNombre Actual: "<<aux->nombre<<endl;
            cout<<"\tPrimer apellido actual: "<<aux->apellido1<<endl;
            cout<<"\tSegundo apellido actual: "<<aux->apellido2<<endl;
            cout<<"\tEspecialidad actual: "<<aux->especialidad<<endl;
            cout<<"\tCodigo: "<<aux->codigoD<<endl;
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"\tNuevo nombre: "<<endl;
            cin>>nombren;         
            cout<<"\tNuevo primer apellido: "<<endl;
            cin>>apellido1n;
            cout<<"\tNuevo segundo apellido: "<<endl;
            cin>>apellido2n;
            cout<<"\tNueva especialidad: "<<endl;
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
            cout<<"\tNuevo nombre modificado: "<<nombren<<endl;
            cout<<"\tNuevo primer apellido modificado: "<<apellido1n<<endl;
            cout<<"\tNuevo segundo apellido modificado: "<<apellido2n<<endl;
            cout<<"\tNuevo especialidad modificado: "<<especialidadn<<endl;
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
			cout<<"\tNombre Actual: "<<aux->nombre<<endl;
            cout<<"\tPrimer apellido actual: "<<aux->apellido1<<endl;
            cout<<"\tSegundo apellido actual: "<<aux->apellido2<<endl;
            cout<<"\tEspecialidad actual: "<<aux->especialidad<<endl;
            cout<<"\tCodigo: "<<aux->codigoD<<endl;
            
            cout<<"------------------------"<<endl;
            cout<<"\tNuevo nombre: "<<endl;
            cin>>nombren;         
            cout<<"\tNuevo primer apellido: "<<endl;
            cin>>apellido1n;
            cout<<"\tNuevo segundo apellido: "<<endl;
            cin>>apellido2n;
            cout<<"\tNueva especialidad: "<<endl;
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
            cout<<"\tNuevo nombre modificado: "<<nombren<<endl;
            cout<<"\tNuevo primer apellido modificado: "<<apellido1n<<endl;
            cout<<"\tNuevo segundo apellido modificado: "<<apellido2n<<endl;
            cout<<"\tNuevo especialidad modificado: "<<especialidadn<<endl;
            cout<<"\t------------------------"<<endl;
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
	
    if (cabeza==NULL){
	
    cout<<"\n\tUsuario inexistente"<<endl;
	}

    else
    {
        aux=cabeza;
        do
        {
        	if(aux->codigo==codigoUsuario && aux==cabeza)
			{
			cout<<"\tCedula del usuario: "<<aux->codigo<<endl;
			cout<<"\tNombre del usuario: "<<aux->nombre<<" "<<aux->apellido1<<endl;
			cout<<"\tEstado actual: "<<aux->estado<<endl;
			
			cout<<" "<<endl;
            cout<<"\t------------------------"<<endl;
            cout<<"\tNuevo estado:\n(activo/inactivo) "<<endl;
            cin>>estadon;         
            cout<<"\t------------------------"<<endl;
            cout<<" "<<endl;
             
            cout<<"\n\tDesea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
            cin>>opcion;
			
            if(opcion==1)	{
				   		
			aux->estado=estadon;

            cout<<" "<<endl;
            cout<<"\t------------------------"<<endl;
            cout<<"\tNuevo estado modificado: "<<estadon<<endl;
            cout<<"\t------------------------"<<endl;
            cout<<" "<<endl;
		    }
		    else if(opcion==2)
		    	{
		    	cout<<"\n\tLos cambios no fueron guardados\n"<<endl;
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
			cout<<"\tCodigo del usuario: "<<aux->codigo<<endl;
			cout<<"\tNombre del usuario: "<<aux->nombre<<" "<<aux->apellido1<<endl;
			cout<<"\tEstado actual: "<<aux->estado<<endl;
			cout<<" "<<endl;
			
			cout<<" "<<endl;
            cout<<"\t------------------------"<<endl;
            cout<<"\tNuevo estado:\n(activo o inactivo) "<<endl;
            cin>>estadon;         
            cout<<"\t------------------------"<<endl;
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
        	cout<<"\n\t------------------------"<<endl;
            cout<<"\tID de la cita : "<<aux->idCita<<endl;
            cout<<"\tSintomas del paciente: "<<aux->sintomas1<<endl;
            cout<<"\tFecha: "<<aux->dia<<"/"<<aux->mes<<"/"<<aux->anno<<endl;
            cout<<"\tHora: "<<aux->hora<<":"<<aux->minutos<<endl;
            cout<<"\tID Doctor: "<<aux->doc1<<endl;
            cout<<"\tDNI Paciente: "<<aux->pac1<<endl;
            cout<<"\t------------------------\n"<<endl;
        	contador=contador+1;
			aux=aux->siguiente;

        } 
        while (aux!=cabeza);
        
    }
    		cout<<"\n\tCitas en total: "<<contador<<"\n\n";
}

void asignarCitaSinNotf(listaC &cabeza,int idCita, int sintomas1,int anno,int mes,int dia, int hora,int minutos,int doc1, int pac1)
{
    nodoCita *nuevo;
    nuevo=crearNodo(idCita,sintomas1,anno,mes,dia,hora,minutos,doc1,pac1);
    

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    }
}

void asignarCita(listaC &cabeza,int idCita, int sintomas1,int anno,int mes,int dia, int hora,int minutos,int doc1, int pac1)
{
    nodoCita *nuevo;
    nuevo=crearNodo(idCita,sintomas1,anno,mes,dia,hora,minutos,doc1,pac1);
    

    if(cabeza==NULL)
    {
        cabeza=nuevo;
        cabeza->siguiente=cabeza;
        cabeza->anterior=cabeza;
        cout<<"\n\tCita asignada"<<endl;
    }

 
    else
    {
    nuevo->anterior=cabeza->anterior;
		nuevo->siguiente=cabeza;
		cabeza->anterior->siguiente=nuevo;
		cabeza->anterior=nuevo;
		cabeza=nuevo;
    	cout<<"\n\tCita asignada"<<endl;
    }
}

void eliminarCita(listaC &cabeza,int idCit)
{
        listaC aux;
 
        if (cabeza == NULL) {
            cout << "\n\tLista vacia" << endl;
        } else {
            aux = cabeza;
            do {
                if (aux -> idCita == idCit && aux == cabeza) {
                    cabeza = aux -> siguiente;
                    aux -> siguiente -> anterior = aux -> anterior;
                    aux -> anterior -> siguiente = aux -> siguiente;
                    aux -> anterior = NULL;
                    aux -> siguiente = NULL;
                    delete(aux);
                    cout << "\n\tCita " << idCit << " eliminada" << endl;
                    aux = cabeza;
                } else {
                    if (aux -> idCita == idCit && aux != cabeza) {
                        aux -> anterior -> siguiente = aux -> siguiente;
                        aux -> siguiente -> anterior = aux -> anterior;
                        aux -> siguiente = NULL;
                        aux -> anterior = NULL;
                        delete(aux);
                        cout << "\n\tCita " << idCit << " eliminada" << endl;
                        aux = cabeza;
                    }
 
                }
                aux = aux -> siguiente;
            } while (aux != cabeza);
        }
}

void modificarCita(listaC &cabeza,int idCit)
{	
	int opcion,annoN,mesN,diaN,horaN,minutosN;
	listaC aux;
	
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
        	if(aux->idCita==idCit && aux==cabeza)
			{
		    cout<<"\tAño actual: "<<aux->anno<<endl;
            cout<<"\tMes actual: "<<aux->mes<<endl;
            cout<<"\tDia actual: "<<aux->dia<<endl;
            cout<<"\tHora actual: "<<aux->hora<<endl;
            cout<<"\tMinutos actuales: "<<aux->minutos<<endl;
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"\tNuevo año: "<<endl;
            cin>>annoN;         
            cout<<"\tNuevo mes: "<<endl;
            cin>>mesN;
            cout<<"\tNuevo dia: "<<endl;
            cin>>diaN;
            cout<<"\tNueva hora: "<<endl;
            cin>>horaN;
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
             
            cout<<"\n\tDesea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
            cin>>opcion;
             
            if(opcion==1)  {
				   		
			aux->anno=annoN;
            aux->mes=mesN;
            aux->dia=diaN;
            aux->hora=horaN;
            
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"\tNuevo año modificado: "<<annoN<<endl;
            cout<<"\tNuevo mes modificado: "<<mesN<<endl;
            cout<<"\tNuevo día modificado: "<<diaN<<endl;
            cout<<"\tNueva hora modificada: "<<horaN<<endl;
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
				if(aux->idCita==idCit && aux!=cabeza)
				{
		 cout<<"\tAño actual: "<<aux->anno<<endl;
            cout<<"\tMes actual: "<<aux->mes<<endl;
            cout<<"\tDia actual: "<<aux->dia<<endl;
            cout<<"\tHora actual: "<<aux->hora<<endl;
            cout<<"\tMinutos actuales: "<<aux->minutos<<endl;
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"\tNuevo año: "<<endl;
            cin>>annoN;         
            cout<<"\tNuevo mes: "<<endl;
            cin>>mesN;
            cout<<"\tNuevo dia: "<<endl;
            cin>>diaN;
            cout<<"\tNueva hora: "<<endl;
            cin>>horaN;
            cout<<"------------------------"<<endl;
            cout<<" "<<endl;
             
            cout<<"\n\tDesea guardar los cambios?\n 1)SI \n 2)NO"<<endl;
            cin>>opcion;
             
            if(opcion==1)  {
				   		
			aux->anno=annoN;
            aux->mes=mesN;
            aux->dia=diaN;
            aux->hora=horaN;
            
            
            cout<<" "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"\tNuevo año modificado: "<<annoN<<endl;
            cout<<"\tNuevo mes modificado: "<<mesN<<endl;
            cout<<"\tNuevo día modificado: "<<diaN<<endl;
            cout<<"\tNueva hora modificada: "<<horaN<<endl;
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

int buscarEspecialidad(listaD cabeza, int var1)
{

	listaP auxP;
	listaD auxD;
	int especialidadReturn;
   
   	int derm=1;
   	int dent=2;
   	int cir=3;
   	int psico=4;
   
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        auxD=cabeza;
        do
        {
        	auxD=auxD->siguiente;
			if("Dermatologo"==auxD->especialidad && derm==var1){
			
			cout<<"\n\tID de doctor: "<<auxD->codigoD<<"\n";
			cout<<"\tNombre: "<<auxD->nombre<<"\n";
			cout<<"\tEspecialidad: "<<auxD->especialidad<<"\n\n";

			//cout<<"\treturn "<<especialidadReturn;
			especialidadReturn=1;
			
			} else if ("Dentista"==auxD->especialidad && dent==var1){
				
			cout<<"\n\tID de doctor: "<<auxD->codigoD<<"\n\n";
			cout<<"\tNombre: "<<auxD->nombre<<"\n";
			cout<<"\tEspecialidad: "<<auxD->especialidad<<"\n\n";
			especialidadReturn=2;
			//cout<<"return "<<especialidadReturn;
				
			}else if ("Cirujano"==auxD->especialidad && cir==var1){
				
			cout<<"\n\tID de doctor: "<<auxD->codigoD<<"\n";
			cout<<"\tNombre: "<<auxD->nombre<<"\n";
			cout<<"\tEspecialidad: "<<auxD->especialidad<<"\n\n";
			//cout<<"return "<<especialidadReturn;
			especialidadReturn=3;

				
			}else if ("Psicologo"==auxD->especialidad && psico==var1){
				
			cout<<"\n\tID de doctor: "<<auxD->codigoD<<"\n";
			cout<<"\tNombre: "<<auxD->nombre<<"\n";
			cout<<"\tEspecialidad: "<<auxD->especialidad<<"\n\n";
			//cout<<"\treturn "<<especialidadReturn;
			especialidadReturn=4;
				
			}
					
        } 
        while (auxD!=cabeza);
        return especialidadReturn;
    }
}

void mostrarCitasMes (listaC cabeza,int ms)
{
    listaC aux;
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
if(aux->mes==ms)
{
        	cout<<"\t\n------------------------"<<endl;
            cout<<"\tID de la Cita: "<<aux->idCita<<endl;
            cout<<"\tSintomas del paciente: "<<aux->sintomas1<<endl;
            cout<<"\tAño: "<<aux->anno<<endl;
            cout<<"\tMes: "<<aux->mes<<endl;
            cout<<"\tDia: "<<aux->dia<<endl;
            cout<<"\tHora: "<<aux->hora<<endl;
            cout<<"\tMinutos: "<<aux->minutos<<endl;
            cout<<"\tDoctor: "<<aux->doc1<<endl;
            cout<<"\tPaciente: "<<aux->pac1<<endl;
            cout<<"\t------------------------\n\n"<<endl;
           
}
aux=aux->siguiente;
        } 
        while (aux!=cabeza);
        
    }
}

//Cantidad atendida de pacientes segun dia y mes
void contarPacientesDiaMes(listaC cabeza,int ms,int di)
{
  listaC aux;
int contador=0;
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
if(ms==aux->mes && di==aux->dia)
{
        	contador=contador+1;
           
}
aux=aux->siguiente;
        } 
        while (aux!=cabeza);
        
    }
cout<<"Cantidad de citas: "<<contador<<endl;
}

void contarDoctoresEspecialidad(listaD cabeza,string espec)
//le pide input en el main. Le da las 4 opciones de especialidades
{
  listaD aux;
int contador=0;
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
if(espec==aux->especialidad)
{
        	contador=contador+1;
           
}
aux=aux->siguiente;
        } 
        while (aux!=cabeza);
        
    }
cout<<"La cantidad de doctores es: "<<contador<<endl;
}

void contarPacientesEspecialidad(listaC cabeza){
	 listaC aux;
int contadorDermatologo=0;
int contadorDentista=0;
int contadorCirujano=0;
int contadorPsicologo=0;
    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
if(aux->sintomas1==1)
{
        	contadorDermatologo=contadorDermatologo+1;
           
} else if(aux->sintomas1==2){

contadorDentista=contadorDentista+1;
}else if(aux->sintomas1==3){
	contadorCirujano=contadorCirujano+1;
}else if(aux->sintomas1==4){

contadorPsicologo=contadorPsicologo+1;
}else{
	cout<<"Invalido"<<endl;
}
aux=aux->siguiente;
        } 
        while (aux!=cabeza);
        
    }
cout<<"Cantidad de pacientes atendidos por Dermatologos: "<<contadorDermatologo<<endl;
cout<<"Cantidad de pacientes atendidos por Dentistas: "<<contadorDentista<<endl;
cout<<"Cantidad de pacientes atendidos por Cirujanos: "<<contadorCirujano<<endl;
cout<<"Cantidad de pacientes atendidos por Psicologos: "<<contadorPsicologo<<endl;
}

/*
void CantidadPacientesDoctor(listaC cabeza)
{
	 listaC aux;
int contadorDermatologo=0;

    if (cabeza==NULL)
    cout<<"\n\tLista vacia"<<endl;
    else
    {
        aux=cabeza;
        do
        {
if(aux->sintomas1==1)
{
        	contadorDermatologo=contadorDermatologo+1;
           
} }else{
	cout<<"Invalido"<<endl;
}
aux=aux->siguiente;
        } 
        while (aux!=cabeza);
        
    }
cout<<"Cantidad de pacientes atendidos por Dermatologos: "<<contadorDermatologo<<endl;
cout<<"Cantidad de pacientes atendidos por Dentistas: "<<contadorDentista<<endl;
cout<<"Cantidad de pacientes atendidos por Cirujanos: "<<contadorCirujano<<endl;
cout<<"Cantidad de pacientes atendidos por Psicologos: "<<contadorPsicologo<<endl;
}
*/

void menuEstandar()
{
	string nombre,apellido1,apellido2,fechaIngreso,inputEspecialidad;
	int opcion,cedula,telefono,sintomas,inputpac,inputdia,inputmes,inputanno,inputhora,inputminutos,var1,inputdoc,idCita,mes,dia;
	
	lista List=NULL;
    listaP ListP=NULL;
    listaD ListD=NULL;
    listaC ListC=NULL;
    
    ingresarFinalUsuariosSinNotf(List,"Valeria","Soto","Corrales",703210563,'A',"Vales","Vale123!","inactivo");
    ingresarFinalUsuariosSinNotf(List,"Diego","Colorado","Murillo",708910891,'E',"diegoma","Diego123!","activo");
    ingresarFinalPacienteSinNotf(ListP,"Carolina","Chinchilla","Solis",702360763,87671212,1,"02/06/2022");
    ingresarFinalPacienteSinNotf(ListP,"Maria","Bonilla","Campos",701580214,61237812,2,"10/05/2022");
    ingresarFinalDoctorSinNoft(ListD,"Juan","Guadamuz","Fernandez","Dermatologo",1);
	ingresarFinalDoctorSinNoft(ListD,"Luis","Monge","Abarca","Dentista",2);
    ingresarFinalDoctorSinNoft(ListD,"Rodrigo","Guevara","Hidalgo","Cirujano",3);
    ingresarFinalDoctorSinNoft(ListD,"Jason","Ortega","Herrera","Cirujano",5);
    ingresarFinalDoctorSinNoft(ListD,"Jose","Quiros","Meneses","Psicologo",4);
    asignarCitaSinNotf(ListC,1,1,2020,12,10,20,30,1,1);
	
	do
    {
        
		cout<<"\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n\tMENU PRINCIPAL ESTANDAR\t";
		cout<<"\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		
        cout << "\t1: Ingresar un nuevo paciente" <<endl;
        cout << "\t2: Mostrar pacientes" <<endl;
        cout << "\t3: Modificar paciente" <<endl;
        cout << "\t4: Eliminar paciente\n\n" <<endl;
        
        cout << "\t5: Asignar una cita medica" <<endl;
        cout << "\t6: Modificar una cita medica" <<endl;
        cout << "\t7: Mostrar citas medicas" <<endl;
        cout << "\t8: Mostrar citas medicas del mes seleccionado" <<endl;
         cout << "\t9: Mostrar citas medicas del dia y mes seleccionado" <<endl;
        cout << "\t10: Eliminar cita medica"<<endl;
        cout << "\t11: Cantidad de pacientes por especialidad"<<endl;
        cout<<"\t12: Cantidad de doctores por especialidad"<<endl;
        
        cout << "\t13: Salir\n\n" <<endl;
        
        cout << "\tLa opcion que desea es: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1: 
                    cout << "\n\tDigite el nombre del paciente		: ";
                    cin >> nombre;
                    cout << "\tDigite el primer apellido del paciente		: ";
                    cin >> apellido1;
                    cout << "\tDigite el segundo apellido del paciente		: ";
                    cin >> apellido2;
                    cout << "\tDigite el DNI del paciente		: ";
                    cin >> cedula;
                    cout << "\tDigite el telefono  del paciente: ";
                    cin >> telefono;
                    cout <<"\n\t\t[1] Gangrena \n\t\t[2] Carie\n\t\t[3] Fractura\n\t\t[4] Depresion\n";
                    cout << "\n\tDigite el sintoma del paciente		: ";
                    cin >> sintomas;
                    cout << "\tDigite la fecha de ingreso  del paciente: ";
                    cin >> fechaIngreso;

                    
                    ingresarFinalPaciente(ListP,nombre,apellido1,apellido2,cedula,telefono,sintomas,fechaIngreso);
                            
            	break;
            case 2: 
                  mostrarPaciente(ListP);
                  cout << "\n\t"; system("Pause");
            	break;
            case 3: 
                     
                    cout<<"\tDigite el numero de cedula del paciente que desea modificar: ";
                    cin>>cedula;
                    modificarPaciente(ListP,cedula);
                    cout << "\n\t"; system("Pause");
            	break;
            case 4:
                    cout<<"\tDigite la cedula del paciente que desea eliminar  : ";
                    cin>>cedula;
					eliminarPaciente(ListP,cedula);
					
					cout << "\n\t"; system("Pause");
            	break;
            case 5:

                    mostrarPaciente(ListP);
                    cout << "\tDigite el cedula de paciente	: ";
                    cin >> inputpac;
					cout << "\n\tDigite el dia que desea su cita	: ";
                    cin >> inputdia;
                    cout << "\tDigite el mes que desea su cita	: ";
                    cin >> inputmes;
                    cout << "\tDigite el año que desea su cita	: ";
                    cin >> inputanno;
                    cout << "\tDigite la hora que desea su cita	: ";
                    cin >> inputhora;
                    cout << "\tDigite en que minuto desea su cita	: ";
                    cin >> inputminutos;
                    cout << "\n\t"; system("Pause");

                    var1 = buscarSintoma(ListP,inputpac);
                    buscarEspecialidad(ListD,var1);
                    cout << "\tDigite el id del doctor: ";
                    cin >> inputdoc;
                   
                    cout << "\n\t"; system("Pause");
                    
                    idCita=rand()%100;
                    
                    asignarCita(ListC,idCita,sintomas,inputanno,inputmes,inputdia,inputhora,inputminutos,inputdoc,inputpac);
                    cout << "\n\t"; system("Pause");
            	break;
            case 6:
                    cout<<"\tDigite el id de la cita que desea modificar"<<endl;
                    cin>>idCita;
					modificarCita(ListC,idCita);
            	break;
            case 7:
                	mostrarCitas(ListC);
					cout << "\n\t"; system("Pause");	
            	break;
            case 8:
			cout<<"\tDigite el mes que desea ver"<<endl;
			cin>>mes;
			mostrarCitasMes(ListC,mes);
			cout << "\n\t"; system("Pause");
            	break;
            	
            	case 9:
					cout<<"\tDigite el mes que desea ver"<<endl;
					cin>>mes;
					cout<<"\tDigite el dia que desea ver"<<endl;
					cin>>dia;
					contarPacientesDiaMes(ListC,mes,dia);
						cout << "\n\t"; system("Pause");
            	break;
            case 10:
					cout<<"\n\tDigite el id de la cita que desea eliminar"<<endl;
				cin>>idCita;
                eliminarCita(ListC,idCita);
                cout << "\n\t"; system("Pause");
				
				break;
				
			case 11:
				contarPacientesEspecialidad(ListC);
				cout << "\n\t"; system("Pause");
				break;
            case 12:
            	cout <<"\n\t\t[1] Gangrena \n\t\t[2] Carie\n\t\t[3] Fractura\n\t\t[4] Depresion\n";
				cout<<"\n\tDigite la especialidad que desea ver		:";
				cin>>inputEspecialidad;
				contarDoctoresEspecialidad(ListD,inputEspecialidad);
				cout << "\n\t"; system("Pause");
				break;
        }
    }
    while(opcion!=13);
    
   cout<<"Fin del sistema"<<endl;
}

void menuAdmin()
{

string nombre, apellido1,apellido2,cuenta,contrasenna,activacion,especialidad,fechaIngreso;
int codigo,codigoUsuario,codigoD,cedula,telefono,sintomas,c = 0;
char tipo;

 	lista List=NULL;
    listaP ListP=NULL;
    listaD ListD=NULL;
    listaC ListC=NULL;
    
     ingresarFinalUsuariosSinNotf(List,"Valeria","Soto","Corrales",703210563,'A',"Vales","Vale123!","inactivo");
    ingresarFinalUsuariosSinNotf(List,"Diego","Colorado","Murillo",708910891,'E',"diegoma","Diego123!","activo");
    ingresarFinalPacienteSinNotf(ListP,"Carolina","Chinchilla","Solis",702360763,87671212,1,"02/06/2022");
    ingresarFinalPacienteSinNotf(ListP,"Maria","Bonilla","Campos",701580214,61237812,2,"10/05/2022");
    ingresarFinalDoctorSinNoft(ListD,"Juan","Guadamuz","Fernandez","Dermatologo",1);
	ingresarFinalDoctorSinNoft(ListD,"Luis","Monge","Abarca","Dentista",2);
    ingresarFinalDoctorSinNoft(ListD,"Rodrigo","Guevara","Hidalgo","Cirujano",3);
     ingresarFinalDoctorSinNoft(ListD,"Jason","Ortega","Herrera","Cirujano",5);
    ingresarFinalDoctorSinNoft(ListD,"Jose","Quiros","Meneses","Psicologo",4);
    asignarCitaSinNotf(ListC,1,1,2020,12,10,20,30,1,1);
{
	int opcion;
	 do
    {
        
		cout<<"\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n\tMENÚ PRINCIPAL ADMINISTRADOR\t";
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
        cout << "\tLa opción que desea es: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1: 
                    cout << "\n\tDigite el nombre				: ";
                    cin >> nombre;
                    cout << "\tDigite el primer apellido			: ";
                    cin >> apellido1;
                    cout << "\tDigite el segundo apellido			: ";
                    cin >> apellido2;
                    cout << "\tDigite la cédula de usuario			: ";
                    cin >> codigo;
                    cout << "\tDigite el tipo de usuario (A/E)			: ";
                    cin >> tipo;
                    cout << "\tDigite el nombre de la cuenta del usuario	: ";
                    cin >> cuenta;
                    cout << "\n\tLa contraseña debe de contener números, carácteres, letras mayúsculas y minúsculas (8)"<<endl;
					cout << "\n\tDigite la contrasenna				: ";
                    do{
                    cin >> contrasenna;
                    printStrongNess(contrasenna,c);
                    }while(c!=1);
                    
                    cout << "\tDigite el estado de la cuenta (activa/inactiva) : ";
                    cin >> activacion;        
                    ingresarFinalUsuarios(List,nombre,apellido1,apellido2,codigo,tipo,cuenta,contrasenna,activacion); 
                    cout << "\n\t"; system("Pause");
            break;
            case 2: 
            
                  mostrar(List);
                  cout << "\n\t"; system("Pause");
                  
            break;
            case 3: 
            
            cout<<"\n\tDigite la cédula del usuario que desea activar o desactivar: ";
       		cin>>codigoUsuario;
       		modificarEstado(List,codigoUsuario);
       		cout << "\n\t"; system("Pause");
                    //desactivar(List,codigoUsuario);
            break;
            case 4:
                    cout << "\n\tDigite el nombre del doctor			: ";
                    cin >> nombre;
                    cout << "\tDigite el primer apellido del doctor		: ";
                    cin >> apellido1;
                    cout << "\tDigite el segundo apellido del doctor		: ";
                    cin >> apellido2;
                    cout <<"\n\t\t[1] Gangrena \n\t\t[2] Carie\n\t\t[3] Fractura\n\t\t[4] Depresión\n";
                    cout << "\n\tDigite la especialidad del doctor		: ";
                    cin >> especialidad;
                    codigoD = rand()%500;
                    
                    ingresarFinalDoctor(ListD,nombre,apellido1,apellido2,especialidad,codigoD);
                    
                    cout << "\n\t"; system("Pause");
            		break;
            case 5:
            	
                    cout<<"\n\tDigite el código del doctor que desea eliminar	: ";
                    cin>>codigoD;
				    eliminarDoctor(ListD,codigoD);
				    //	mostrarDoctor(ListD);
				    cout << "\n\t"; system("Pause");
            		break;
            case 6:
                     cout<<"\n\tDigite el código del doctor que desea modificar	: ";
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
                    cout << "\n\tDigite el nombre del paciente			: ";
                    cin >> nombre;
                    cout << "\tDigite el primer apellido del paciente		: ";
                    cin >> apellido1;
                    cout << "\tDigite el segundo apellido del paciente		: ";
                    cin >> apellido2;
                    cout << "\tDigite el número de cédula del paciente		: ";
                    cin>>cedula;
                    cout << "\tDigite el número de teléfono del paciente	: ";
                    cin >> telefono;
                    cout <<"\n\t\t[1] Gangrena \n\t\t[2] Carie\n\t\t[3] Fractura\n\t\t[4] Depresión\n";
					cout << "\n\tDigite los síntomas del paciente		: ";	
					cin>>sintomas;
					cout << "\tDigite la fecha de ingreso (DD/MM/YYYY)		: ";
					cin>>fechaIngreso;			
					ingresarFinalPaciente(ListP,nombre,apellido1,apellido2,cedula,telefono,sintomas,fechaIngreso);
					 cout << "\n\t"; system("Pause");
            break;
             case 9:
                     mostrarPaciente(ListP);
                      cout << "\n\t"; system("Pause");
            break;
            case 10:
                      cout<<"Digite la cédula del paciente que desea eliminar"<<endl;
                    cin>>cedula;
					eliminarPaciente(ListP,cedula);
					mostrarPaciente(ListP);
					 cout << "\n\t"; system("Pause");
            break;
            case 11:
                      cout<<"Digite el número de cédula del paciente que desea modificar"<<endl;
                    cin>>cedula;
                    modificarPaciente(ListP,cedula);
                    cout << "\n\t"; system("Pause");
					
            break;
        }
    }
    while(opcion!=12);
    menuEstandar();
    cout << "Fin del sistema" <<endl;
}
}



	
    int main(){
    	
	setlocale(LC_ALL, "spanish");
    /*	
	int sintomas1,mes,anno,dia,hora,minutos,doc,pac,idCita;
	int inputsintomas1,inputmes,inputanno,inputdia,inputhora,inputminutos,inputdoc,inputpac,inputidCita,inputCedula;
	int sintomas, especialidadPara;
		
    int opcion = 0,edad = 0,codigo = 0,codigoUsuario = 0;
    string nombre,apellido1,apellido2,cuenta,contrasenna;
    string fechaIngreso,inputEspecialidad;
    string especialidad;
    int cedula = 0,telefono = 0;
    int codigoD = 0;
    int var1;
    char tipo;
    string estado;
    string activacion;
    */
    //lista List=NULL;
    //listaP ListP=NULL;
    //listaD ListD=NULL;
    //listaC ListC=NULL;
   int opcion;
    
    //ingresarFinalUsuariosSinNotf(List,"Valeria","Soto","Corrales",703210563,'A',"Vales","Vale123!","inactivo");
    //ingresarFinalUsuariosSinNotf(List,"Diego","Colorado","Murillo",708910891,'E',"diegoma","Diego123!","activo");
    //ingresarFinalPacienteSinNotf(ListP,"Carolina","Chinchilla","Solis",702360763,87671212,1,"02/06/2022");
    //ingresarFinalPacienteSinNotf(ListP,"Maria","Bonilla","Campos",701580214,61237812,2,"10/05/2022");
    //ingresarFinalDoctorSinNoft(ListD,"Juan","Guadamuz","Fernandez","Dermatologo",1);
	//ingresarFinalDoctorSinNoft(ListD,"Luis","Monge","Abarca","Dentista",2);
    //ingresarFinalDoctorSinNoft(ListD,"Rodrigo","Guevara","Hidalgo","Cirujano",3);
    //ingresarFinalDoctorSinNoft(ListD,"Jason","Ortega","Herrera","Cirujano",5);
    //ingresarFinalDoctorSinNoft(ListD,"Jose","Quiros","Meneses","Psicologo",4);
    //asignarCitaSinNotf(ListC,1,1,2020,12,10,20,30,1,1);

    
  	cout<<"\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n\tLogin\t";
		cout<<"\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
		
        cout << "\t1: Ingresar como Administrador" <<endl;
        cout << "\t2: Ingresar como usuario Estandar" <<endl;
        
    
        cout << "\tLa opcion que desea es: ";
        
        do
    {
        cin >> opcion;
        switch (opcion)
        {
			case 1:
				menuAdmin();
				break;
			
			case 2:
				menuEstandar();	
				break;
			}
		}
		while(opcion!=3);
	cout << "Fin del sistema" <<endl;	
	
  
    
	//string input = " aB4$cfgty";
    //printStrongNess(input);
    //return 0;

    


   
    }
