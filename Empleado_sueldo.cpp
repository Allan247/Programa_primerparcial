#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";

struct empleado{
	int codigo;
	char nombre[50];
	char apellido[50];
	int sueldo;
};
 void ingresar_empleado();
void abrir_empleado();
 void modificar_empleado();
 void eliminar_empleado();
int main (){
	abrir_empleado();
 ingresar_empleado();
	modificar_empleado();
   eliminar_empleado();
	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	empleado empleado;
	
	fread ( &empleado, sizeof(empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(empleado), SEEK_SET );

    fread ( &empleado, sizeof( empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "sueldo: " << empleado.sueldo << endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(empleado), SEEK_SET );
	
	empleado empleado;
	
    fread ( &empleado, sizeof( empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "sueldo: " << empleado.sueldo << endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_empleado(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(empleado), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<"|"<<"APELLIDO"<<"|"<<"sueldo"<<" "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< empleado.codigo <<" | "<< empleado.nombre<<"|"<<empleado.apellido<<"|"<<empleado.sueldo<<endl;
        
        
		fread ( &empleado, sizeof(empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_empleado(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		empleado empleado;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el sueldo:";
		cin>>empleado.sueldo;
		cin.ignore();
		
		fwrite( &empleado, sizeof(empleado), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_empleado();
	//buscar_indice();	
	buscar_codigo();
}
void modificar_empleado(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	empleado empleado;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    	
    		fseek ( archivo, id * sizeof(empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el sueldo:";
		cin>>empleado.sueldo;
		cin.ignore();
		
		fwrite( &empleado, sizeof(empleado), 1, archivo );
		
	fclose(archivo);
	abrir_empleado();
		system("PAUSE");
}
void eliminar_empleado(){
	
	FILE* archivo = fopen(nombe_archivo, "remove()");
	
		int id;
		string nombre,apellido;	
    	empleado empleado;
    
		cout << "Ingrese el ID que desea Eliminar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(empleado), SEEK_SET );  
    		
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
	
		fwrite( &empleado, sizeof(empleado), -1, archivo );
		
	fclose(archivo);
	abrir_empleado();
		system("PAUSE");
}

